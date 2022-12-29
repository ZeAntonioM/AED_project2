#ifndef AED_PROJECT2_SKYLINES_H
#define AED_PROJECT2_SKYLINES_H

#include "bits/stdc++.h"
#include "Graph.h"

struct airport{
    string code;
    string name;
    string city;
    string country;
    Coordinate coordinate;
};

struct airline {
    string name;
    string callsign;
    string country;
};

class SkyLines {
private:

    /**
     * @var graph - graph that contains all the airports and flights
     */
    Graph graph;


    /**
     * @var airports - unordered map that stores the airports and their respective city
     */
    unordered_map<int, airport> airports;

    /**
     * @var airlines - unordered map that stores the airlines and their respective information
     */
    unordered_map<string, airline> airlines;

    /**
     * @var flights - unordered map that stores the flights and their respective information
     */
    unordered_map<string, string> flights;


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
     * @param companies - vector of strings with the companies that operate the flight
     */
    void addFlight(int origin, int destination, vector<string> companies);

    /**
     * Function that creates the airports and adds them to an unordered map and the graph.
     * Time complexity: //TODO
     */
    void createAirports();

    /**
     * Function that creates the airlines ant puts them on an unordered map.
     * Time complexity: //TODO
     */
    void createAirlines();

    /**
     * Function that creates the countries and puts them on an unordered map and creates the edges referring to a flight.
     * Time complexity: //TODO
     */
    void createFlights();

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
