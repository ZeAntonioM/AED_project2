#include "SkyLines.h"

const int SkyLines::NUMBER_AIRPORTS = 3019;
const string SkyLines::AIRLINES = "../data/airlines.csv";
const string SkyLines::AIRPORTS = "../data/airports.csv";
const string SkyLines::FLIGHTS = "../data/flights.csv";

SkyLines::SkyLines() : graph(NUMBER_AIRPORTS) {
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


void SkyLines::addFlight(int origin, int destination, unordered_set<string> &airlines) {
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
        Node node = {Code, Name, City, Country, coordinate, {}, false, 0, 0, false};
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
    vector<Node> nodes = graph.getNodes(); //graph's node vector
    unordered_map<int, Edge> edges;

    while (getline(file,line)){
        istringstream ss(line);

        string Source, Target, Airline;
        getline(ss, Source, ',');
        getline(ss, Target, ',');
        getline(ss, Airline);

        airport = nodes[airports[Source]];

        edges = airport.hashMapEdges;


        if (edges.find(airports[Target]) != edges.end()){
            edges[airports[Target]].airlines.insert(Airline);

        } else {
            unordered_set<string> airlines;
            airlines.insert(Airline);
            addFlight(airports[Source], airports[Target], airlines);
        }

    }

}

void SkyLines::findRoute(const Coordinate &origin, const Coordinate &destination) {
    findRoute(graph.getNode(origin).code, graph.getNode(destination).code);
}

void SkyLines::findRoute(const string &originAirport, const string &destinationAirport) {

    if(airports.find(originAirport) == airports.end() || airports.find(destinationAirport) == airports.end()){
        cout << "Invalid airport code!" << endl;
        return;
    }

    vector<Node> path = graph.generateFlightPath(airports[originAirport], airports[destinationAirport]);

    for(int i = 0; i < path.size()-1; i++){
        cout << path[i].code << " -> ";
    }
    cout << path[path.size()-1].code << endl;



}

void SkyLines::disableAirport(const string &code) {
    if(airports.find(code) != airports.end()){
        graph.disableAirport(airports[code]);
    } else {
        cout << "Airport not found" << endl;
    }

}

unordered_map<string, Airline> SkyLines::getCompanies() const{
    return this->companies;
}

Node SkyLines::getAirport(const string &code) {
    return airports.find(code) != airports.end() ? graph.getNodes()[airports[code]] : Node();
}

vector<Node> SkyLines::getAirports(){
    return graph.getNodes();
}
