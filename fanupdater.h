#ifndef FANUPDATER_H
#define FANUPDATER_H

#include <QObject>
#include <QThread>

#include <malloc.h>


namespace Ui {
class FanUpdater;
}


class FanUpdater : public QObject
{

    Q_OBJECT

public :
//    FanUpdater();
//    ~FanUpdater();

private :
    const char* sensorFiles[36] = {
        "/sys/class/hwmon/hwmon1/fan2_input"
//        "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq",
//        "/proc/cpuinfo"
    };


public slots:
    void process(); //can be replaced by run()


signals:
    void progressChanged(const QString&);

};



#endif // FANUPDATER_H
