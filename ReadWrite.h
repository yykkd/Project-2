//
// Created by Yasmin on 11/29/2022.
//

#include "string"
#include "vector"
#include "regex"
#include "fstream"
using namespace std;

#ifndef AIRLINEROUTES_READWRITE_H
#define AIRLINEROUTES_READWRITE_H
vector<string> readFile();
vector<string> split(string s, regex r);
#endif //AIRLINEROUTES_READWRITE_H
