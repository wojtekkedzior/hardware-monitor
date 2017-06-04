#ifndef CPUTEMPUPDATER_H
#define CPUTEMPUPDATER_H

#include <QObject>
#include <QThread>

#include <malloc.h>

#include <map>
#include <string>


namespace Ui {
class CpuTempUpdater;
}


class CpuTempUpdater : public QObject
{
    Q_OBJECT

public :
    int updateCheckFrequency(int);

    //Alternative place to get system temp
    // /sys/class/thermal/thermal_zone0/temp

private :
    const char* sensorFiles[21] = {
        //Temp
        "/sys/class/hwmon/hwmon0/temp1_input", //Physical ID i.e. the Package
        "/sys/class/hwmon/hwmon0/temp2_input",
        "/sys/class/hwmon/hwmon0/temp3_input",
        "/sys/class/hwmon/hwmon0/temp4_input",
        "/sys/class/hwmon/hwmon0/temp5_input",
        "/sys/class/hwmon/hwmon0/temp6_input",
        "/sys/class/hwmon/hwmon0/temp7_input",

        //Max
        "/sys/class/hwmon/hwmon0/temp1_max",  //Physical ID i.e. the Package
        "/sys/class/hwmon/hwmon0/temp2_max",
        "/sys/class/hwmon/hwmon0/temp3_max",
        "/sys/class/hwmon/hwmon0/temp4_max",
        "/sys/class/hwmon/hwmon0/temp5_max",
        "/sys/class/hwmon/hwmon0/temp6_max",
        "/sys/class/hwmon/hwmon0/temp7_max",

        //Critical
        "/sys/class/hwmon/hwmon0/temp1_crit",  //Physical ID i.e. the Package
        "/sys/class/hwmon/hwmon0/temp2_crit",
        "/sys/class/hwmon/hwmon0/temp3_crit",
        "/sys/class/hwmon/hwmon0/temp4_crit",
        "/sys/class/hwmon/hwmon0/temp5_crit",
        "/sys/class/hwmon/hwmon0/temp6_crit",
        "/sys/class/hwmon/hwmon0/temp7_crit"
    };

public slots:
    void process();


signals:
    void cpuTempChanged(const std::map<std::string, std::string>&);

};



#endif // CPUTEMPUPDATER_H
