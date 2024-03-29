#ifndef AED_PROJECT2_GRAPH_H
#define AED_PROJECT2_GRAPH_H

#include "bits/stdc++.h"

using namespace std;

/**
 * Struct that represents a Coordinate using latitude and longitude
 */
struct Coordinate {
    /**
     * @var latitude - latitude of the coordinate
     */
    double latitude;

    /**
     * @var longitude - longitude of the coordinate
     */
    double longitude;
};

/**
 * Struct representing a flight between two airports
 */
struct Edge{
    /**
     * @var destination - destination node of the edge
     */
    int destination;

    /**
     * @var airlines - Airlines that operates the flight
     */
    unordered_set<string> airlines;

    /**
     * @var disabledAirlines - Disabled airlines for the flight
     */
    unordered_set<string> disabledAirlines;


};

/**
 * Struct that represents an airport in the graph
 */
struct Node{
    /**
     * @var code - a string representing the code of the airport
     */
    string code = "";

    /**
     * @var name - a string representing the name of the airport
     */
    string name = "";

    /**
     * @var city - a string representing the city of the airport
     */
    string city = "";

    /**
     * @var country - a string representing the country of the airport
     */
    string country = "";

    /**
     * @var coordinate - a Coordinate struct representing the coordinate of the airport
     */
    Coordinate coordinate;

    /**
     * @var hashMapEdges - a hashMap that stores the destination node and the edge between the current node and the destination node
     */
    unordered_map<int, Edge> hashMapEdges;

    /**
     * @var visited - a boolean representing if the node has been visited
     */
    bool visited = false;

    /**
     * @var distance - a double representing the distance (number of nodes, not in km) from the origin node
     */
    int distance = 0; //!IMPORTANT: this is the number of nodes, not in km

    /**
     * @var parent - a int representing the parent node of the current node
     */
    int parent = 0;

    /**
     * @var disabled - a boolean representing if the node is disabled
     */
    bool disabled = false;

    /**
     * Function that prints all the info of the node
     * Time complexity: O(1)
     */
    void printInfo();
};

class Graph {
private:
    /**
     * @var nodes - a vector of Node structs representing the airports in the graph
     */
    vector<Node> nodes;

    /**
     * Function that returns the distance between two points with coordinates passed by parameter
     * Time Complexity: O(log(n))
     * @param lat1 - a double value represents the latitude of first point
     * @param lon1 - a double value represents the longitude of first point
     * @param lat2 - a double value represents the latitude of second point
     * @param lon2 - a double value represents the longitude of second point
     * @return - a double value containing the distance between two points
     */
    static double calculateDistance(double lat1, double lon1, double lat2, double lon2);

public:
    /**
     * Graph constructor
     * @param nodes integer number that represents the number of nodes the graph must have
     */
    Graph(int nodes);

    /**
     * Function that adds a node to the graph
     * Time Complexity: O(1)
     * @param node - a Node struct representing the Airport to be added
     * @param index - an int representing the index of the Airport to be added
     */
    void addNode(const Node &node, int index);

    /**
     * Function that returns the closest Airport given a coordinate
     * Time Complexity: O(V), where V is the number of nodes in the graph
     * @param coordinate - a Coordinate struct representing the coordinate of the Airport to be found
     * @return - a Node struct representing the closest Airport to the given coordinate
     */
    vector<Node> getNode(const Coordinate &coordinate, int distance);

    /**
     * Getter for the vector of nodes
     * Time complexity: O(1)
     * @return - a vector containing all the graph's nodes
     */
    vector<Node> getNodes();

    /**
     * Setter for the vector of nodes
     * Time complexity: O(1)
     * @param newNodes - vector to set as the graph's node vector
     */
    void setNodes(vector<Node> newNodes);

    /**
     * Function that applies breadth-first search on the graph, changing the distance of each node based on the origin node
     * Time Complexity: O(V+E), V being the total number of nodes, E being the total number of edges
     * @param origin - an int representing the index of the origin node
     */
    void BFS(int origin);

    /**
     * Function to clear all nodes from the graph
     * Time Complexity: O(V), where V is the number of nodes in the graph
     */
    void clear();

    /**
     * Function that disables an airport given an index
     * Time Complexity: O(1)
     * @param index - an int representing the index of the airport to be disabled
     */
    void disableAirport(int index);

    /**
     * Function that enables an airport given an index
     * Time Complexity: O(1)
     * @param index - an int representing the index of the airport to be enabled
     */
    void enableAirport(int index);

    /**
     * Function that disables an airline given its code
     * Time complexity: 0(V+E), V being the number of nodes, E being the number of edges
     * @param airline - string representing the code of the airline to be disabled
     */
    void disableAirline(const string &airline);

    /**
     * Function that disables an airline given its code
     * Time complexity: 0(V+E), V being the number of nodes, E being the number of edges
     * @param airline - string representing the code of the airline to be disabled
     */
    void enableAirline(const string &airline);

    /**
     * Function that creates the shortest path between two available airports
     * Time complexity: O(V+E), V being the number of nodes, E being the number of edges
     * @param origin - an int representing the index of the origin airport
     * @param destination - an int representing the index of the destination airport
     * @return - a vector of Nodes representing the airports in the path
     */
    vector<Node> generateFlightPath(int origin, int destination);


};


#endif //AED_PROJECT2_GRAPH_H
