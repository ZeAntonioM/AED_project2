#include <cfloat>
#include <queue>
#include <utility>
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
        if (distance < minDistance and !node.disabled) {
            minDistance = distance;
            closestNode = node;
        }
    }
    return closestNode;
}

void Graph::addEdge(int origin, int destination, unordered_set<string> &airlines) {
    //check if node can be added to graph
    if (origin < 0 || destination > (int) nodes.size() || origin > (int) nodes.size() || destination < 0) return;

    this->nodes[origin].hashMapEdges[destination] = {destination, airlines};
}

void Graph::BFS(int origin) {
    for (int i = 1; i < (int) nodes.size(); i++){
        nodes[i].visited = false;
        nodes[i].distance = 0;
        nodes[i].parent = i;
    }

    //check if airport is disabled or not
    if(nodes[origin].disabled){
        cout << "Airport is disabled" << endl;
        return;
    }

    queue<int> q;
    q.push(origin);
    nodes[origin].visited = true;
    nodes[origin].distance = 0;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        //ignore the node if it is disabled
        if(nodes[current].disabled) continue;

        int size = nodes[current].hashMapEdges.size();

        // "iterating" through the hashMapEdges
        for (int i = 0 ; i < size; i++)
        {
            Edge e = nodes[current].hashMapEdges[i];

            int n = e.destination;

            if (!nodes[n].visited)
            {
                q.push(n);
                nodes[n].visited = true;
                nodes[n].distance = nodes[current].distance + 1;
                nodes[n].parent = current;
            }
        }
    }
}

int Graph::shortestPath(int origin, int destination) {

    BFS(origin);

    return (nodes[destination].distance);
}

void Graph::clear() {
    for(auto &node : this->nodes){
        node.hashMapEdges.clear();
    }
}

vector<Node> Graph::getNodes() {
    return nodes;
}

void Graph::disableAirport(int index) {
    this->nodes[index].disabled = true;
}

vector<Node> Graph::generateFlightPath(int origin, int destination) {
    vector<Node> path = {};

    if(nodes[origin].disabled || nodes[destination].disabled){
        cout << "Origin/Destinatio airport is disabled" << endl;
        return path;
    }

    if(nodes[destination].parent == destination){
        cout << "No path found" << endl;
        return path;
    }

    //building the path
    path.push_back(nodes[destination]);
    while(nodes[destination].parent != origin){
        destination = nodes[destination].parent;
        path.push_back(nodes[destination]);
    }
    return path;

}


