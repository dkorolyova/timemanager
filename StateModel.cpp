

#include "StateModel.h"
#include "string"
#include "Sessions.h"
#include <algorithm>
#include "ConfigConst.h"
#include <fstream>
#include "TimeStruct.h"
#include "TimeCount.h"
#include "Commands.h"
#include "TimeLogger.h"




using namespace std;

StateModel::StateModel() {
    fillMap();
    state = readStateFromFile();
    timeLogger.setTimeData(&timestamps);
}

StateModel::StateModel(const StateModel& orig) {
}

string StateModel::getState() {
    return state;
}

void StateModel::setState(string stateValue) {
    TimeCount timeCount;
    state = stateValue;
    writeStateToFile(state);
    if (state == START_COMMAND) {
        timeData = new TimeStruct();
        timeData->startTime = time(NULL);
    }
    if (state == STOP_COMMAND) {
        timeData->stopTime = time(NULL);
        timestamps.push_back(*timeData);
        timeCount.sumOfTime(&timestamps);
        timeLogger.writeToLog();
    }
}

bool StateModel::checkTheState(string command) {
    return find(mapOfStates[state].begin(), mapOfStates[state].end(), command) != mapOfStates[state].end();
}

void StateModel::writeStateToFile(string status) {
    fstream out(STATE_FILE, std::fstream::in | std::fstream::out | std::fstream::app);
    out << status << "\n";
    out.close();
}

string StateModel::readStateFromFile() {
    Sessions sessions;
    string data;
    ifstream infile(STATE_FILE);
    while (infile >> data) {
        sessions.getSessionVector().emplace_back(data);
    }
    if (sessions.getSessionVector().empty()) {
        return "entry";
    }
    return sessions.getSessionVector().back();
}

void StateModel::fillMap() {
    mapOfStates["init"] = {"start", "commit"};
    mapOfStates["start"] = {"stop"};
    mapOfStates["stop"] = {"start", "commit"};
    mapOfStates["commit"] = {"init"};
    mapOfStates["entry"] = {"init"};
}

string StateModel::getAvailable(string state) {
    string result = "(";
    for (int i = 0; i < mapOfStates.at(state).size(); i++) {
        if (i != 0) {
            result += " "; 
        }
        result += mapOfStates.at(state)[i];
    }
    return result + ")";
} 

StateModel::~StateModel() {
}