#ifndef FANUPDATER_H
#define FANUPDATER_H

#include <QObject>
#include <QThread>

#include <malloc.h>

#include <map>
#include <string>


namespace Ui {
class FanUpdater;
}


class FanUpdater : public QObject
{
    Q_OBJECT

public :
//    FanUpdater();
//    ~FanUpdater();
//     map<char, char> fanMap;+


private :
    const char* sensorFiles[2] = {
          "/sys/class/hwmon/hwmon1/fan2_input",
          "/sys/class/hwmon/hwmon1/fan6_input"
//        "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq",
//        "/proc/cpuinfo"
    };

    //has something
    ///sys/class/hwmon/hwmon1/in0
    ///
    /// cpu:
    ///sys/devices/system/cpu


public slots:
    void process();


signals:
    void progressChanged(const std::map<std::string, std::string>&);

};



#endif // FANUPDATER_H
