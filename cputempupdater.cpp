#include <cputempupdater.h>

#include <iostream>
#include <cstdlib>

#include <stdlib.h>
#include <unistd.h>

#include <map>

#include <fstream>

#include <sstream>
#include <string>


using namespace std;

void CpuTempUpdater::process(){
    map<string, string> map;

    while (true) {
        sleep(1);

        double correctValue;
        std::string::size_type sz;

//        cout << sizeof(sensorFiles) << endl;

        for ( int i = 0; i < 21; i++) {
            ifstream infile(sensorFiles[i]);

            string line;
            while (std::getline(infile, line))
            {
                istringstream iss(line);
                correctValue = std::stod (line,&sz);
            }

            string varAsString = to_string(correctValue);

            map[sensorFiles[i]] = varAsString.c_str();

//            map.insert(make_pair(sensorFiles[i], varAsString.c_str()));

//            cout << "inserting: " << sensorFiles[i] << " and: " << varAsString.c_str();
//            map["ada"] = 123;
        }

        emit cpuTempChanged(map);
    }
}
