#include "phone.h"

Phone::Phone() {
}

void Phone::setLandline(string landline)
{
    this->landline = landline;
}

void Phone::setMobile(vector<string> mob)
{
    for (const string &i : mob)
    {
        //this->mobile.insert()
    }
}

Phone::~Phone() {
}