#ifndef FINDELEMENTVECTOR_H_
#define FINDELEMENTVECTOR_H_

#include <iostream>
// #include <any>
#include <vector>

using namespace std;

bool is_element_in_vector(vector<int> v, int e);
bool is_element_in_vector(vector<char> v, char e);
bool is_element_in_vector(vector<string> v, string e);
#endif