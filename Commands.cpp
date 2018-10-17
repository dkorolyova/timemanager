

#include "Commands.h"
#include "ConfigConst.h"
#include "iostream"
#include "string"
#include "StateModel.h"
#include <map>

using namespace std;



Commands::Commands() {
}

Commands::Commands(const Commands& orig) {
}

void Commands::checkCommand() {
    string command;
    
    while (true) {
        cout << "Enter the action ";      
        cout << stateModel.getAvailable(stateModel.getState()) << " ";
        cin >> command;
        if (stateModel.checkTheState(command)) {
            stateModel.setState(command);
        }
    }
}

Commands::~Commands() {
}