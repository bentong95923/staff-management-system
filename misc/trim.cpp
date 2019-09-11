#include "trim.h"

string trim(string str, const string chars)
{
    if (str.size() == 0)
    {
        return str;
    }
    else
    {
        string tmp(str);
        tmp.erase(tmp.find_last_not_of(chars) + 1);
        tmp.erase(0, tmp.find_first_not_of(chars));

        string out_str;
        bool pre_space = false;
        int i = 0;
        while (i < tmp.size())
        {
            if (tmp.at(i) != ' ')
            {
                if (pre_space)
                {
                    out_str += ' ';
                }
                out_str += tmp.at(i);
                pre_space = false;
            }
            else
            {
                pre_space = true;
            }
            ++i;
        }
        return out_str;
    }
}