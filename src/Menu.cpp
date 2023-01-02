#include "Menu.h"

/**
 * Menu numbers
 */
const int Menu::MAIN_MENU = 0;
const int Menu::FLIGHT_TYPE_MENU = 1;
const int Menu::COORD_TYPE_MENU = 2;
const int Menu::AIRPORT_MENU = 3;
const int Menu::CITY_MENU = 4;
const int Menu::COORDINATE_MENU = 5;
const int Menu::SEARCH_DEFINITIONS_MENU = 6;
const int Menu::GENERAL_INFO_MENU = 7;
const int Menu::AIRLINE_SELECTOR_MENU = 8;
const int Menu::AIRPORT_CODE_SEARCH = 9;
const int Menu::AIRPORT_CITY_SEARCH = 10;
const int Menu::AIRPORT_COUNTRY_SEARCH = 11;
const int Menu::LIST_AIRPORTS= 12;
const int Menu::DISABLE_AIRPORT_MENU = 13;
const int Menu::DISABLE_AIRLINE_MENU = 14;
const int Menu::LIST_AIRLINES = 15;

Menu::Menu() {
    this->menuState.push(MAIN_MENU);
    system("clear");
    getMenu();

}

void Menu::getMenu() {
    if(!menuState.empty()){
        switch(menuState.top()) {
            case 0: mainMenu(); break;
            case 1: flightTypeMenu(); break;
            case 2: coordTypeMenu(); break;
            case 3: airportInputMenu(); break;
            case 4: cityInputMenu(); break;
            case 5: coordInputMenu(); break;
            case 6: searchDefinitionsMenu(); break;
            case 7: GeneralInfoMenu(); break;
            case 8: airlineSelectorMenu(); break;
            case 9: airportCodeSearch(); break;
            case 10: airportCountrySearch(); break;
            case 11: airportCitySearch(); break;
            case 12: listAirports(); break;
            case 13: disableAirportMenu(); break;
            case 14: disableAirlineMenu(); break;
            case 15: listAirlines(); break;
        }
    }
    else{
        //exits from the entire program
        //(return only returns from the function)
        exit(0);
    }
}

void Menu::mainMenu() {
    do {

    cout << "──────────────SkyLines──────────────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "1 - Find Flight" << endl;
    cout << "2 - Search Settings" << endl;
    cout << "3 - General Information" << endl;
    cout << "4 - Exit" << endl;
    cout << "Choose an option: ";
    cin >> option;
    cout << "────────────────────────────────────" << endl;

    if(option < 1 || option > 4){
        cout << "Invalid option!" << endl;
    }

    cin.clear();
    cin.ignore(INT16_MAX, '\n');

    } while(option < 1 || option > 4);

    //clear the console
    system("clear");

    switch(option){
        case 1: menuState.push(COORD_TYPE_MENU); break;
        case 2: menuState.push(SEARCH_DEFINITIONS_MENU); break;
        case 3: menuState.push(GENERAL_INFO_MENU); break;
        case 4: default: menuState.pop(); break;
    }

    getMenu();

}

void Menu::flightTypeMenu() {
    do{
        cout << "─────────────Find Flight────────────" << endl;
        cout << "────────────────────────────────────" << endl;
        cout << "1 - One Way" << endl;
        cout << "2 - Round Trip" << endl;
        cout << "3 - Go Back" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << "────────────────────────────────────" << endl;

        if(option < 1 || option > 3){
            cout << "Invalid option!" << endl;
        }

        cin.clear();
        cin.ignore(INT16_MAX, '\n');



    } while(option < 1 || option > 3);

    //clear the console
    system("clear");

    switch(option){
        case 3: default: menuState.pop(); break;
    }

    getMenu();
}

void Menu::coordTypeMenu() {
    do{
        cout << "─────────────Find Flight────────────" << endl;
        cout << "────────────────────────────────────" << endl;
        cout << "1 - By Airport" << endl;
        cout << "2 - By City" << endl;
        cout << "3 - By Coordinates" << endl;
        cout << "4 - Go Back" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << "────────────────────────────────────" << endl;

        if(option < 1 || option > 4){
            cout << "Invalid option!" << endl;
        }

        cin.clear();
        cin.ignore(INT16_MAX, '\n');

    } while(option < 1 || option > 4);

    //clear the console
    system("clear");

    switch(option){
        case 1: menuState.push(AIRPORT_MENU); break;
        case 2: menuState.push(CITY_MENU); break;
        case 3: menuState.push(COORDINATE_MENU); break;
        case 4: default: menuState.pop(); break;
    }

    system("clear");
    getMenu();
}

void Menu::airportInputMenu() {
    string departureAirport, arrivalAirport;
    cout << "─────────────Find Flight────────────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "Departure Airport Code: ";
    cin >> departureAirport;
    cout << "Arrival Airport Code: ";
    cin >> arrivalAirport;
    cout << "────────────────────────────────────" << endl;


    transform(departureAirport.begin(), departureAirport.end(), departureAirport.begin(), ::toupper);
    transform(arrivalAirport.begin(), arrivalAirport.end(), arrivalAirport.begin(), ::toupper);

    skyLines.findRoute(departureAirport, arrivalAirport);

    menuState.pop();
    menuState.pop();
    getMenu();
}

void Menu::cityInputMenu() {
    string departureCity, arrivalCity;
    cout << "─────────────Find Flight────────────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "Departure City: ";
    cin >> departureCity;
    cout << "Arrival City: ";
    cin >> arrivalCity;
    cout << "────────────────────────────────────" << endl;

    countryInputMenu();
    //TODO
    //call the find route function

    getMenu();
}

void Menu::countryInputMenu() {

}

void Menu::coordInputMenu() {
    double departureLatitude, departureLongitude, arrivalLatitude, arrivalLongitude;
    cout << "─────────────Find Flight────────────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "Departure Latitude: ";
    cin >> departureLatitude;
    cout << "Departure Longitude: ";
    cin >> departureLongitude;
    cout << "Arrival Latitude: ";
    cin >> arrivalLatitude;
    cout << "Arrival Longitude: ";
    cin >> arrivalLongitude;
    cout << "────────────────────────────────────" << endl;

    Coordinate departureCoord = {departureLatitude, departureLongitude};
    Coordinate arrivalCoord = {arrivalLatitude, arrivalLongitude};

    //find route by coordenates
    skyLines.findRoute(departureCoord, arrivalCoord);

    //return to the main menu
    system("clear");
    menuState.pop();
    menuState.pop();
    getMenu();
}

void Menu::searchDefinitionsMenu() {
    do{
        cout << "────────────Search Settings──────────" << endl;
        cout << "─────────────────────────────────────" << endl;
        cout << "1 - Disable Airport" << endl;
        cout << "2 - Disable Airline" << endl;
        cout << "3 - Change Max Stops" << endl;
        cout << "4 - Reset Search Settings" << endl;
        cout << "5 - Go Back" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << "────────────────────────────────────" << endl;

        if(option < 1 || option > 6){
            cout << "Invalid option!" << endl;
        }

        cin.clear();
        cin.ignore(INT16_MAX, '\n');


    } while(option < 1 || option > 6);

    //clear the console
    system("clear");

    switch(option){
        case 1: menuState.push(DISABLE_AIRPORT_MENU); break;
        case 2: menuState.push(DISABLE_AIRLINE_MENU); break;
        case 3: //TODO
                break;
        case 4: menuState.pop(); skyLines.reset(); break;
        case 5: default: menuState.pop(); break;
    }

    getMenu();
}


void Menu::GeneralInfoMenu() {
    int option;
    cout << "─────────General Information─────────" << endl;
    cout << "─────────────────────────────────────" << endl;
    cout << "1 - Search by Airport Code" << endl;
    cout << "2 - " << endl;
    cout << "3 - " << endl;
    cout << "4 - List all Airports" << endl;
    cout << "5 - List all Airlines" << endl;
    cout << "6 - Go Back" << endl;
    cout << "─────────────────────────────────────" << endl;
    cin >> option;

    //clear the console
    system("clear");

    switch(option){
        case 1: menuState.push(AIRPORT_CODE_SEARCH); break;

        case 4: menuState.push(LIST_AIRPORTS); break;
        case 5: menuState.push(LIST_AIRLINES); break;
        case 6: default: menuState.pop(); break;

    }
    getMenu();
}


void Menu::airportCodeSearch() {
    string airportCode;
    cout << "──────────Airport Information───────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "Airport Code: ";
    cin >> airportCode;
    cout << "────────────────────────────────────" << endl;

    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    while (skyLines.getAirport(airportCode).code == "") {
        cout << "Invalid Airport Code!" << endl;
        cout << "Airport Code: ";
        cin >> airportCode;
        cout << "────────────────────────────────────" << endl;

        cin.clear();
        cin.ignore(INT16_MAX, '\n');
    }




    getMenu();
}

void Menu::airportCitySearch() {
    string city;
    cout << "──────────Airport Information───────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "City: ";
    cin >> city;
    cout << "────────────────────────────────────" << endl;

    //TODO
    //call the airport info function

    getMenu();
}

void Menu::airportCountrySearch() {
    string country;
    cout << "──────────Airport Information───────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "Country: ";
    cin >> country;
    cout << "────────────────────────────────────" << endl;

    //TODO
    //call the airport info function

    getMenu();
}

void Menu::listAirports() {

    int page = 1;
    string cenas = skyLines.getAirports()[0].code;
    int numpages = 0;
    if (skyLines.getAirports().size()%20 == 0) {
        numpages = skyLines.getAirports().size()/20;
    }
    else {
        numpages = skyLines.getAirports().size()/20 + 1;
    }

    vector<Node> nodes = skyLines.getAirports();

    while (page != numpages+1 && page != 0) {
        cout << "─────────────List Airports───────────" << endl;
        cout << "─────────────────────────────────────" << endl;
        cout << "page: " << page << " of " << numpages << endl;
        cout << "─────────────────────────────────────" << endl;
        cout << "Code - Name - City - Country" << endl;
        cout << "─────────────────────────────────────" << endl;
        for (auto idx = nodes.begin() + ((page-1) * 20); idx != nodes.begin() + (page*20); idx++) {
            cout << idx->code << " - " << idx->name << " - " << idx->city << " - " << idx->country << endl;
        }
        cout << "─────────────────────────────────────" << endl;
        cout << "Insert the number of the page or " << numpages+1 << " to go back: " << endl;
        cin >> page;

        cin.clear();
        cin.ignore(INT16_MAX, '\n');

        system("clear");
    }

    menuState.pop();
    getMenu();
}

void Menu::disableAirportMenu() {
    string airportCode;
    cout << "──────────Disable Airport───────────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "Airport Code: ";
    cin >> airportCode;
    cout << "────────────────────────────────────" << endl;

    //transform to uppercase
    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    while (skyLines.getAirport(airportCode).code == "") {
        cout << "Invalid Airport Code!" << endl;
        cout << "Airport Code: ";
        cin >> airportCode;
        cout << "────────────────────────────────────" << endl;

        cin.clear();
        cin.ignore(INT16_MAX, '\n');
    }

    skyLines.disableAirport(airportCode);

    cout << "Airport disabled!" << endl;

    //Go back to main menu
    menuState.pop();
    menuState.pop();
    getMenu();
}

void Menu::disableAirlineMenu() {
    string airlineCode;
    cout << "──────────Disable Airline───────────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "Airline Code: ";
    cin >> airlineCode;
    cout << "────────────────────────────────────" << endl;

    //transform code to uppercase
    transform(airlineCode.begin(), airlineCode.end(), airlineCode.begin(), ::toupper);

    while (skyLines.getAirline(airlineCode).name == "") {
        cout << "Invalid Airline Code!" << endl;
        cout << "Airline Code: ";
        cin >> airlineCode;
        cout << "────────────────────────────────────" << endl;

        cin.clear();
        cin.ignore(INT16_MAX, '\n');
    }

    skyLines.disableAirline(airlineCode);

    cout << "Airline disabled!" << endl;

    //Go back to main menu
    menuState.pop();
    menuState.pop();
    getMenu();
}

void Menu::listAirlines(){
    int page = 1;
    int numpages = 0;
    auto companies = skyLines.getCompanies();
    numpages = companies.size() % 20 == 0 ? companies.size() / 20 : (companies.size() / 20 + 1);

    struct help{
        string code;
        Airline airline;
    };

    vector<help> airlines;

    for (const auto& e: companies){
        airlines.push_back({e.first, e.second});
    }

    while (page != numpages+1 && page != 0) {
        cout << "─────────────List Airlines───────────" << endl;
        cout << "─────────────────────────────────────" << endl;
        cout << "page: " << page << " of " << numpages << endl;
        cout << "─────────────────────────────────────" << endl;
        cout << "Code - Name - Callsign - Country" << endl;
        cout << "─────────────────────────────────────" << endl;

        for (int i = (page - 1) * 20; i < page * 20; i++){
            cout << airlines[i].code << " - " << airlines[i].airline.name << " - " << airlines[i].airline.callsign
                 << " - " << airlines[i].airline.country << endl;
        }

        cout << "─────────────────────────────────────" << endl;
        cout << "Insert the number of the page or " << numpages+1 << " to go back: " << endl;
        cin >> page;

        cin.clear();
        cin.ignore(INT16_MAX, '\n');

        system("clear");
    }

    menuState.pop();

    getMenu();
}
