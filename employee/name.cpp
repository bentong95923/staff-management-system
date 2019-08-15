#include "name.h"

Name::Name() {
}

string Name::getFullName()
{
    return firstName + " " + middleName + " " + lastName;
}

string Name::getName()
{
    return firstName + " " + lastName;
}

void Name::setName(string fName, string mName, string lName)
{
    this->firstName = fName;
    this->middleName = mName;
    this->lastName = lName;
}

Name::~Name() {
}