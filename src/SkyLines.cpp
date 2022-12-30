#include "SkyLines.h"
#include <utility>

const int SkyLines::NUMBER_AIRPORTS = 3019;
const string SkyLines::AIRLINES = "../data/airlines.csv";
const string SkyLines::AIRPORTS = "../data/airports.csv";
const string SkyLines::FLIGHTS = "../data/flights.csv";

SkyLines::SkyLines() {
    graph = Graph(SkyLines::NUMBER_AIRPORTS);
    createAirports();
    createCompanies();
    createFlights();
}

SkyLines::~SkyLines() {
    this->graph.clear();
}

void SkyLines::addAirport(const Node &node, int index) {
    this->graph.addNode(node, index);
}


void SkyLines::addFlight(int origin, int destination, const unordered_set<string> &airlines) {
    this->graph.addEdge(origin, destination, airlines);
}

void SkyLines::createAirports() {

    ifstream file;
    file.open(AIRPORTS);
    int index = 0;

    string line;

    getline(file,line);

    while (getline(file,line)){
        istringstream ss(line);

        string Code, Name, City, Country, Lat, Long;
        getline(ss, Code, ',');
        getline(ss, Name, ',');
        getline(ss, City, ',');
        getline(ss, Country, ',');
        getline(ss, Lat, ',');
        getline(ss, Long);

        Coordinate coordinate = {stod(Lat), stod(Long)};
        Node node = {Code, Name, City, Country, coordinate, {}, false, 0, 0};
        addAirport(node, index);
        airports.insert({Code, index});

        index++;
    }

}

void SkyLines::createCompanies() {
    ifstream file;
    file.open(AIRLINES);

    string line;
    getline(file,line);


    while (getline(file,line)){
        istringstream ss(line);

        string Code, Name, CallSign, Country;
        getline(ss, Code, ',');
        getline(ss, Name, ',');
        getline(ss, CallSign, ',');
        getline(ss, Country, ',');

        Airline airline = {Name, CallSign, Country};
        companies.insert({Code, airline});

    }
}

void SkyLines::createFlights() {

    ifstream file;
    file.open(FLIGHTS);

    string line;
    getline(file,line);

    Node airport;
    unordered_map<int, Edge> edges;

    int index = 0;
    while (getline(file,line)){
        istringstream ss(line);

        cout << index << endl;
        string Source, Target, Airline;
        getline(ss, Source, ',');
        getline(ss, Target, ',');
        getline(ss, Airline);

        edges = airport.hashMapEdges;

        bool found = false;

        if (edges.find(airports[Target]) != edges.end()){
            edges[airports[Target]].airlines.insert(Airline);
            found = true;
        }

        if(!found){
            unordered_set<string> airlines = {Airline};
            addFlight(airports[Source], airports[Target], airlines);

        }
        index++;
    }
}

void SkyLines::findRoute(const Coordinate &origin, const Coordinate &destination) {
    findRoute(graph.getNode(origin).code, graph.getNode(destination).code);
}

void SkyLines::findRoute(const string &originAirport, const string &destinationAirport) {
    //auto origin = airports.find(originAirport);
    //auto destination = airports.find(destinationAirport);

    //TODO
}