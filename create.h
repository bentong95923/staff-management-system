#ifndef CREATE_H_
#define CREATE_H_

#include <iostream>
#include <vector>
#include <string>
#include "conf.h"

using namespace std;

class Create
{
private:
    vector<string> userInput;
public:
    Create();
    ~Create();
    void view();
    void askUserInput();
    void execute();
    vector<string> getUserInput();
    void setUserInput(vector<string> i);
};

#endif