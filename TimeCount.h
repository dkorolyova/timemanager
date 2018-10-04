/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeCount.h
 * Author: mi
 *
 * Created on October 3, 2018, 7:25 PM
 */

#ifndef TIMECOUNT_H
#define TIMECOUNT_H
#include <vector>
#include <time.h>
#include <cstdlib>
#include <string>
#include "TimeStruct.h"


using namespace std;

class TimeCount {
    int timeTotal;
public:
    TimeCount();
    TimeCount(const TimeCount& orig);
    virtual ~TimeCount();
    int SumOfTime(vector<TimeStruct> timestamps);
    string HumanReadable();
private:

};

#endif /* TIMECOUNT_H */

