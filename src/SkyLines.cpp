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

void SkyLines::createCountries() {
    //TODO - read the cities file and store the information in the unordered map
}

void

void SkyLines::createAirports() {
    //TODO read the airports file and add the airports to the unordered map
}

void SkyLines::createGraph() {
    //TODO read the flights file and add the flights to the graph
}
