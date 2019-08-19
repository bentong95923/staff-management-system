#include "trim.h"

string trim(string str, const string chars) {
    str.erase(str.find_last_not_of(chars) + 1);
    str.erase(0, str.find_first_not_of(chars));
    string out_str = "";
    bool pre_space = false;
    int i = 0;
    while(i < str.size()) {
        if (str.at(i) != ' ') {
            if (pre_space) {
                out_str+=' ';
            }
            out_str+=str.at(i);
            pre_space = false;
        } else {
            pre_space = true;
        }
        ++i;
    }
    return out_str;
}