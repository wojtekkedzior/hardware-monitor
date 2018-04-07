#include <cputempupdater.h>

#include <unistd.h>
#include <map>
#include <iostream>

#include <fstream>
#include <string>

using namespace std;

int cpuTempSleepFor = 1;

void CpuTempUpdater::process(){
    map<string, string> map;

    while (true) {
        sleep(cpuTempSleepFor);

        for ( int i = 0; i < 21; i++) {
            ifstream infile(sensorFiles[i]);

            string line;
            while (getline(infile, line))
            {
                map[sensorFiles[i]] = line;
            }

            infile.close();
        }

        emit cpuTempChanged(map);
        map.clear();
    }
}

int CpuTempUpdater::updateCheckFrequency(int newValue) {
    cpuTempSleepFor = newValue;
}
