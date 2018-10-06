

#ifndef TIMELOGGER_H
#define TIMELOGGER_H
#include <vector>
#include "TimeStruct.h"

using namespace std;

class TimeLogger {
public:
    TimeLogger();
    TimeLogger(vector<TimeStruct> *data);
    TimeLogger(const TimeLogger& orig);
    virtual ~TimeLogger();
    void writeToLog();
    bool fexists(const char *filename);
private:
    vector<TimeStruct> *timeData;
};

#endif /* TIMELOGGER_H */

