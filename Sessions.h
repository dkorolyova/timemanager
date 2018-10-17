

#ifndef SESSIONS_H
#define SESSIONS_H
#include <string>
#include <vector>

using namespace std;

class Sessions {
public:
    Sessions();
    Sessions(const Sessions& orig);
    virtual ~Sessions();
    void writeToFile(string status);
    void initSession();
    void commitSession();
    void sessionRead();
    bool isSessionCommit();
    bool isSessionInit();
    vector<string> getSessionVector();
    
private:
    vector<string> sessionVector;
};

#endif /* SESSIONS_H */