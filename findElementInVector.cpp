#include "findElementInVector.h"

bool is_element_in_vector(vector<int> v, int e)
{
    for (auto x : v)
    {
        if (x == e)
        {
            return true;
        }
    }
    return false;
}

bool is_element_in_vector(vector<char> v, char e)
{
    for (auto x : v)
    {
        if (x == e)
        {
            return true;
        }
    }
    return false;
}

bool is_element_in_vector(vector<string> v, string e)
{
    for (auto x : v)
    {
        if (x == e)
        {
            return true;
        }
    }
    return false;
}