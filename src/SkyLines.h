#ifndef AED_PROJECT2_SKYLINES_H
#define AED_PROJECT2_SKYLINES_H

#include "Graph.h"

struct Airline {

    /**
     * @var name - name of the airline
     */
    string name;

    /**
     * @var callsign - callsign of the airline
     */
    string callsign;

    /**
     * @var country - country of the airline
     */
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
     * @var airports - unordered map that stores the airport's code and the index of the airport in the graph
     */
    unordered_map<string, int> airports;

    /**
     * @var companies - unordered map that stores the airline's code and their respective information
     */
    unordered_map<string, Airline> companies;

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
     * @param airlines - vector of strings with the airlines that operate the flight
     */
    void addFlight(int origin, int destination, unordered_set<string> &airlines);

    /**
     * Function that creates the airports and adds them to an unordered map and the graph.
     * Time complexity: //TODO
     */
    void createAirports();

    /**
     * Function that creates the airlines ant puts them on an unordered map.
     * Time complexity: //TODO
     */
    void createCompanies();

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

    void findRoute(const string &originAirport, const string &destinationAirport);

    void findRoute(const Coordinate &origin, const Coordinate &destination);

    /**
     * Function that disables an airport requested by the user
     * @param code - code of the airport to be disabled
     */
    void disableAirport(const string &code);


};


#endif //AED_PROJECT2_SKYLINES_H
