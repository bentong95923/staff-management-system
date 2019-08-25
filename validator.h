#ifndef VALIDATOR_H_
#define VALIDATOR_H_

#include <regex>
#include <string>

using namespace std;

class Validator
{
public:
    static bool validate_words_only(string name);
    static bool validate_date(string date);
    static bool validate_landline(string landline);
    static bool validate_email(string email);
    static bool validate_mobile(string mobile);
    static bool validate_salary(string salary);
};

#endif