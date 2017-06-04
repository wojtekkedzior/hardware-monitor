#include <cputempupdater.h>

#include <unistd.h>
#include <map>

#include <fstream>
#include <string>

using namespace std;

int sleepFor2 = 1;

void CpuTempUpdater::process(){
    map<string, string> map;

    while (true) {
        sleep(sleepFor2);

        for ( int i = 0; i < 21; i++) {
            ifstream infile(sensorFiles[i]);

            string line;
            while (getline(infile, line))
            {
                map[sensorFiles[i]] = line;
            }
        }

        emit cpuTempChanged(map);
    }
}

int CpuTempUpdater::updateCheckFrequency(int newValue) {
    sleepFor2 = newValue;
}
