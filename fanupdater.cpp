#include <fanupdater.h>

#include <unistd.h>
#include <map>

#include <fstream>
#include <string>

using namespace std;

int sleepFor = 1;

void FanUpdater::process(){
    map<string, string> map;

    while (true) {
        sleep(sleepFor);

        for ( int i = 0; i < 2; i++) {
            ifstream infile(sensorFiles[i]);

            string line;
            while (getline(infile, line)) {
                  map[sensorFiles[i]] = line;
            }
        }

        emit progressChanged(map);
    }
}

int FanUpdater::updateCheckFrequency(int newValue) {
    sleepFor = newValue;
}
