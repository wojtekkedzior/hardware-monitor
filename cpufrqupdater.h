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
        "/sys/devices/system/cpu/cpufreq/policy0/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy0/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy1/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy1/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy1/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy2/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy2/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy2/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy3/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy3/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy3/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy4/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy4/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy4/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy5/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy5/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy5/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy6/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy6/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy6/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy7/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy7/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy7/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy8/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy8/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy8/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy9/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy9/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy9/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy10/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy10/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy10/scaling_max_freq",

        "/sys/devices/system/cpu/cpufreq/policy11/scaling_cur_freq",
        "/sys/devices/system/cpu/cpufreq/policy11/scaling_min_freq",
        "/sys/devices/system/cpu/cpufreq/policy11/scaling_max_freq"
    };

public slots:
    void process();


signals:
    void cpuFrqChanged(const std::map<std::string, std::string>&);

};



#endif // CPUFRQUPDATER_H
