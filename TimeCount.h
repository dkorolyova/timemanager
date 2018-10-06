

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
    int SumOfTime(vector<TimeStruct> *timestamps);
private:

};

#endif /* TIMECOUNT_H */