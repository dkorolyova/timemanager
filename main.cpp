

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#include <utility>
#include "TimeCount.h" 
#include <string>
#include "TimeStruct.h"
#include "TimeLogger.h"
#include "Sessions.h" 
#include <fstream>
#include "ConfigConst.h"


using namespace std;

int main(int argc, char** argv) {
    TimeCount timeCount;
    Sessions sessions;
    vector<TimeStruct> timestamps;
    TimeLogger timeLogger(&timestamps);
    string command;
    cout << "Time management program\n";
    while (true) {
        if (sessions.isSessionInit()) {
            if (cin >> command && command == INIT_COMMAND) {
                sessions.initSession();
            }
            continue;
        }
        cout << "Enter the action: ";
        TimeStruct timeData;
        cin >> command;
        if (command == START_COMMAND) {
            timeData.startTime = time(NULL);
        }
        if (command == STOP_COMMAND) {
            timeData.stopTime = time(NULL);

            timestamps.push_back(timeData);
            timeCount.SumOfTime(&timestamps);
            timeLogger.writeToLog();
        }
        if (command == COMMIT_COMMAND) {
            sessions.commitSession();
        }
    }
    return 0;
}