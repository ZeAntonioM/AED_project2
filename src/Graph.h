//
// Created by sergiopeixoto on 26-12-2022.
//

#ifndef AED_PROJECT2_GRAPH_H
#define AED_PROJECT2_GRAPH_H

#include <cmath>

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

struct Edge{

};

class Graph {
private:


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
