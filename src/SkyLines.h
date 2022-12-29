//
// Created by sergiopeixoto on 28-12-2022.
//

#ifndef AED_PROJECT2_SKYLINES_H
#define AED_PROJECT2_SKYLINES_H

#include <unordered_map>
#include "Graph.h"


/**
 * Definition of number of airports and some file paths and useful for the class
 */
#define numberAirports 3019
#define AIRLINES "../data/airlines.csv"
#define AIRPORTS "../data/airports.csv"
#define FLIGHTS "../data/flights.csv"


class SkyLines {
private:

    /**
     * @var graph - graph that contains all the airports and flights
     */
    Graph graph;


    /**
     * @var airports - unordered map that stores the airports and their respective city
     */
    unordered_map<string, string> airports;

    //TODO define another unordered map or unordered set to store something useful as per the project's requirements
    //unordered_map<string, string> flights;

    //TODO functions to read the files and store the information in the unordered maps and graph

    /**
     * Function that adds a node to the graph
     * @param node - node to be added
     * @param index - index of the node
     */
    void addAirport(const Node &node, int index);

    /**
     * Function that adds an edge to the graph
     * @param origin - origin node of the edge
     * @param destination - destination node of the edge
     */
    void addFlight(int origin, int destination);

    /**
     * Function that creates the airports and adds them to the graph and the unordered map
     * Time complexity: //TODO
     */
    void createAirports();

public:
    /**
     * Default constructor
     */
    SkyLines();

    /**
     * Default destructor
     */
    ~SkyLines();

    //TODO define the functions that will be used in the menu

};


#endif //AED_PROJECT2_SKYLINES_H
