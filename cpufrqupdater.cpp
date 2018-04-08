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
            string line;

            ifstream cpuCurFreqFile("/sys/devices/system/cpu/cpufreq/policy" + std::to_string(i)+ "/scaling_cur_freq");
            while (getline(cpuCurFreqFile, line))
            {
                map["cpu" + std::to_string(i) + "currentFrequency"] = line;
            }
            cpuCurFreqFile.close();

            ifstream cpuMinFreqFile("/sys/devices/system/cpu/cpufreq/policy" + std::to_string(i)+ "/scaling_min_freq");
            while (getline(cpuMinFreqFile, line))
            {
                map["cpu" + std::to_string(i) + "minFrequency"] = line;
            }
            cpuMinFreqFile.close();


            ifstream cpuMaxFreqFile("/sys/devices/system/cpu/cpufreq/policy" + std::to_string(i)+ "/scaling_max_freq");
            while (getline(cpuMaxFreqFile, line))
            {
                map["cpu" + std::to_string(i) + "maxFrequency"] = line;
            }
            cpuMaxFreqFile.close();
        }

        emit cpuFrqChanged(map);
        map.clear();
    }
}



void readFile(string fileDir, map<string, string> map) {




}


int CpuFrqUpdater::updateCheckFrequency(int newSleepValue) {
    cpuFreqSleepFor = newSleepValue;
}
