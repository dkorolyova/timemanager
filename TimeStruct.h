

#ifndef TIMESTRUCT_H
#define TIMESTRUCT_H
#include <string>
#include <time.h>
#include <iomanip>
#include <sstream>



using namespace std;

struct TimeStruct {
    time_t startTime, stopTime;

    int getSeconds() {
        return stopTime - startTime;
    }

    int getHours() {
        return getMinutes() / 60;
    }

    int getMinutes() {
        return getSeconds() / 60;
    }
    
    string getDate(time_t timeSeconds) {
        auto tm = *localtime(&timeSeconds);
        ostringstream oss;
        oss << put_time(&tm, "%d-%m-%Y %H-%M-%S");
        auto str = oss.str();
        return str;
    }

    string getStartDate() {
        return getDate(startTime);
    }

    string getStopDate() {
        return getDate(stopTime);
    }

    string humanReadable() {
        return getStartDate() + ";" + getStopDate() + ";" + to_string(getHours()) + "h " + to_string(getMinutes() % 60) + "m " + to_string(getSeconds() % 60) + "s ";
    } 
};


#endif /* TIMESTRUCT_H */

