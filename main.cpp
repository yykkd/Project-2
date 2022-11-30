#include <iostream>
#include "ReadWrite.h"
#include "FindAirport.h"
#include "AirlineManager.h"
#include "RouteFinder.h"


int main() {
    vector<string> file_contents = readFile();
//    string start_city = file_contents.at(0);
//    string start_country = file_contents.at(1);
//    string destination_city = file_contents.at(2);
//    string destination_country = file_contents.at(3);
//
//    vector<vector<string>> all_paths;
//
//    FindAirport starting = FindAirport(start_city, start_country);
//    FindAirport destination = FindAirport(destination_city, destination_country);
//
//    vector<string> starting_airports = starting.getMatchingAirports();
//    vector<string> destination_airports = destination.getMatchingAirports();
//
//    AirlineManager air = AirlineManager();
//    vector<string> available_airlines = air.getAvailableAirlines();
//
//    RouteFinder route = RouteFinder(available_airlines);
//    route.findStartRoutes(starting_airports);
//
//    bool found1 = false;
//    bool found_multiple_paths = false;
//
//    for(string airport: destination_airports){
//        found1 = route.findOneStepPath(airport);
//        found_multiple_paths = route.findMultiPath(airport);
//    }
//
//    if (found1 || found_multiple_paths) {
//        all_paths = route.path;
//    } else{
//        cout << "No route found";
//        exit(0);
//    }
//



}
