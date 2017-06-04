#ifndef CPUFRQUPDATER_H
#define CPUFRQUPDATER_H

#include <QObject>
#include <QThread>

#include <malloc.h>

#include <map>
#include <string>


namespace Ui {
class CpuFrqUpdater;
}


class CpuFrqUpdater : public QObject
{
    Q_OBJECT

public :
     int updateCheckFrequency(int);

    //system temp
    // /sys/class/thermal/thermal_zone0/temp
    //proper place to get all the cpu+package temps
    // /sys/class/hwmon/hwmon0/temp1_label


private :
    const char* sensorFiles[36] = {
        "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu7/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu8/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu9/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu10/cpufreq/cpuinfo_max_freq",

        "/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_cur_freq",
        "/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_min_freq",
        "/sys/devices/system/cpu/cpu11/cpufreq/cpuinfo_max_freq"
    };

public slots:
    void process();


signals:
    void cpuFrqChanged(const std::map<std::string, std::string>&);

};



#endif // CPUFRQUPDATER_H
