#ifndef VECTOREXT_H_
#define VECTOREXT_H_

#include <iostream>
#include <vector>

using namespace std;

class VectorExtension
{
public:
    static bool is_element_in_vector(vector<int> v, int e);
    static bool is_element_in_vector(vector<char> v, char e);
    static bool is_element_in_vector(vector<string> v, string e);

    static string vector_to_string(vector<int> v, string delimiter);
    static string vector_to_string(vector<char> v, string delimiter);
    static string vector_to_string(vector<string> v, string delimiter);
};

#endif