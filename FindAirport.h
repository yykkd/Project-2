//
// Created by Yasmin on 11/20/2022.
//

#include "string"
#include "cstring"
#include "map"
#include "vector"
#include "fstream"
using namespace std;
#define BOOST_PROGRAM_OPTIONS_SOURCE

#ifndef AIRLINEROUTES_AIRPORT_H
#define AIRLINEROUTES_AIRPORT_H


class FindAirport {
private:
    vector<string> matching_airports;

public:
    vector<string> getMatchingAirports();
    FindAirport(string city_name, string country_name);
    string country;
    string city;

private:
    bool equals(string airport_city, string airport_country);
    void readMatchingAirports();

};

#endif //airlineroutes_airport_h
