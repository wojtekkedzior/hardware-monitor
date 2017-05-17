#include <cputempupdater.h>

#include <unistd.h>
#include <map>

#include <fstream>
#include <string>

using namespace std;

void CpuTempUpdater::process(){
    map<string, string> map;

    while (true) {
        sleep(1);

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
