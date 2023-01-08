#include "Menu.h"

/**
 * Menu numbers
 */
    const int Menu::MAIN_MENU = 0;
        const int Menu::COORD_TYPE_MENU = 1;
            const int Menu::AIRPORT_MENU = 2;
            const int Menu::CITY_MENU = 3;
            const int Menu::COORDINATE_MENU = 4;
        const int Menu::SEARCH_DEFINITIONS_MENU = 5;
            const int Menu::DISABLE_MENU = 6;
                const int Menu::DISABLE_AIRPORT_MENU = 7;
                const int Menu::DISABLE_AIRLINE_MENU = 8;
            const int Menu::ENABLE_MENU = 9;
                const int Menu::ENABLE_AIRPORT_MENU = 10;
                const int Menu::ENABLE_AIRLINE_MENU = 11;
            const int Menu::CHANGE_MAX_AIRPORTS = 12;
        const int Menu::GENERAL_INFO_MENU = 13;
            const int Menu::AIRPORT_CODE_SEARCH = 14;
            const int Menu::AIRLINE_CODE_SEARCH = 15;
            const int Menu::AIRPORT_CITY_SEARCH = 16;
            const int Menu::INFO_FROM_AIRPORT = 17;
            const int Menu::LIST_AIRPORTS= 18;
            const int Menu::LIST_AIRLINES = 19;

Menu::Menu() {
    this->menuState.push(MAIN_MENU);
    system("clear");
    getMenu();
}

void Menu::getMenu() {
    if(!menuState.empty()){
        switch(menuState.top()) {

            case 0: mainMenu(); break;
                case 1: coordTypeMenu(); break;
                    case 2: airportInputMenu(); break;
                    case 3: cityInputMenu(); break;
                    case 4: coordInputMenu(); break;
                case 5: searchDefinitionsMenu(); break;
                    case 6: disableMenu(); break;
                        case 7: disableAirportMenu(); break;
                        case 8: disableAirlineMenu(); break;
                    case 9: enableMenu(); break;
                        case 10: enableAirportMenu(); break;
                        case 11: enableAirlineMenu(); break;
                    case 12: changeMaxStops(); break;
                case 13: GeneralInfoMenu(); break;
                    case 14: airportCodeSearch(); break;
                    case 15: airlineCodeSearch(); break;
                    case 16: airportCitySearch(); break;
                    case 17: infoFromAirport(); break;
                    case 18: listAirports(); break;
                    case 19: listAirlines(); break;
        }
    }
    else{
        //exits from the entire program
        //(return only returns from the function)
        exit(0);
    }
}

void Menu::mainMenu() {
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│              SkyLines              │" << endl;
    cout << "├────────────────────────────────────┤" << endl;
    cout << "│  1 - Find Flight                   │" << endl;
    cout << "│  2 - Search Settings               │" << endl;
    cout << "│  3 - General Information           │" << endl;
    cout << "│  4 - Exit                          │" << endl;
    cout << "└────────────────────────────────────┘" << endl;

    do {
        cout << "   Option > ";
        cin >> option;
        if(option < 1 || option > 4){
            cout << "   Invalid option! Please try again! " << endl;
        }
        cin.clear();
        cin.ignore(INT64_MAX, '\n');
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


void Menu::coordTypeMenu() {

        cout << "┌────────────────────────────────────┐" << endl;
        cout << "│             Find Flight            │" << endl;
        cout << "├────────────────────────────────────┤" << endl;
        cout << "│  1 - By Airport                    │" << endl;
        cout << "│  2 - By City                       │" << endl;
        cout << "│  3 - By Coordinates                │" << endl;
        cout << "│  4 - Go Back                       │" << endl;
        cout << "└────────────────────────────────────┘" << endl;

        do {
            cout << "   Option > ";
            cin >> option;
            if(option < 1 || option > 4){
                cout << "   Invalid option! Please try again! " << endl;
            }
            cin.clear();
            cin.ignore(INT64_MAX, '\n');
        } while(option < 1 || option > 4);

    //clear the console
    system("clear");

    switch(option){
        case 1: menuState.push(AIRPORT_MENU); break;
        case 2: menuState.push(CITY_MENU); break;
        case 3: menuState.push(COORDINATE_MENU); break;
        case 4: default: menuState.pop(); break;
    }

    getMenu();
}

void Menu::airportInputMenu() {
    string departureAirport, arrivalAirport;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│             Find Flight            │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Departure Airport Code > ";
    cin >> departureAirport;
    cout << "   Arrival Airport Code > ";
    cin >> arrivalAirport;

    transform(departureAirport.begin(), departureAirport.end(), departureAirport.begin(), ::toupper);
    transform(arrivalAirport.begin(), arrivalAirport.end(), arrivalAirport.begin(), ::toupper);

    cout << endl;
    skyLines.findRoute(departureAirport, arrivalAirport);

    cin.clear();
    cin.ignore(INT64_MAX, '\n');
    cout << "\n   PRESS ENTER TO CONTINUE";
    cin.get();

    system("clear");
    menuState.pop();
    menuState.pop();
    getMenu();
}

void Menu::cityInputMenu() {
    string departureCity, arrivalCity, departureCountry, arrivalCountry;
    Node departureNode, arrivalNode;

    //departure

    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│             Find Flight            │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Departure Country > ";
    getline(cin, departureCountry);
    cout << "   Departure City > ";
    getline(cin, departureCity);

    transform(departureCity.begin(), departureCity.end(), departureCity.begin(), ::toupper);
    transform(departureCountry.begin(), departureCountry.end(), departureCountry.begin(), ::toupper);

    departureNode = skyLines.getAirport(departureCity, departureCountry);

    cout << endl;

    if(departureNode.name == ""){
        menuState.pop();
        menuState.pop();
        getMenu();
    }

    //arrival
    cout << "   Arrival Country > ";
    getline(cin, arrivalCountry);
    cout << "   Arrival City > ";
    getline(cin, arrivalCity);

    transform(arrivalCity.begin(), arrivalCity.end(), arrivalCity.begin(), ::toupper);
    transform(arrivalCountry.begin(), arrivalCountry.end(), arrivalCountry.begin(), ::toupper);

    arrivalNode = skyLines.getAirport( arrivalCity, arrivalCountry);

    cout << endl;

    skyLines.findRoute(departureNode.code, arrivalNode.code);

    cout << endl;
    cout << "   PRESS ENTER TO CONTINUE" << endl;
    cin.get();

    system("clear");
    menuState.pop();
    getMenu();
}

void Menu::coordInputMenu() {
    double departureLatitude, departureLongitude, arrivalLatitude, arrivalLongitude;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│             Find Flight            │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Departure Latitude: ";
    cin >> departureLatitude;
    cout << "   Departure Longitude: ";
    cin >> departureLongitude;

    cout << endl;

    cout << "   Arrival Latitude: ";
    cin >> arrivalLatitude;
    cout << "   Arrival Longitude: ";
    cin >> arrivalLongitude;

    Coordinate departureCoord = {departureLatitude, departureLongitude};
    Coordinate arrivalCoord = {arrivalLatitude, arrivalLongitude};

    //find route by coordenates
    skyLines.setMaxDistance(distanceInputMenu());

    cout << endl;

    skyLines.findRoute(departureCoord, arrivalCoord);

    cout << endl;
    cout << "   PRESS ENTER TO CONTINUE" << endl;
    cin.ignore(INT64_MAX, '\n');
    cin.get();

    //return to the main menu
    system("clear");
    menuState.pop();
    menuState.pop();
    getMenu();
}

int Menu::distanceInputMenu() {
    int maxDistance;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│  Search airports within a radius   │"<< endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Search airports within a radius." << endl;
    cout << "   Maximum Radius (Km) > ";

    cin >> maxDistance;

    return maxDistance;
}

void Menu::searchDefinitionsMenu() {

    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│           Search Settings          │" << endl;
    cout << "├────────────────────────────────────┤" << endl;
    cout << "│  1 - Disable Airports or Airlines  │" << endl;
    cout << "│  2 - Enable Airports or Airlines   │" << endl;
    cout << "│  3 - Change Max Airports           │" << endl;
    cout << "│  4 - Reset Search Settings         │" << endl;
    cout << "│  5 - Go Back                       │" << endl;
    cout << "└────────────────────────────────────┘" << endl;

    do {
        cout << "   Option > ";
        cin >> option;
        if(option < 1 || option > 5){
            cout << "   Invalid option! Please try again! " << endl;
        }

        cin.clear();
        cin.ignore(INT64_MAX, '\n');

    } while(option < 1 || option > 5);

    cout << endl;
    //clear the console
    system("clear");

    switch(option){
        case 1: menuState.push(DISABLE_MENU); break;
        case 2: menuState.push(ENABLE_MENU); break;
        case 3: menuState.push(CHANGE_MAX_AIRPORTS); break;
        case 4: menuState.pop(); skyLines.reset(); break;
        case 5: default: menuState.pop(); break;
    }

    getMenu();
}

void Menu::disableMenu() {
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│           Disable Options          │" << endl;
    cout << "├────────────────────────────────────┤" << endl;
    cout << "│  1 - Disable Airport               │" << endl;
    cout << "│  2 - Disable Airline               │" << endl;
    cout << "│  3 - Disable All Airports          │" << endl;
    cout << "│  4 - Disable All Airlines          │" << endl;
    cout << "│  5 - Go Back                       │" << endl;
    cout << "└────────────────────────────────────┘" << endl;

    do {
        cout << "   Option > ";
        cin >> option;
        if(option < 1 || option > 5){
            cout << "   Invalid option! Please try again!" << endl;
        }
        cin.clear();
        cin.ignore(INT64_MAX, '\n');

    } while(option < 1 || option > 5);

    cout << endl;
    //clear the console
    system("clear");

    switch(option){
        case 1: menuState.push(DISABLE_AIRPORT_MENU); break;
        case 2: menuState.push(DISABLE_AIRLINE_MENU); break;
        case 3: skyLines.changeAllAirportState(false); break;
        case 4: skyLines.changeAllAirlineState(false); break;
        case 5: default: menuState.pop(); break;
    }
    getMenu();
}


void Menu::disableAirportMenu() {
    string airportCode;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│           Disable Airport          │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Airport Code > ";
    cin >> airportCode;

    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    while (skyLines.getAirport(airportCode).code == "") {
        cout << endl;
        cout << "   Invalid Airport Code!" << endl;
        cout << "   Airport Code > ";
        cin >> airportCode;

        cin.clear();
        cin.ignore(INT64_MAX, '\n');
    }

    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    skyLines.changeAirportState(airportCode, false);

    cout << "   Airport " << airportCode << " disabled!" << endl;

    cout << "\n   PRESS ENTER TO CONTINUE" << endl;
    cin.get();
    cin.ignore(INT64_MAX, '\n');

    //Go back to main menu
    system("clear");
    menuState.pop();
    menuState.pop();
    getMenu();
}

void Menu::disableAirlineMenu() {
    string airlineCode;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│           Disable Airline          │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Airline Code > ";
    cin >> airlineCode;

    transform(airlineCode.begin(), airlineCode.end(), airlineCode.begin(), ::toupper);

    while (skyLines.getAirline(airlineCode).name == "") {
        cout << endl;
        cout << "   Invalid Airline Code!" << endl;
        cout << "   Airline Code > ";
        cin >> airlineCode;

        cin.clear();
        cin.ignore(INT64_MAX, '\n');
    }

    //transform code to uppercase
    transform(airlineCode.begin(), airlineCode.end(), airlineCode.begin(), ::toupper);

    skyLines.changeAirlineState(airlineCode, false);

    cout << "   Airline " << airlineCode << " disabled!" << endl;

    cout << "\n   PRESS ENTER TO CONTINUE" << endl;
    cin.get();
    cin.ignore(INT64_MAX, '\n');

    //Go back to main menu
    system("clear");
    menuState.pop();
    menuState.pop();
    getMenu();
}

void Menu::enableMenu() {
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│           Enable Options           │" << endl;
    cout << "├────────────────────────────────────┤" << endl;
    cout << "│  1 - Enable Airport                │" << endl;
    cout << "│  2 - Enable Airline                │" << endl;
    cout << "│  3 - Enable All Airports           │" << endl;
    cout << "│  4 - Enable All Airlines           │" << endl;
    cout << "│  5 - Go Back                       │" << endl;
    cout << "└────────────────────────────────────┘" << endl;

    do {
        cout << "   Option > ";
        cin >> option;
        if(option < 1 || option > 5){
            cout << "   Invalid option! Please try again!" << endl;
        }
        cin.clear();
        cin.ignore(INT64_MAX, '\n');

    } while(option < 1 || option > 5);

    cout << endl;
    //clear the console
    system("clear");

    switch(option){
        case 1: menuState.push(ENABLE_AIRPORT_MENU); break;
        case 2: menuState.push(ENABLE_AIRLINE_MENU); break;
        case 3: skyLines.changeAllAirportState(true); break;
        case 4: skyLines.changeAllAirlineState(true); break;
        case 5: default: menuState.pop(); break;
    }
    getMenu();
}

void Menu::enableAirlineMenu() {
    string airlineCode;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│           Enable Airline           │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Airline Code > ";
    cin >> airlineCode;

    transform(airlineCode.begin(), airlineCode.end(), airlineCode.begin(), ::toupper);

    while (skyLines.getAirline(airlineCode).name == "") {
        cout << "   Invalid Airline Code!" << endl;
        cout << "   Airline Code > ";
        cin >> airlineCode;

        cin.clear();
        cin.ignore(INT64_MAX, '\n');
    }

    //transform code to uppercase
    transform(airlineCode.begin(), airlineCode.end(), airlineCode.begin(), ::toupper);

    skyLines.changeAirlineState(airlineCode, true);

    cout << "   Airline " << airlineCode << " enabled!" << endl;

    cout << "\n   PRESS ENTER TO CONTINUE" << endl;
    cin.get();
    cin.ignore(INT64_MAX, '\n');

    system("clear");
    menuState.pop();
    menuState.pop();
    getMenu();
}

void Menu::enableAirportMenu() {
    string airportCode;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│           Enable Airport           │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Airport Code > ";
    cin >> airportCode;

    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    while (skyLines.getAirport(airportCode).code == "") {
        cout << endl;
        cout << "   Invalid Airport Code!" << endl;
        cout << "   Airport Code > ";
        cin >> airportCode;

        cin.clear();
        cin.ignore(INT64_MAX, '\n');
    }

    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    skyLines.changeAirportState(airportCode, true);

    cout << "   Airport " << airportCode << " enabled!" << endl;

    cout << "\n   PRESS ENTER TO CONTINUE" << endl;
    cin.get();
    cin.ignore(INT64_MAX, '\n');

    //Go back to main menu
    system("clear");
    menuState.pop();
    menuState.pop();
    getMenu();
}

void Menu::changeMaxStops() {
    int max;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│         Change Max Airports        │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Max number of airports" << endl << "   that you want to stop at > ";
    cin >> max;
    while (max <= 1) {
        cin.clear();
        cin.ignore(INT64_MAX, '\n');
        cout << "   Min number of airports that can be in a flight path is 2!" << endl;
        cout << "   Max number of airports that you want to stop at > ";
        cin >> max;
    }

    skyLines.setMaxAirports(max);
    cout << endl;

    cout << "   Max number of airports changed to " << max << "!" << endl;

    cout << "\n   PRESS ENTER TO CONTINUE" << endl;
    cin.get();
    cin.ignore(INT64_MAX, '\n');

    //Go back to main menu
    system("clear");
    menuState.pop();
    menuState.pop();
    getMenu();

}

void Menu::GeneralInfoMenu() {
    int option;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│         General Information        │" << endl;
    cout << "├────────────────────────────────────┤" << endl;
    cout << "│  1 - Search By Airport Code        │" << endl;
    cout << "│  2 - Search By Airline Code        │" << endl;
    cout << "│  3 - Search Airport By City        │" << endl;
    cout << "│  4 - Reachables from Airport       │" << endl;
    cout << "│  5 - List All Airports             │" << endl;
    cout << "│  6 - List All Airlines             │" << endl;
    cout << "│  7 - Go Back                       │" << endl;
    cout << "└────────────────────────────────────┘" << endl;

    do {
        cout << "   Option > ";
        cin >> option;
        if(option < 1 || option > 7){
            cout << "   Invalid option! Please try again!" << endl;
        }
        cin.clear();
        cin.ignore(INT64_MAX, '\n');
    } while(option < 1 || option > 7);

    cout << endl;

    //clear the console
    system("clear");

    switch(option){
        case 1: menuState.push(AIRPORT_CODE_SEARCH); break;
        case 2: menuState.push(AIRLINE_CODE_SEARCH); break;
        case 3: menuState.push(AIRPORT_CITY_SEARCH); break;
        case 4: menuState.push(INFO_FROM_AIRPORT); break;
        case 5: menuState.push(LIST_AIRPORTS); break;
        case 6: menuState.push(LIST_AIRLINES); break;
        case 7: default: menuState.pop(); break;

    }
    getMenu();
}


void Menu::airportCodeSearch() {
    string airportCode;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│         Airport Information        │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Airport Code > ";
    cin >> airportCode;

    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    while (skyLines.getAirport(airportCode).code == "") {
        cin.clear();
        cin.ignore(INT64_MAX, '\n');
        cout << endl;
        cout << "   Invalid Airport Code!" << endl;
        cout << "   Airport Code > ";
        cin >> airportCode;

        transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);
    }
    cout << endl;

    system("clear");

    skyLines.getAirport(airportCode).printInfo();

    cin.ignore(INT64_MAX, '\n');

    cout << "\n   PRESS ENTER TO CONTINUE" << endl;
    cin.get();

    system("clear");
    menuState.pop();
    getMenu();
}

void Menu::airlineCodeSearch() {
    string airlineCode;
    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│         Airline Information        │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Airline Code > ";
    cin >> airlineCode;

    transform(airlineCode.begin(), airlineCode.end(), airlineCode.begin(), ::toupper);

    while (skyLines.getAirline(airlineCode).name == "") {
        cin.clear();
        cin.ignore(INT64_MAX, '\n');
        cout << endl;
        cout << "   Invalid Airline Code!" << endl;
        cout << "   Airline Code > ";
        cin >> airlineCode;

        transform(airlineCode.begin(), airlineCode.end(), airlineCode.begin(), ::toupper);

    }
    cout << endl;

    system("clear");

    cout << "┌───────────────────────────────────────────────────┐" << endl;
    cout << "│                      Airline                      │" << endl;
    cout << "├───────────────────────────────────────────────────┤" << endl;
    cout << "│  Code : " << left << setw(42) << airlineCode << "│" << endl;
    skyLines.getAirline(airlineCode).printInfo();

    cin.ignore(INT64_MAX, '\n');

    cout << "\n   PRESS ENTER TO CONTINUE" << endl;
    cin.get();

    system("clear");
    menuState.pop();
    getMenu();
}

void Menu::airportCitySearch() {

    string city, country;
    char option = 'Y';

    while (option == 'Y' || option == 'y') {
        cout << "┌────────────────────────────────────┐" << endl;
        cout << "│         Airport Information        │" << endl;
        cout << "└────────────────────────────────────┘" << endl;
        cout << "   Country > ";
        getline(cin, country);
        cout << "   City > ";
        getline(cin, city);

        transform(city.begin(), city.end(), city.begin(), ::toupper);
        transform(country.begin(), country.end(), country.begin(), ::toupper);

        Node airport = skyLines.getAirport(city, country);
        if (airport.code == "") {
            cout << endl;
            cout << "   Try again? (Y/N) > ";
            cin >> option;


        } else {
            system("clear");
            airport.printInfo();
            cout << "\n   PRESS ENTER TO CONTINUE" << endl;
            cin.get();
            break;
        }

        cin.clear();
        cin.ignore(INT64_MAX, '\n');
    }

    system("clear");
    menuState.pop();
    getMenu();
}

void Menu::listAirports() {
    int page = 1;
    vector<Node> nodes = skyLines.getAirports();
    int numPages = nodes.size() / 20 + (nodes.size() % 20 != 0);

    while (page < numPages + 1 && page > 0) {
        string spa = "│ page: " + to_string(page) + " of " + to_string(numPages);
        cout << "┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
        cout << "│                                                            List Airports                                                           │" << endl;
        cout << "├────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤" << endl;
        cout << left << setw(135) << spa << "│" << endl;
        cout << "├────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤" << endl;
        cout << "│  Code   Name                                                   City                             Country                            │" << endl;
        cout << "│  ----   ----                                                   ----                             -------                            │" << endl;

        for (auto idx = nodes.begin() + ((page - 1) * 20); idx != nodes.begin() + (page * 20); idx++) {
            cout << "│  " << left << setw(5) << idx->code << "  " << left << setw(53) << idx->name << "  " << left << setw(31) << idx->city << "  " << left << setw(33) << idx->country << "  │" << endl;
        }

        cout << "│  ----   ----                                                   ----                             -------                            │" << endl;
        cout << "└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
        cout << "   Insert the number of the page or " << numPages + 1 << " to go back > ";
        cin >> page;
        cout << endl;

        cin.clear();
        cin.ignore(INT64_MAX, '\n');

        system("clear");
    }

    menuState.pop();
    getMenu();
}



void Menu::listAirlines(){
    int page = 1;
    int numpages;
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

    while (page < numpages + 1 && page > 0) {
        string spa = "│ page: " + to_string(page) + " of " + to_string(numpages);
        cout << "┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
        cout << "│                                                       List Airlines                                                     │" << endl;
        cout << "├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤" << endl;
        cout << left << setw(124) << spa << "│" << endl;
        cout << "├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤" << endl;
        cout << "│  Code   Name                                         Callsign                    Country                                │" << endl;
        cout << "│  ----   ----                                         --------                    -------                                │" << endl;

        for (auto idx = airlines.begin() + ((page - 1) * 20); idx != (airlines.begin() + (page * 20)) && idx != airlines.end(); idx++) {
            cout << "│  " << left << setw(5) << idx->code << "  " << left << setw(43) << idx->airline.name << "  " << left << setw(26) << idx->airline.callsign << "  " << left << setw(37) << idx->airline.country << "  │" << endl;
        }

        cout << "│  ----   ----                                         --------                    -------                                │" << endl;
        cout << "└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
        cout << "   Insert the number of the page or " << numpages + 1 << " to go back > ";
        page = 0;
        cin >> page;
        cout << endl;

        cin.clear();
        cin.ignore(INT64_MAX, '\n');

        system("clear");
    }

    menuState.pop();
    getMenu();
}

void Menu::infoFromAirport() {
    string airportCode;
    int maxAirports;

    cout << "┌────────────────────────────────────┐" << endl;
    cout << "│      Information From Airport      │" << endl;
    cout << "└────────────────────────────────────┘" << endl;
    cout << "   Airport code > ";
    cin >> airportCode;

    transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);

    while (skyLines.getAirport(airportCode).code == "") {
        cin.clear();
        cin.ignore(INT64_MAX, '\n');
        cout << endl;
        cout << "   Invalid Airport Code!" << endl;
        cout << "   Airport Code > ";
        cin >> airportCode;

        transform(airportCode.begin(), airportCode.end(), airportCode.begin(), ::toupper);
    }
    cout << endl;
    cout << "   Max number of flights > ";
    cin >> maxAirports;

    while (maxAirports < 1) {
        cin.clear();
        cin.ignore(INT64_MAX, '\n');
        cout << "   Min number of flights has to be bigger than 1!" << endl;
        cout << "   Max number of flights > ";
        cin >> maxAirports;
    }

    auto t = skyLines.getInfoFromAirport(maxAirports, airportCode);

    system("clear");

    cout << "┌───────────────────────────────────────────────────┐" << endl;
    cout << "│             Information From Airport              │" << endl;
    cout << "├───────────────────────────────────────────────────┤" << endl;
    cout << "│  Different reachable airports: " << left << setw(19) << get<0>(t) <<  "│" << endl;
    cout << "│  Different reachable cities: " << left << setw(21) << get<1>(t) <<  "│" << endl;
    cout << "│  Different reachable countries: " << left << setw(18) <<  get<2>(t) << "│" << endl;
    cout << "└───────────────────────────────────────────────────┘" << endl;

    cout << "\n   PRESS ENTER TO CONTINUE" << endl;
    cin.ignore(INT64_MAX, '\n');
    cin.get();
    system("clear");

    menuState.pop();
    getMenu();
}
