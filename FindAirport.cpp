//
// Created by Yasmin on 11/20/2022.
//

#include "FindAirport.h"
using namespace std;

/**
 * FindAirport constructor definition
 * @param city_name city airport is in
 * @param country_name country airport is in
 */
FindAirport::FindAirport(string city_name, string country_name) {
    this->city = city_name;
    this->country = country_name;
}


/**
     * compares object with an airport
     * @param anotherObj an array version of row entry in airports
     * @return a boolean to indicate whether two entries are equal or not
     */
bool FindAirport::equals(string airport_city, string airport_country) {
    string city_holder = airport_city;
    string country_holder = airport_country;

    char quotationMark[] =  {'"'};

    if (city_holder.length() > 0) {
        if (strcmp(&city_holder.at(0), quotationMark) == 0) {
            city_holder = city_holder.substr(1, city_holder.length() - 1);
        }
    }

    const char* city_holder_arr = city_holder.c_str();
    const char* city_arr = this->city.c_str();
    const char* country_holder_arr = country_holder.c_str();
    const char* country_arr = this->country.c_str();

    bool return_value = strcmp(city_holder_arr, city_arr) && strcmp(country_holder_arr, country_arr);

    delete city_holder_arr;
    delete city_arr;
    delete country_holder_arr;
    delete country_arr;

    return return_value;
}


/**
    * returns all airports in starting city with a valid destination
 */
void FindAirport::readMatchingAirports() {
    ifstream fin;
    fin.open("airports.csv");

    string zero;
    string airport_name;
    string airport_city;
    string airport_country;
    string icao_code;
    string five;
    string latitude;
    string longitude;

    while(!fin.eof()){
        getline(fin, zero, ',');
        getline(fin, airport_name, ',');
        getline(fin, airport_city, ',');
        getline(fin, airport_country, ',');
        getline(fin, icao_code, ',');
        getline(fin, five, ',');
        getline(fin, latitude, ',');
        getline(fin, longitude, ',');


        if(equals(airport_city, airport_country) && !(icao_code == "\\N")){
            string temp[4] = {airport_name, icao_code, latitude, longitude};
            matching_airports.push_back(icao_code);
        }
    }
}

/**
 * gets matching airports for city and country
 * @return map with icao code for airports and array for details
 */
vector<string> FindAirport::getMatchingAirports() {
    readMatchingAirports();
    return this->matching_airports;
}
