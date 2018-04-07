#include <cpufrqupdater.h>

#include <unistd.h>
#include <map>

#include <fstream>
#include <string>

#include <iostream>


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

            infile.close();
        }

        emit cpuFrqChanged(map);
        map.clear();
    }
}

int CpuFrqUpdater::updateCheckFrequency(int newSleepValue) {
    cpuFreqSleepFor = newSleepValue;
}
