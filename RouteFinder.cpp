//
// Created by Yasmin on 11/26/2022.
//

#include "RouteFinder.h"
#include "math.h"

/**
     * creates a graph of all valid routes and stores it in a hashmap
     * @param available_airlines the airlines that are available to fly
*/




bool RouteFinder::findOneStepPath(string destination_airport){
    for(string* arr: source_airports){
        if(arr[3] == destination_airport){
            vector<string> temp = {arr[2], arr[3]};
            path.push_back(temp);
            return true;
        }
    }
    return false;
}


bool RouteFinder::findMultiPath(string destination_airport) {
    string curr_airport = source_acode;
    vector<string> next_level;

    if(curr_airport.empty()){
        cout << "No solution found";
        exit;
    }
    if(curr_airport == destination_airport){
        cout << "Already in city. Enter a different city";
        return true;
    }

    vector<string> explored;
    vector<string> frontier = {curr_airport};
    store_parent[curr_airport] = "None";

    while(frontier.size() > 0){
        curr_airport.erase(curr_airport.begin());
        explored.push_back(curr_airport);

        next_level = airport_graph.at(curr_airport);
        for(string child: next_level){
            if(!(count(explored.begin(), explored.end(), child)) && !(count(frontier.begin(), frontier.end(), child))){
                store_parent[child] = curr_airport;

                if(child == destination_airport){
                    solutionPath(destination_airport);
                    return true;
                }
                frontier.push_back(child);
            }
        }
    }
    return false;
}


void RouteFinder::findStartRoutes(vector<string> city_airports) {
    ifstream fin;
    fin.open("routes.csv");

    string airline_code;
    string airline_id;
    string source_airport_code;
    string source_airport_id;
    string destination_airport_code;
    string destination_airport_id;
    string codeshare;
    string stops;

    while(!fin.eof()) {
        getline(fin, airline_code, ',');
        getline(fin, airline_id, ',');
        getline(fin, source_airport_code, ',');
        getline(fin, source_airport_id, ',');
        getline(fin, destination_airport_code, ',');
        getline(fin, destination_airport_id, ',');

        if(count(city_airports.begin(), city_airports.end(), source_airport_code)){
            source_acode = source_airport_code;
            string temp[] = {airline_code, airline_id, source_airport_code, destination_airport_code, stops};
            source_airports.push_back(temp);
        }
    }
}


vector<string> RouteFinder::getAirportidStops(string start, string destination) {
    ifstream fin;
    fin.open("routes.csv");

    string airline_code;
    string airline_id;
    string source_airport_code;
    string source_airport_id;
    string destination_airport_code;
    string destination_airport_id;
    string codeshare;
    string stops;

    while(fin.eof()){
        if(source_airport_code == start && destination_airport_code == destination){
            vector<string> temp = {airline_code, stops};
            return temp;
        }
    }

    return {};
}

void RouteFinder::solutionPath(string destination) {
    vector<string> temp;

    while(!(store_parent.at(destination) != "None")){
        string string_temp = "[" + store_parent.at(destination) + ", " + destination + "]";
        temp.insert(temp.begin(), string_temp);
        destination = store_parent.at(destination);

    }
   if(!(count(this->path.begin(), this->path.end(), temp))){
       path.push_back(temp);
   }
}

void RouteFinder::createGraph(vector<string> available_airlines) {
    ifstream fin;
    fin.open("routes.csv");

    string airline_code;
    string airline_id;
    string source_airport_code;
    string source_airport_id;
    string destination_airport_code;
    string destination_airport_id;
    string codeshare;
    string stops;

    while(!fin.eof()){
        getline(fin, airline_code, ',');
        getline(fin, airline_id, ',');
        getline(fin, source_airport_code, ',');
        getline(fin, source_airport_id, ',');
        getline(fin, destination_airport_code, ',');
        getline(fin, destination_airport_id, ',');

        if(std::count(available_airlines.begin(), available_airlines.end(), airline_code)){
            if(!airport_graph.count(source_airport_code)){
                if(!(destination_airport_code == "/N")){
                    vector<string> temp = {destination_airport_code};
                    airport_graph[source_airport_code] = temp;
                }
            }else{
                vector<string> temp= airport_graph.at(source_airport_code);
                if(!(destination_airport_code == "/N")){
                    temp.push_back(destination_airport_code);
                    airport_graph[source_airport_code] = temp;
                }
            }
        }
    }
}

RouteFinder::RouteFinder(vector<string> available_airlines) {
    createGraph(available_airlines);
}


double RouteFinder::haversine(double lat1, double lon1, double lat2, double lon2) {
    // distance between latitudes and longitudes
    double latitude = (lat2 - lat1) * (M_PI/180);
    double longitude = (lon2 - lon1) * (M_PI/180);

    // convert to radians
    lat1 = (lat1) * (M_PI/180);
    lat2 = (lat2) * (M_PI/180);

    // apply formulae
    double a = pow(sin(latitude / 2), 2) +
               pow(sin(longitude / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}



