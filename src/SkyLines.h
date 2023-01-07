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
     * Function that prints all the information about the airline
     * Time complexity: O(1)
     */
    void printInfo() const;
};


class SkyLines {
private:

    /**
     * Definition of number of airports and some file paths and useful for the class
     */
    static const int NUMBER_AIRPORTS;

    /**
     * Filepath to the airlines.csv folder to be read
     */
    static const string AIRLINES;

    /**
     * Filepath to the airports.csv folder to be read
     */
    static const string AIRPORTS;

    /**
     * Filepath to the flights.csv folder to be read
     */
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
     * @var maxAirports - Maximum number of airports that can be in a flight path
     */
    int maxAirports;

    /**
     * @var maxDistance - Maximum radius used to search for airports
     */
    int maxDistance;

    /**
     * Function that adds a node to the graph
     * Time Complexity: O(1)
     * @param node - node to be added
     * @param index - index of the node
     */
    void addAirport(const Node &node, int index);

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
     * Function that changes the state of a given airport
     * Time Complexity: O(V), V being the number of nodes
     * @param code - code of the airport
     * @param enable - boolean used to determine to which state to change
     */
    void changeAirportState(const string &code, const bool &enable);

    /**
     * Function that changes the state of all airports
     * Time Complexity: O(V), V being the number of nodes
     * @param enable - boolean used to determine to which state to change
     */
    void changeAllAirportState(const bool &enable);

    /**
     * Function that changes the state of a given airline
     * Time Complexity: O(V+E+A), V being the number of nodes, E being the number of edges, A being the number of airlines in each edge
     * @param code - code of the airline
     * @param enable - boolean used to determine to which state to change
     */
    void changeAirlineState(const string &code, const bool &enable);

    /**
     * Function that changes the state of all airlines
     * Time Complexity: O(V+E+A), V being the number of nodes, E being the number of edges, A being the number of airlines in each edge
     * @param enable - boolean used to determine to which state to change
     */
    void changeAllAirlineState(const bool &enable);

    /**
     * Function that returns a copy of the node corresponding to the airport that matches the code provided, or in case of not finding one, returns an empty node object
     * Time Complexity: O(1)
     * @param code - code of the airport to find
     * @return Copy of the node corresponding to the found airport
     */
    Node getAirport(const string &code);

    /**
     * Function that searches for all available airports in a given city in a given country, and allows the user to choose one to return
     * Time Complexity: O(V), V being the number of nodes
     * @param city - string representing the city in which to search for
     * @param country - string representing the country in which to search for
     * @return Copy of the node corresponding to the user-chosen airport
     */
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
     * Time complexity: O(n1+n2+n3), n1 being the number of lines in the airports file, n2 being the number of lines in the airlines file, n3 being the number of lines in the flights file
     */
    void reset();

    /**
     * Setter for the maximum number of airports that can be in a flight path
     * Time complexity: O(1)
     * @param maxAirports - number to be set
     */
    void setMaxAirports(int maxAirports);

    /**
     * Setter for the maximum radius to search for airports in
     * @param maxDistance - number to be set
     */
    void setMaxDistance(int maxDistance);

};

#endif //AED_PROJECT2_SKYLINES_H
