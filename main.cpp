

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



using namespace std;



int main(int argc, char** argv) {
    TimeCount timeCount;
    Sessions sessions;
    vector<TimeStruct> timestamps;
    TimeLogger timeLogger(&timestamps);
    string command;
    cout << "Time management program\n";
    while (true) {
        //sessions.writeToFile();
        TimeStruct timeData;
        cin >> command;
        if (command == "start") {
            timeData.startTime = time(NULL);
        }
        if (command == "stop") {
            timeData.stopTime = time(NULL);
          
            timestamps.push_back(timeData);
            timeCount.SumOfTime(&timestamps);
            timeLogger.writeToLog();
        }
        
    }
    return 0;
}