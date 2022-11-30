//
// Created by Yasmin on 11/27/2022.
//

#include "HelperFunctions.h"
using namespace std;


/**
   * reads all airports in the airports.csv file and stores it in hashmap
*/


void readAllAirports() {
    ifstream fin;
    fin.open("airports.csv");

    string zero;
    string airport_name;
    string two;
    string three;
    string icao_code;
    string five;
    string latitude;
    string longitude;

    while(!fin.eof()){
        getline(fin, zero, ',');
        getline(fin, airport_name, ',');
        getline(fin, two, ',');
        getline(fin, three, ',');
        getline(fin, icao_code, ',');
        getline(fin, five, ',');
        getline(fin, latitude, ',');
        getline(fin, longitude, ',');
//        boost::split(airport_data, line, boost::is_any_of("(,)(?=(?:[^\"]|\"[^\"]*\")*$)"));

        string temp[3] = {airport_name, latitude, longitude};
        allAirports.insert({icao_code, temp});
    }
}

map<string, string*> getAllAirports(){
    return allAirports;
}



