

#include "TimeLogger.h"
#include "TimeStruct.h"
#include "TimeCount.h"
#include <vector>
#include <fstream>
#include "ConfigConst.h"


TimeLogger::TimeLogger() {
}

TimeLogger::TimeLogger(vector<TimeStruct> *data):timeData(data) {
}

void TimeLogger::setTimeData(vector<TimeStruct> *data) {
    timeData = data;
}

bool TimeLogger::fexists(const string filename) {
    ifstream ifile(filename);
    return ifile.good();
}

void TimeLogger::writeToLog() {
    bool addHeadLine = false;
    if (!fexists(OUTPUT_FILE)) {
        addHeadLine = true;
    }
    string headLine = "Start date;Stop date;Period;Total time today\n";
    fstream out(OUTPUT_FILE, std::fstream::in | std::fstream::out | std::fstream::app);
    if (addHeadLine) {
        out << headLine;
    }
    TimeCount timeSum;
    out << (timeData->back()).humanReadable() << ";" << timeSum.totalTime(timeData) << "\n";
    out.close();
}

TimeLogger::TimeLogger(const TimeLogger& orig) {
}

TimeLogger::~TimeLogger() {
}