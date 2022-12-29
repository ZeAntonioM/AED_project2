#include "SkyLines.h"

#include <utility>

const string SkyLines::AIRLINES = "../data/airlines.csv";
const string SkyLines::AIRPORTS = "../data/airports.csv";
const string SkyLines::FLIGHTS = "../data/flights.csv";

SkyLines::SkyLines() : graph(NUMBER_AIRPORTS) {

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

    ifstream file;
    file.open(AIRPORTS);
    int index = 0;

    string line;
    getline(file,line);
    istringstream ss(line);

    while (getline(file,line)){

        string Code, Name, City, Country, Lat, Long;
        getline(ss, Code, ',');
        getline(ss, Name, ',');
        getline(ss, City, ',');
        getline(ss, Country, ',');
        getline(ss, Lat, ',');
        getline(ss, Long, ',');

        Coordinate coordinate = {stod(Lat), stod(Long)};
        Node node = {Code, Name, City, Country, coordinate, {}, false, 0, 0};
        addAirport(node, index);
        airports.insert({Code, index});

        index++;
    }

}

void SkyLines::createAirlines() {
    ifstream file;
    file.open(AIRLINES);

    string line;
    getline(file,line);
    istringstream ss(line);

    while (getline(file,line)){

        string Code, Name, CallSign, Country;
        getline(ss, Code, ',');
        getline(ss, Name, ',');
        getline(ss, CallSign, ',');
        getline(ss, Country, ',');

        Airline airline = {Name, CallSign, Country};
        airlines.insert({Code, airline});
    }
}

void SkyLines::createFlights() {

    ifstream file;
    file.open(FLIGHTS);
    int index = 0;

    string line;
    getline(file,line);
    istringstream ss(line);

    while (getline(file,line)){

        string Source, Target, Airline;
        getline(ss, Source, ',');
        getline(ss, Target, ',');
        getline(ss, Airline, ',');

        Node airport = graph.getNode[airports.find(Source)->second];

        vector<string> companies = {Airline};
        graph.addEdge(airports.at(Source), airports.at(Target), companies);

    }
}

void SkyLines::findRoute(const Coordinate &origin, const Coordinate &destination) {
    findRoute(graph.getNode(origin).code, graph.getNode(destination).code);
}

void SkyLines::findRoute(const string &originAirport, const string &destinationAirport) {
    auto origin = airports.find(originAirport);
    auto destination = airports.find(destinationAirport);

    //TODO
}