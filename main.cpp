/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mi
 *
 * Created on September 30, 2018, 11:17 AM
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#include <utility>
#include "TimeCount.h" 
#include <string>
#include "TimeStruct.h" 


using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    TimeCount timeCount;
    vector<TimeStruct> timestamps;
    string command;
    int timeSum = 0;
    cout << "Time management program\n";
    while (true) {
        TimeStruct timePair;

        cin >> command;
        if (command == "start") {
            timePair.startTime = time(NULL);
        }
        if (command == "stop") {
            timePair.endTime = time(NULL);

            timestamps.push_back(timePair);

            cout << timeCount.SumOfTime(timestamps) << endl;
            cout << timeCount.HumanReadable() << endl;

        }
    }
    return 0;
}