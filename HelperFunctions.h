//
// Created by Yasmin on 11/27/2022.
//
#include "map"
#include "string"
#include "fstream"
#include "vector"


using namespace std;

#ifndef AIRLINEROUTES_HELPERFUNCTIONS_H
#define AIRLINEROUTES_HELPERFUNCTIONS_H


//private:
    map<string, string*> allAirports;
    void readAllAirports();

//public:
    map<string, string*> getAllAirports();

#endif //AIRLINEROUTES_HELPERFUNCTIONS_H
