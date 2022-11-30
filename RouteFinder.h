//
// Created by Yasmin on 11/26/2022.
//
#include "string"
#include <map>
#include <vector>
#include <fstream>
#include <cstring>
#include "iostream"
#include "algorithm"
using namespace std;

#ifndef AIRLINEROUTES_ROUTEFINDER_H
#define AIRLINEROUTES_ROUTEFINDER_H
#define BOOST_PROGRAM_OPTIONS_SOURCE

class RouteFinder{
private:
    map<string, vector<string>> airport_graph;
    map<string, string> store_parent;
    vector<string*> source_airports;
    string source_acode;
    static double haversine(double lat1, double lon1, double lat2, double lon2);


public:
    RouteFinder(vector<string> available_airlines);
    void findStartRoutes(vector<string> city_airports);
    bool findOneStepPath(string destination_airport);
    bool findMultiPath(string destination_airport);
    vector<vector<string>> path;

private:
    void createGraph(vector<string> available_airline);

    vector<string> getAirportidStops(string start, string destination);
    void  solutionPath(string destination);
    void findRoute();
};

#endif //AIRLINEROUTES_ROUTEFINDER_H
