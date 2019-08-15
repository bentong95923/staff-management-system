#ifndef PHONE_H_
#define PHONE_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Phone
{
private:
    string landline;
    vector<string> mobile;
    string directLine;
    int DDI;

public:
    Phone();
    ~Phone();
    void setLandline(string landline);
    void setMobile(vector<string> mob);
};

#endif