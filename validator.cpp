#include "validator.h"

bool Validator::validate_email(string email) {
    
}

bool Validator::validate_landline(string landline){
    
}

bool Validator::validate_mobile(string mobile){
    
}

bool Validator::validate_number(string number){
    
}

bool Validator::validate_name(string name) {
    return regex_match(name, regex("([A-Za-z ]+)"));
}

bool Validator::validate_date(string date) {
    
}