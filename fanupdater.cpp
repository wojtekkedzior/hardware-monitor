#include <fanupdater.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <cstdlib>

#include <memory>
//#include "rsensor.h"
//#include "nvidia.h"
#include <sys/stat.h>
#include "sensors/sensors.h"

#include <stdlib.h>
#include <unistd.h>

#include <fanupdater.h>
#include <map>


#define SENSORS_ERR_ACCESS_R	3 /* Can't read */
#define SENSORS_ERR_KERNEL	4 /* Kernel interface error */
#define SENSORS_ERR_IO		10 /* I/O error */


using namespace std;

static
int get_type_scaling(sensors_subfeature_type type)
{
    /* Multipliers for subfeatures */
    switch (type & 0xFF80) {
    case SENSORS_SUBFEATURE_IN_INPUT:
    case SENSORS_SUBFEATURE_TEMP_INPUT:
    case SENSORS_SUBFEATURE_CURR_INPUT:
    case SENSORS_SUBFEATURE_HUMIDITY_INPUT:
        return 1000;
    case SENSORS_SUBFEATURE_FAN_INPUT:
        return 1;
    case SENSORS_SUBFEATURE_POWER_AVERAGE:
    case SENSORS_SUBFEATURE_ENERGY_INPUT:
        return 1000000;
    }

    /* Multipliers for second class subfeatures
       that need their own multiplier */
    switch (type) {
    case SENSORS_SUBFEATURE_POWER_AVERAGE_INTERVAL:
    case SENSORS_SUBFEATURE_VID:
    case SENSORS_SUBFEATURE_TEMP_OFFSET:
        return 1000;
    default:
        return 1;
    }
}

void FanUpdater::process(){

    map<char, char> map;

    while (true) {
        sleep(1);

        double value;
        double correctValue;
        int TEMP_IDX_MAX = 3;
        FILE *f;

        for ( int i = 0; i < TEMP_IDX_MAX; ++i) {
            if ( ( f = fopen( sensorFiles[i], "r"))) {
                int res, err = 0;

                errno = 0;
                res = fscanf( f, "%lf", &value);
                if ( res == EOF && errno == EIO)
                    err = -SENSORS_ERR_IO;
                else if ( res != 1)
                    err = -SENSORS_ERR_ACCESS_R;
                res = fclose( f);
                if ( err)
                    // return err;
                    printf( "%lf\n", err);

                if ( res == EOF) {
                    if ( errno == EIO)
                        //return -SENSORS_ERR_IO;
                        printf( "%lf\n", -SENSORS_ERR_IO);
                    else
                        //return -SENSORS_ERR_ACCESS_R;
                        printf( "%lf\n", -SENSORS_ERR_ACCESS_R);
                }
                printf( "before: %lf\n", value);
                correctValue = value;
                value /= get_type_scaling( SENSORS_SUBFEATURE_TEMP_INPUT);

            } else
                //return -SENSORS_ERR_KERNEL;
                printf( "%lf\n", -SENSORS_ERR_KERNEL);

            printf( "%lf\n", value);
        }

        string varAsString = to_string(correctValue);
        QString str = QString::fromUtf8(varAsString.c_str());

        emit progressChanged(str);
    }
}
