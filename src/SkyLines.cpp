//
// Created by sergiopeixoto on 28-12-2022.
//

#include "SkyLines.h"

SkyLines::SkyLines() : graph(numberAirports) {
    createAirports();
    //TODO
}

SkyLines::~SkyLines() {
    this->graph.clear();
}

void SkyLines::addAirport(const Node &node, int index) {
    this->graph.addNode(node, index);
}

void SkyLines::addFlight(int origin, int destination) {
    this->graph.addEdge(origin, destination);
}

void SkyLines::createAirports() {
    //TODO read the airports file and add the airports to the graph and the unordered map
}
