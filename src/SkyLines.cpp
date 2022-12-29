#include "SkyLines.h"

const int SkyLines::NUMBER_AIRPORTS = 3019;
const string SkyLines::AIRLINES = "../data/airlines.csv";
const string SkyLines::AIRPORTS = "../data/airports.csv";
const string SkyLines::FLIGHTS = "../data/flights.csv";

SkyLines::SkyLines() : graph(NUMBER_AIRPORTS) {
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

void SkyLines::findRoute(const Coordinate &origin, const Coordinate &destination) {
    findRoute(graph.getNode(origin).code, graph.getNode(destination).code);
}

void SkyLines::findRoute(const string &originAirport, const string &destinationAirport) {
    auto origin = airports.find(originAirport);
    auto destination = airports.find(destinationAirport);

    //TODO
}


