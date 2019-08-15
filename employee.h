#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <vector>
#include "name.h"
#include "phone.h"

using namespace std;

enum employment_status
{
    Employed,
    OnHold,
    Left
};

class Employee
{
private:
    int ID;
    int salary;
    Name name;
    time_t DoB;
    string title;
    string department;
    employment_status employmentStatus;
    string email;
    vector<string> attachedEmail;
    string userName;
    string officeBased;
    Phone phoneDetail;

public:
    Employee();
    ~Employee();
    string getFullName();
    string getName();
    void setName(string fName, string mName, string lName);
    int getID();
    void setID(int id);
};

#endif