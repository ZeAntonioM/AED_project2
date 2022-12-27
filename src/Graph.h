//
// Created by sergiopeixoto on 26-12-2022.
//

#ifndef AED_PROJECT2_GRAPH_H
#define AED_PROJECT2_GRAPH_H

#include <cmath>
#include <string>
#include <vector>
#include <list>

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
 * Struct representing the three customizable weights for Dijsktra's algorithm
 */
struct DijkstraWeight {
    /**
     * @var distance - distance from the current node and the origin node
     */
    double distance;

    //TODO choose what will be the last two weights
    int something;
    int somethingElse;


};

/**
 * Struct representing an edge between two nodes
 */
struct Edge{
    /**
     * @var destination - destination node of the edge
     */
    int destination;

    /**
     * @var weight - weight of the edge (representing length in km)
     */
    double weight;

    /**
     * @var name - name of the edge
     */
    string name;
};

/**
 * Struct that represents an airport in the graph
 */
struct Node{
    /**
     * @var code - a string representing the code of the airport
     */
    string code;

    /**
     * @var name - a string representing the name of the airport
     */
    string name;

    /**
     * @var country - a string representing the country of the airport
     */
    string city;

    /**
     * @var country - a string representing the country of the airport
     */
    string country;

    /**
     * @var coordinate - a Coordinate struct representing the coordinate of the airport
     */
    Coordinate coordinate;

    /**
     * @var edges - a vector of Edge structs representing the edges of the airport
     */
    list<Edge> adjacentEdges;

    /**
     * @var visited - a boolean representing if the node has been visited
     */
    bool visited;

    /**
     * @var distance - a double representing the distance (number of nodes, not in km) from the origin node
     */
    int distance;

    /**
     * @var parent - a int representing the parent node of the current node
     */
    int parent;

    /**
     * @var weight - a DijkstraWeight struct representing the weight of the node
     */
    DijkstraWeight weight;

    //TODO add more if needed
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
     * @return a double value containing the distance between two points
     */
    double computeDistance(double lat1, double lon1, double lat2, double lon2);

public:

    /**
     * Graph constructor
     * @param nodes integer number that represents the number of nodes the graph must have
     */
    Graph(int nodes);
};


#endif //AED_PROJECT2_GRAPH_H
