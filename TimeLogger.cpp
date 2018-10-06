

#include "TimeLogger.h"
#include "TimeStruct.h"
#include "TimeCount.h"
#include <vector>
#include <fstream>


TimeLogger::TimeLogger() {
}

TimeLogger::TimeLogger(vector<TimeStruct> *data):timeData(data) {
}

bool TimeLogger::fexists(const char *filename) {
    ifstream ifile(filename);
    return ifile.good();
}

void TimeLogger::writeToLog() {
    const char* filename = "output.txt";
    bool addHeadLine = false;
    if (!fexists(filename)) {
        addHeadLine = true;
    }
    string headLine = "Start date;Stop date;Hours;Minutes;Seconds;Total time today\n";
    fstream out(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    if (addHeadLine) {
        out << headLine;
    }
    TimeCount timeSum;
    out << (timeData->back()).humanReadable() << timeSum.SumOfTime(timeData) << "\n";
    out.close();
}

TimeLogger::TimeLogger(const TimeLogger& orig) {
}

TimeLogger::~TimeLogger() {
}

