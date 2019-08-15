#ifndef NAME_H_
#define NAME_H_

#include <iostream>
#include <string>

using namespace std;

class Name
{
private:
    string firstName;
    string middleName;
    string lastName;
    string preferredName;
    string alternativeName;

public:
    Name();
    ~Name();
    string getFullName();
    string getName();
    void setName(string fName, string mName, string lName);
};

#endif