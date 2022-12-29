#ifndef AED_PROJECT2_SKYLINES_H
#define AED_PROJECT2_SKYLINES_H

#include <unordered_map>
#include "Graph.h"


struct Airline {
    string name;
    string callsign;
    string country;

};


class SkyLines {
private:

    /**
     * Definition of number of airports and some file paths and useful for the class
     */
    static const int NUMBER_AIRPORTS;
    static const string AIRLINES;
    static const string AIRPORTS;
    static const string FLIGHTS;


    /**
     * @var graph - graph that contains all the airports and flights
     */
    Graph graph;

    /**
     * @var airports - unordered map that stores the airport's code and their respective city
     */
    unordered_map<string, string> airports;

    /**
     * @var airlines - unordered map that stores the airline's code and their respective information
     */
    unordered_map<string, Airline> airlines;

    /**
     * @var countries - unordered map that stores the airline's code and their country
     */
    unordered_map<string, string> countries;

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
     * Function that creates the airports and adds them to an unordered map and the graph.
     * Time complexity: //TODO
     */
    void createAirports();

    /**
     * Function that link the cities and the airports in an unordered map.
     * Time complexity: //TODO
     */
    void createCountries();

    /**
     * Function that creates the airlines ant puts them on an unordered map.
     * Time complexity: //TODO
     */
    void createAirlines();

    /**
     * Function that creates the graph and reads the flights file.
     * Time complexity: //TODO
     */
    void createGraph();



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

    void findRoute(const string &originAirport, const string &destinationAirport);

    void findRoute(const Coordinate &origin, const Coordinate &destination);

};


#endif //AED_PROJECT2_SKYLINES_H
