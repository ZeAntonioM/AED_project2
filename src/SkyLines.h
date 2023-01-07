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

    /**
     *
     */
    bool disabled = false;

    void printInfo() const;
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
     * @var max - Maximum number of airports that can be in a flight path
     */
    int maxAirports;
    int maxDistance;

    /**
     * Function that adds a node to the graph
     * Time Complexity: O(1)
     * @param node - node to be added
     * @param index - index of the node
     */
    void addAirport(const Node &node, int index);

    /**
     * Function that adds an edge to the graph
     * Time Complexity: O(1)
     * @param origin - origin node of the edge
     * @param destination - destination node of the edge
     * @param airlines - vector of strings with the airlines that operate the flight
     */
    void addFlight(int origin, int destination, unordered_set<string> &airlines);

    /**
     * Function that creates the airports and adds them to an unordered map and the graph.
     * Time complexity: O(n), n being the number of lines in the file
     */
    void createAirports();

    /**
     * Function that creates the airlines ant puts them on an unordered map.
     * Time complexity: O(n), n being the number of lines in the file
     */
    void createCompanies();

    /**
     * Function that creates the countries and puts them on an unordered map and creates the edges referring to a flight.
     * Time complexity: O(n), n being the number of lines in the file
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

    /**
     * Function that finds the shortest possible flight route between two airports
     * Time Complexity: O(V+E), V being the number of nodes, E being the number of edges
     * @param originAirport - code for the departure airport
     * @param destinationAirport - code for the arrival airport
     */
    void findRoute(const string &originAirport, const string &destinationAirport);

    /**
     * Function that finds the shortest possible flight route between two airports
     * Time Complexity: O(V+E), V being the number of nodes, E being the number of edges
     * @param origin - coordinate corresponding to departure location
     * @param destination - coordinate corresponding to arrival location
     */
    void findRoute(const Coordinate &origin, const Coordinate &destination);

    /**
     * Function that disables an airport requested by the user
     * Time Complexity: O(1)
     * @param code - code of the airport to be disabled
     */

    void changeAirportState(const string &code, const bool &enable);

    void changeAllAirportState(const bool &enable);

    void changeAllAirlineState(const bool &enable);

    /**
     * Function that disables an airline requested by the user
     * Time Complexity: O(1)
     * @param code - code of the airline to disabled
     */
    void changeAirlineState(const string &code, const bool &enable);

    /**
     * Function that returns a copy of the node corresponding to the airport that matches the code provided, or in case of not finding one, returns an empty node object
     * Time Complexity: O(1)
     * @param code - code of the airport to find
     * @return Copy of the node corresponding to the found airport
     */
    Node getAirport(const string &code);

    Node getAirport(const string &city, const string &country);

    /**
     * Getter for the Airports vector
     * Time Complexity: O(1)
     * @return vector containing all the nodes of the graph (aka the Airports)
     */
    vector<Node> getAirports();

    /**
     * Getter for the Airline Companies unordered_map
     * Time Complexity: O(1)
     * @return unordered_map containing all the key value pairs of (string Airline Code, Airline Object)
     */
    unordered_map<string, Airline> getCompanies() const;

    /**
     * Function that returns a copy of the Airline object whose code matches the provided code
     * Time Complexity: O(1)
     * @param code - code of the Airline to be found
     * @return copy of the found Airline object, or empty Airline object if none found
     */
    Airline getAirline(const string &code);

    /**
     * Function that resets the graph back to its original state
     */
    void reset();

    /**
     * Function that sets the maximum number of airports that can be in a flight path
     */
    void setMaxAirports(int maxAirports);

    void setMaxDistance(int maxDistance);

};

#endif //AED_PROJECT2_SKYLINES_H
