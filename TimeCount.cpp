

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

int TimeCount::sumOfTime(vector<TimeStruct> *timestamps) {
    sumSeconds = 0;
    for (TimeStruct timeStamp : *timestamps) {
        sumSeconds += timeStamp.getSeconds();
    }
    return sumSeconds;
};

string TimeCount::totalTime(vector<TimeStruct> *timestamps) {
    int sumSeconds = sumOfTime(timestamps);
    return to_string((sumSeconds / 60) / 60) + "h " + to_string((sumSeconds / 60) % 60) + "m " + to_string(sumSeconds % 60) + "s ";
}

TimeCount::~TimeCount() {
}