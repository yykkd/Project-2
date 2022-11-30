//
// Created by Yasmin on 11/26/2022.
//

#include "string"
#include "map"
#include "vector"
#include "fstream"
using namespace std;

#ifndef AIRLINEROUTES_AIRLINE_H
#define AIRLINEROUTES_AIRLINE_H

class AirlineManager{
private:
    vector<string> available_airlines;
    map<string, string> available_airlines_icao;

    string country;
    string airline_code;
    string icao_code;
    string is_active;

public:
    AirlineManager();
    vector<string> getAvailableAirlines();
    map<string, string> getAvailableAirlinesIcao();

private:
    void readFile();
    bool canFly(string active);
};

#endif //AIRLINEROUTES_AIRLINE_H
