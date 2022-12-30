#include "Menu.h"

/**
 * Menu numbers
 */
const int Menu::MAIN_MENU = 0;
const int Menu::FLIGHT_TYPE_MENU = 1;
const int Menu::COORD_TYPE_MENU = 2;
const int Menu::AIRPORT_MENU = 3;
const int Menu::COORDINATE_MENU = 4;
const int Menu::CITY_MENU = 5;
const int Menu::SEARCH_DEFINITIONS_MENU = 6;
const int Menu::AIRPORT_INFO_MENU = 7;
const int Menu::AIRLINE_SELECTOR_MENU = 8;


Menu::Menu() {
    this->menuState.push(MAIN_MENU);
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
            case 7: airportInfoMenu(); break;
            case 8: airlineSelectorMenu(); break;
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
    cout << "3 - Airport Information" << endl;
    cout << "4 - Exit" << endl;
    cout << "Choose an option: ";
    cin >> option;
    cout << "────────────────────────────────────" << endl;

    if(option < 1 || option > 4){
        cout << "Invalid option!" << endl;
    }

    cin.clear();
    cin.ignore(INT16_MAX, '\n');

    //clear the console
    system("clear");

    } while(option < 1 || option > 4);

    switch(option){
        case 1: menuState.push(FLIGHT_TYPE_MENU); break;
        case 2: menuState.push(SEARCH_DEFINITIONS_MENU); break;
        case 3: menuState.push(AIRPORT_INFO_MENU); break;
        case 4: default: menuState.pop(); break;
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

        //clear the console
        system("clear");


    } while(option < 1 || option > 4);

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
    cout << "─────────────Find Flight────────────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "Departure Airport Code: ";
    cin >> departureAirport;
    cout << "Arrival Airport Code: ";
    cin >> arrivalAirport;
    cout << "────────────────────────────────────" << endl;

    //TODO
    //call the find route function
    skyLines.findRoute(departureAirport, arrivalAirport);

    //return to the main menu
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

    //TODO
    //call the find route function
    //por coordenadas encontrar o airporto mais proximo
    skyLines.findRoute(departureCoord, arrivalCoord);

    //return to the main menu
    menuState.pop();
    menuState.pop();
    getMenu();
}

void Menu::airportInfoMenu() {
    string airportCode;
    cout << "──────────Airport Information───────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "Airport Code: ";
    cin >> airportCode;
    cout << "────────────────────────────────────" << endl;

    //TODO
    //call the airport info function

    getMenu();
}




void Menu::searchDefinitionsMenu() {
    do{
        cout << "────────────Search Settings──────────" << endl;
        cout << "────────────────────────────────────" << endl;
        cout << "1 - Change Max Distance" << endl;
        cout << "2 - Change Max Price" << endl;
        cout << "3 - Change Max Stops" << endl;
        cout << "4 - Change Max Time" << endl;
        cout << "5 - Change Allowed Airlines" << endl;
        cout << "6 - Go Back" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << "────────────────────────────────────" << endl;

        if(option < 1 || option > 6){
            cout << "Invalid option!" << endl;
        }

        cin.clear();
        cin.ignore(1000, '\n');

        //clear the console
        system("clear");

    } while(option < 1 || option > 6);

    switch(option){
        case 5:
            menuState.push(AIRLINE_SELECTOR_MENU);
            break;
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

        //clear the console
        system("clear");

    } while(option < 1 || option > 3);

    switch(option){
        case 3: default: menuState.pop(); break;
    }

    getMenu();
}

void Menu::countryInputMenu() {

}

void Menu::airlineSelectorMenu(){
    struct al_select{
        string name;
        bool selected;
    };

    vector<al_select> selections;
    auto comp = skyLines.getCompanies();

    for (auto it = comp.begin(); it != comp.end(); it++){
        selections.push_back({(*it).second.name, true});
    }

    int count;

    do{
        cout << "──────────Airline Selector──────────" << endl;
        count = 1;
        for (auto& e :selections){
            cout << count++ << ": [";
            if (e.selected) cout << "X";
            else cout << " ";
            cout << "] - " << e.name << endl;
        }
        cout << count << ": Go Back" << endl;
        cout << "Choose an option" << endl;
        cin >> option;
        cout << "────────────────────────────────────" << endl;

        if (option < 1 || option > count){
            cout << "Invalid Option" << endl;
        }

        else if (option != count){
            selections[option -1].selected = !selections[option-1].selected;
        }

    } while((option < 1 || option > count) || option != count);

    if (option == count) {
        menuState.pop();
        getMenu();
    }

}
