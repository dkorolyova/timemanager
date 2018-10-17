

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
    bool fexists(const string filename);
    void setTimeData(vector<TimeStruct> *data);
private:
    vector<TimeStruct> *timeData;
};

#endif /* TIMELOGGER_H */

