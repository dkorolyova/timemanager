/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeCount.cpp
 * Author: mi
 * 
 * Created on October 3, 2018, 7:25 PM
 */

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
//timeTotal
string TimeCount::HumanReadable() {
    double workHours = 0, workMins = 0;
    workMins = timeTotal / 60;
    workHours = workMins / 60;
    return "Time of work: " + to_string((int)workHours) + " hours " + to_string((int)workMins % 60)
            + " minutes " + to_string((int)timeTotal % 60) + " seconds.";
}

int TimeCount::SumOfTime(std::vector<TimeStruct> timestamps) {
    int timeSum = 0;
    for (TimeStruct timestamp : timestamps) {
        timeSum += timestamp.endTime - timestamp.startTime;
    }
    
    timeTotal = timeSum;
    return timeSum;
};

TimeCount::~TimeCount() {
}