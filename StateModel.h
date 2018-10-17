
#ifndef STATEMODEL_H
#define STATEMODEL_H
#include <string>
#include <map>
#include <vector>
#include "TimeStruct.h"
#include "TimeLogger.h"


using namespace std;

class StateModel {
public:
    StateModel();
    StateModel(const StateModel& orig);
    virtual ~StateModel();
    string getState();
    void setState(string stateValue);
    bool checkTheState(string command);
    void writeStateToFile(string status);
    string readStateFromFile();
    string getAvailable(string state);
    map <string, vector<string>> mapOfStates;
private:
    string state;
    vector<TimeStruct> timestamps;
    TimeLogger timeLogger;
    TimeStruct *timeData;
    void fillMap();
};

#endif /* STATEMODEL_H */

