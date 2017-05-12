#include <cpuupdater.h>

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

#include <fstream>

#include <sstream>
#include <string>


using namespace std;

void CpuUpdater::process(){
    map<string, string> map;

    while (true) {
        sleep(1);

        double correctValue;
        std::string::size_type sz;

//        cout << sizeof(sensorFiles) << endl;

        for ( int i = 0; i < 36; i++) {
            ifstream infile(sensorFiles[i]);

            string line;
            while (std::getline(infile, line))
            {
                std::istringstream iss(line);
                correctValue = std::stod (line,&sz);
            }

            string varAsString = to_string(correctValue);

            map[sensorFiles[i]] = varAsString.c_str();

//            map.insert(make_pair(sensorFiles[i], varAsString.c_str()));

//            cout << "inserting: " << sensorFiles[i] << " and: " << varAsString.c_str();
//            map["ada"] = 123;
        }

        emit cpuChanged(map);
    }
}
