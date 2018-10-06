

#include "Sessions.h"
#include <fstream>
#include <iostream>

using namespace std;

Sessions::Sessions() {
}

Sessions::Sessions(const Sessions& orig) {
}

void Sessions::writeToFile() {
    cout << "Enter status of work(init or commit): ";
    string status;
    cin >> status;
    const char* filename = "sessions.txt";
    fstream out(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    out << status;
    out.close();
}

Sessions::~Sessions() {
    
}