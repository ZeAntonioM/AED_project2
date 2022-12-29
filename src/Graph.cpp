//
// Created by sergiopeixoto on 26-12-2022.
//

#include <cfloat>
#include "Graph.h"

Graph::Graph(int nodes) : nodes(nodes+1){}

double Graph::calculateDistance(double lat1, double lon1, double lat2, double lon2) {

    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c; //in km
}

void Graph::addNode(const Node &node, int index) {
    this->nodes[index] = node;
}

Node Graph::getNode(const Coordinate &coordinate) {

    Node closestNode;
    auto minDistance = DBL_MAX;
    for (auto &node : this->nodes) {
        double distance = calculateDistance(node.coordinate.latitude, node.coordinate.longitude, coordinate.latitude,
                                          coordinate.longitude);
        if (distance < minDistance) {
            minDistance = distance;
            closestNode = node;
        }
    }
    return closestNode;
}

void Graph::addEdge(int origin, int destination) {
    //check if node can be added to graph
    if (origin < 1 || destination > nodes.size() || origin > nodes.size() || destination < 1) return;
    this->nodes[origin].adjacentEdges.push_back({destination, calculateDistance(this->nodes[origin].coordinate.latitude,
                                                                                this->nodes[origin].coordinate.longitude,
                                                                                this->nodes[destination].coordinate.latitude,
                                                                                this->nodes[destination].coordinate.longitude)});
}

void Graph::clear() {
    for(auto &node : this->nodes){
        node.adjacentEdges.clear();
    }
}
