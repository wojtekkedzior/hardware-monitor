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

        for ( int i = 0; i < 36; i++) {
            ifstream infile(sensorFiles[i]);

            string line;
            while (getline(infile, line))
            {
                map[sensorFiles[i]] = line;
            }
        }

        emit cpuFrqChanged(map);
    }
}

int CpuFrqUpdater::updateCheckFrequency(int newSleepValue) {
    cpuFreqSleepFor = newSleepValue;
}
