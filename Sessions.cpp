

#include "Sessions.h"
#include <fstream>
#include <iostream>
#include "ConfigConst.h"

using namespace std;

Sessions::Sessions() {
    sessionRead();
}

Sessions::Sessions(const Sessions& orig) {
}

void Sessions::initSession () {
    sessionVector.emplace_back(INIT_COMMAND);
    writeToFile(INIT_COMMAND);
}

void Sessions::commitSession () {
    sessionVector.emplace_back(COMMIT_COMMAND);
    writeToFile(COMMIT_COMMAND);
}

void Sessions::writeToFile(string status) {
    fstream out(SESSIONS_FILE, std::fstream::in | std::fstream::out | std::fstream::app);
    out << status << "\n";
    out.close();
}

void Sessions::sessionRead() {
    string data;
    ifstream infile(SESSIONS_FILE);
    while (infile >> data) {
        sessionVector.emplace_back(data);
    }
}

bool Sessions::isSessionInit() {
    return sessionVector.empty() || sessionVector.back() == COMMIT_COMMAND;
}

vector<string> Sessions::getSessionVector () {
    return sessionVector;
} 

Sessions::~Sessions() {
    
}