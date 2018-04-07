#include <cpufrqupdater.h>

#include <unistd.h>
#include <map>

#include <fstream>
#include <string>

using namespace std;

int cpuFreqSleepFor = 1;

void CpuFrqUpdater::process(){
    map<string, string> map;

    while (true) {
        sleep(cpuFreqSleepFor);

        for ( int i = 0; i <= 11; i++) {
            string filedir = "/sys/devices/system/cpu/cpufreq/policy" + std::to_string(i)+ "/scaling_cur_freq";

            ifstream cpuCurFreqFile(filedir);

            string line;
            while (getline(cpuCurFreqFile, line))
            {
                map[filedir] = line;
            }

            cpuCurFreqFile.close();

            filedir = "/sys/devices/system/cpu/cpufreq/policy" + std::to_string(i)+ "/scaling_min_freq";

            ifstream cpuMinFreqFile(filedir);

            while (getline(cpuMinFreqFile, line))
            {
                map[filedir] = line;
            }

            cpuMinFreqFile.close();

            filedir = "/sys/devices/system/cpu/cpufreq/policy" + std::to_string(i)+ "/scaling_max_freq";

            ifstream cpuMaxFreqFile(filedir);

            while (getline(cpuMaxFreqFile, line))
            {
                map[filedir] = line;
            }

            cpuMaxFreqFile.close();
        }

        emit cpuFrqChanged(map);
        map.clear();
    }
}

int CpuFrqUpdater::updateCheckFrequency(int newSleepValue) {
    cpuFreqSleepFor = newSleepValue;
}
