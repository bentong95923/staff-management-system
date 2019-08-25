#include "validator.h"

bool Validator::validate_email(string email)
{
    return regex_match(email, regex("(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$)"));
}

bool Validator::validate_landline(string landline)
{
    return regex_match(landline, regex("(^[0]{1}[0-9]{8}$)"));
}

bool Validator::validate_mobile(string mobile)
{
    return regex_match(mobile, regex("(^[0]{1}[2]{1}[0-9]{7,9}$)"));
}

bool Validator::validate_salary(string salary)
{
    return regex_match(salary, regex("(^[0-9]+$)"));
}

bool Validator::validate_words_only(string name)
{
    return regex_match(name, regex("(^[A-Za-z ]+$)"));
}

bool Validator::validate_date(string date)
{
    return regex_match(date, regex("^((2000|2400|2800|(19|2[0-9](0[48]|[2468][048]|[13579][26])))-02-29)$|^(((19|2[0-9])[0-9]{2})-02-(0[1-9]|1[0-9]|2[0-8]))$|^(((19|2[0-9])[0-9]{2})-(0[13578]|10|12)-(0[1-9]|[12][0-9]|3[01]))$|^(((19|2[0-9])[0-9]{2})-(0[469]|11)-(0[1-9]|[12][0-9]|30))$"));
}
