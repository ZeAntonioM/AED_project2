#include "SkyLines.h"

const int SkyLines::NUMBER_AIRPORTS = 3019;
const string SkyLines::AIRLINES = "../data/airlines.csv";
const string SkyLines::AIRPORTS = "../data/airports.csv";
const string SkyLines::FLIGHTS = "../data/flights.csv";

SkyLines::SkyLines() : graph(NUMBER_AIRPORTS), maxAirports(NUMBER_AIRPORTS) {
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
            nodes[airports[Source]].hashMapEdges[airports[Target]].airlines.insert(Airline);

        } else {
            unordered_set<string> airlines;
            airlines.insert(Airline);
            nodes[airports[Source]].hashMapEdges[airports[Target]] = {airports[Target], airlines, {}};
        }

    }
    graph.setNodes(nodes);
}

void SkyLines::findRoute(const Coordinate &origin, const Coordinate &destination) {
    vector<Node> departureAirports = graph.getNode(origin, maxDistance);
    vector<Node> arrivalAirports = graph.getNode(destination, maxDistance);

    if(departureAirports.empty() || arrivalAirports.empty()){
        cout << "   No airports found in the given radius" << endl;
        return;
    }
    if(departureAirports.size() > 1){
        int option;
        do {
            cout << endl;
            cout << "   ";
            for (int i = 1; i <= departureAirports.size(); i++) {
                cout << "   [" << i << "] -> " << departureAirports[i - 1].code << endl;
            }
            cout << endl;
            cout << "   Choose the departure airport: ";
            cin >> option;

            if(option < 1 || option > departureAirports.size()){
                cout << "   Invalid option" << endl;
            }

            cin.ignore(INT16_MAX, '\n');

        }while(option < 1 || option > departureAirports.size());

        departureAirports = {departureAirports[option-1]};

    }
    if(arrivalAirports.size() > 1){
        int option;
        do {
            cout << "   " << endl;
            for (int i = 1; i <= arrivalAirports.size(); i++) {
                cout << "   [" << i << "] -> " << arrivalAirports[i - 1].code << endl;
            }
            cout << endl;
            cout << "   Choose the arrival airport: ";
            cin >> option;

            if(option < 1 || option > arrivalAirports.size()){
                cout << "   Invalid option" << endl;
            }

            cin.ignore(INT16_MAX, '\n');

        }while(option < 1 || option > arrivalAirports.size());

        arrivalAirports = {arrivalAirports[option-1]};
    }

    findRoute(departureAirports[0].code, arrivalAirports[0].code);
}

void SkyLines::findRoute(const string &originAirport, const string &destinationAirport) {

    if(airports.find(originAirport) == airports.end() || airports.find(destinationAirport) == airports.end()){
        cout << "   Invalid airport code!" << endl;
        return;
    }

    vector<Node> path = graph.generateFlightPath(airports[originAirport], airports[destinationAirport]);

    if(path.empty() || path.size() > maxAirports){
        cout << "   No route found!" << endl;
        return;
    }

    cout << "   Route: ";
    for(int i = 0; i < path.size()-1; i++){
        cout << path[i].code << " -> ";
    }
    cout << path[path.size()-1].code << endl;

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

void SkyLines::reset() {
    vector<Node> nodes = graph.getNodes();
    for(int i = 0; i < nodes.size(); i++){
        nodes[i].disabled = false;
    }

    maxAirports = NUMBER_AIRPORTS;

}

Airline SkyLines::getAirline(const string &code) {
    return companies.find(code) != companies.end() ? companies[code] : Airline();
}

void SkyLines::changeAirportState(const std::string &code, const bool &enable) {
    if(airports.find(code) != airports.end()){
        if (enable){
            graph.enableAirport(airports[code]);
        }
        else{
            graph.disableAirport(airports[code]);
        }
    } else {
        cout << "   Airport not found" << endl;
    }
}

void SkyLines::changeAirlineState(const string &code, const bool &enable) {
    if(companies.find(code) != companies.end()){
        if (enable)
            graph.enableAirline(code);
        else
            graph.disableAirline(code);
    } else {
        cout << "   Airline not found" << endl;
    }
}

void SkyLines::changeAllAirportState(const bool &enable) {
    if (enable) {
        for (auto n: airports) {
            graph.enableAirport(n.second);
        }
        cout << "   Enabled all airports!" << endl;
    }
    else{
        for (auto n: airports) {
            graph.disableAirport(n.second);
        }
        cout << "   Disabled all airports!" << endl;
    }
}

void SkyLines::changeAllAirlineState(const bool &enable) {
    if (enable) {
        for (auto n: companies) {
            graph.enableAirline(n.first);
        }
        cout << "   Enabled all airlines!" << endl;
    }
    else{
        for (auto n: companies) {
            graph.disableAirline(n.first);
        }
        cout << "   Disabled all airlines!" << endl;
    }
}


Node SkyLines::getAirport(const string &city, const string &country) {
    vector<Node> possibleAirports ={};

    vector<Node> nodes = graph.getNodes();

    for(auto airport : airports){
        Node current = nodes[airport.second];

        string currentCity = current.city;
        string currentCountry = current.country;

        transform(currentCity.begin(), currentCity.end(), currentCity.begin(), ::toupper);
        transform(currentCountry.begin(), currentCountry.end(), currentCountry.begin(), ::toupper);

        if(currentCity == city && currentCountry == country){
            possibleAirports.push_back(current);
        }

    }

    if(possibleAirports.empty()){
        cout << "   Airport not found" << left << setw(38)<< endl;
        return Node();

    }
    else if(possibleAirports.size() == 1){
        return possibleAirports[0];
    }
    else {
        int option;
        do {
            cout << "   " << endl;
            for (int i = 1; i <= possibleAirports.size(); i++) {
                cout << "   [" << i << "] -> " << possibleAirports[i - 1].code << endl;
            }
            cout << endl;
            cout << "   Choose the airport: ";
            cin >> option;

            if (option < 1 || option > possibleAirports.size()) {
                cout << "   Invalid option" << endl;
            }

            cin.ignore(INT16_MAX, '\n');
        }
        while (option < 1 || option > possibleAirports.size());

        return possibleAirports[option-1];
    }
}

void Airline::printInfo() const {
    cout << "   Name: " << name << endl;
    cout << "   Call Sign: " << callsign << endl;
    cout << "   Country: " << country << endl;
}

void SkyLines::setMaxAirports(int maxAirports) {
    this->maxAirports = maxAirports;
}

void SkyLines::setMaxDistance(int maxDistance) {
    this->maxDistance = maxDistance;
}