

#ifndef COMMANDS_H
#define COMMANDS_H
#include <string>
#include "StateModel.h"

using namespace std;

class Commands {
public:
    Commands();
    Commands(const Commands& orig);
    virtual ~Commands();
    bool expectCommit();
    bool expectInit();
    bool expectStart();
    bool expectStop();
    bool expectCommand(string command, string message);
    void handleCommand();
    void fillMap();
    StateModel stateModel;
private:

};

#endif /* COMMANDS_H */

