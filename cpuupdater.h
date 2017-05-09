#ifndef CPUUPDATER_H
#define CPUUPDATER_H

#include <QObject>
#include <QThread>

#include <malloc.h>

#include <map>
#include <string>


namespace Ui {
class CpuUpdater;
}


class CpuUpdater : public QObject
{
    Q_OBJECT

public :

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
    void cpuChanged(const std::map<std::string, std::string>&);

};



#endif // CPUUPDATER_H
