#include <cpufrqupdater.h>

#include <unistd.h>
#include <map>

#include <fstream>
#include <string>


using namespace std;

int sleepFor1 = 1;

void CpuFrqUpdater::process(){
    map<string, string> map;

    while (true) {
        sleep(sleepFor1);

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

int CpuFrqUpdater::updateCheckFrequency(int newValue) {
    sleepFor1 = newValue;
}
