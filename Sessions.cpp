

#include "Sessions.h"
#include <fstream>
#include <iostream>
#include "ConfigConst.h"

using namespace std;

Sessions::Sessions() {
    //sessionRead();
}

Sessions::Sessions(const Sessions& orig) {
}

vector<string> Sessions::getSessionVector () {
    return sessionVector;
} 

Sessions::~Sessions() {
    
}