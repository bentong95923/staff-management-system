#include "employee.h"

Employee::Employee() {
    // Get ID from database
    //this->name = new Name();
}

string Employee::getFullName()
{
    return this->name.getFullName();
}

string Employee::getName()
{
    return this->name.getName();
}

void Employee::setName(string fName, string mName, string lName)
{
    this->name.setName(fName, mName, lName);
}

int Employee::getID() {
    return this->ID;
}

void Employee::setID(int id) {
    this->ID = id;
}

Employee::~Employee() {
}