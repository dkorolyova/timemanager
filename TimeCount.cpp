

#include "TimeCount.h"
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "TimeStruct.h"

using namespace std;


TimeCount::TimeCount() {
}

TimeCount::TimeCount(const TimeCount& orig) {
}

int TimeCount::SumOfTime(vector<TimeStruct> *timestamps) {
    int timeSum = 0;
    for (TimeStruct timeStamp : *timestamps) {
        timeSum += timeStamp.getSeconds();
    }
    timeTotal = timeSum;
    return timeSum;
};

TimeCount::~TimeCount() {
}