//
// Created by sergiopeixoto on 28-12-2022.
//

#ifndef AED_PROJECT2_SKYLINES_H
#define AED_PROJECT2_SKYLINES_H

#include <unordered_map>
#include "Graph.h"


/**
 * Definitoin of some file paths useful for the class
 */
#define AIRLINES "../data/airlines.csv"
#define AIRPORTS "../data/airports.csv"
#define FLIGHTS "../data/flights.csv"


class SkyLines {
private:

    /**
     * @var graph - graph that contains all the airports and flights
     */
    Graph graph;


    //TODO define another unordered map or unordered set to store something useful as per the project's requirements
    unordered_map<string, int> something;
    unordered_map<string, string> somethingElse;

    //TODO functions to

};


#endif //AED_PROJECT2_SKYLINES_H
