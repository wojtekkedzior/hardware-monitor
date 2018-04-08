#ifndef CPUFRQUPDATER_H
    static const char*  cpu0curFreq = "cpu0currentFrequency";
    static const char*  cpu1curFreq = "cpu1currentFrequency";
    static const char*  cpu2curFreq = "cpu2currentFrequency";
    static const char*  cpu3curFreq = "cpu3currentFrequency";
    static const char*  cpu4curFreq = "cpu4currentFrequency";
    static const char*  cpu5curFreq = "cpu5currentFrequency";
    static const char*  cpu6curFreq = "cpu6currentFrequency";
    static const char*  cpu7curFreq = "cpu7currentFrequency";
    static const char*  cpu8curFreq = "cpu8currentFrequency";
    static const char*  cpu9curFreq = "cpu9currentFrequency";
    static const char*  cpu10curFreq = "cpu10currentFrequency";
    static const char*  cpu11curFreq = "cpu11currentFrequency";

    static const char*  cpu0minFreq = "cpu0minFrequency";
    static const char*  cpu1minFreq = "cpu1minFrequency";
    static const char*  cpu2minFreq = "cpu2minFrequency";
    static const char*  cpu3minFreq = "cpu3minFrequency";
    static const char*  cpu4minFreq = "cpu4minFrequency";
    static const char*  cpu5minFreq = "cpu5minFrequency";
    static const char*  cpu6minFreq = "cpu6minFrequency";
    static const char*  cpu7minFreq = "cpu7minFrequency";
    static const char*  cpu8minFreq = "cpu8minFrequency";
    static const char*  cpu9minFreq = "cpu9minFrequency";
    static const char*  cpu10minFreq = "cpu10minFrequency";
    static const char*  cpu11minFreq = "cpu11minFrequency";

    static const char*  cpu0maxFreq = "cpu0maxFrequency";
    static const char*  cpu1maxFreq = "cpu1maxFrequency";
    static const char*  cpu2maxFreq = "cpu2maxFrequency";
    static const char*  cpu3maxFreq = "cpu3maxFrequency";
    static const char*  cpu4maxFreq = "cpu4maxFrequency";
    static const char*  cpu5maxFreq = "cpu5maxFrequency";
    static const char*  cpu6maxFreq = "cpu6maxFrequency";
    static const char*  cpu7maxFreq = "cpu7maxFrequency";
    static const char*  cpu8maxFreq = "cpu8maxFrequency";
    static const char*  cpu9maxFreq = "cpu9maxFrequency";
    static const char*  cpu10maxFreq = "cpu10maxFrequency";
    static const char*  cpu11maxFreq = "cpu11maxFrequency";
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

public slots:
    void process();


signals:
    void cpuFrqChanged(const std::map<std::string, std::string>&);

};



#endif // CPUFRQUPDATER_H
