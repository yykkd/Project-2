//
// Created by Yasmin on 11/26/2022.
//

#include "AirlineManager.h"

/**
 * Constructor definition
 * @param current_country country airline is in
 * @param icao_code identity code
 * @param is_active is flying or not
 */
AirlineManager::AirlineManager(){
    readFile();
}

void AirlineManager::readFile() {
    string airlineID;
    string name;
    string alias;
    string iata_code;
    string icao_code;
    string callsign;
    string country;
    string active;

    ifstream fin;
    fin.open("airlines.csv");

    while (!fin.eof()) {
        getline(fin, airlineID, ',');
        getline(fin, name, ',');
        getline(fin, alias, ',');
        getline(fin, iata_code, ',');
        getline(fin, icao_code, ',');
        getline(fin, callsign, ',');
        getline(fin, country, ',');
        getline(fin, active, '\n');

        if(canFly(active)){
            available_airlines_icao.insert({iata_code, icao_code});
            available_airlines.push_back(iata_code);
        }
    }
}


bool AirlineManager::canFly(string active) {
    return active == "Y";
}

vector<string> AirlineManager::getAvailableAirlines(){
    return available_airlines;
}

map<string, string> AirlineManager::getAvailableAirlinesIcao(){
    return available_airlines_icao;
};