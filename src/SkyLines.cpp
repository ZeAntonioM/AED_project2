#include "SkyLines.h"

#include <utility>

static int numberAirports = 3019;

SkyLines::SkyLines() : graph(numberAirports) {
    createAirports();
    createAirlines();
    createFlights();
    //TODO
}

SkyLines::~SkyLines() {
    this->graph.clear();
}

void SkyLines::addAirport(const Node &node, int index) {
    this->graph.addNode(node, index);
}

void SkyLines::addFlight(int origin, int destination, vector<string> companies) {
    this->graph.addEdge(origin, destination, std::move(companies));
}

void SkyLines::createAirports() {

    string filename = "airports,csv";
    ifstream file;
    file.open(filename);
    int index = 0;

    string line;
    getline(file,line);

    while (getline(file,line)){
        /*
        Coordinate coordinate = {(double)line[4], (double)line[5]};
        airport airport = {line[0], line[1], line[2], line[3], line[4]};
        airports.insert({index, airport});
         */
        cout<< line[0] << endl;
        index++;
    }



}

void SkyLines::createFlights() {
    //TODO read the flights file and add the flights to the unordered map
}

void SkyLines::createAirlines() {
    //TODO read the airlines file and add the airlines to the unordered map
}