

#ifndef TIMESTRUCT_H
#define TIMESTRUCT_H
#include <string>
#include <time.h>


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
        tm* now = localtime(&timeSeconds);
        return to_string(now->tm_year + 1900) + "-" + to_string(now->tm_mon + 1) + "-" + to_string(now->tm_mday);
    }
    string getStartDate() {
        return getDate(startTime);
    }
    string getStopDate() {
        return getDate(stopTime);
    }
    string humanReadable() {
        return getStartDate() + ";" + getStopDate() + ";" + to_string(getHours()) + ";" + to_string(getMinutes() % 60)
                 + ";" + to_string(getSeconds() % 60) + ";" + to_string(getHours()) + "h " + to_string(getMinutes() % 60) + "m " + to_string(getSeconds() % 60) + "s ";
    }
    
};


#endif /* TIMESTRUCT_H */

