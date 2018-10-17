

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
#include "Commands.h"
#include "StateModel.h"


using namespace std;

int main(int argc, char** argv) {
    Commands commands;
    vector<TimeStruct> timestamps;
    TimeLogger timeLogger(&timestamps);
    cout << "Time management program\n";
    while (true) {
        commands.checkCommand();
    }
    return 0;
}