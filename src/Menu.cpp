#include "Menu.h"

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

    /*if(option < 1 || option > 3){
        cout << "Invalid option!" << endl;
    }*/

    cin.clear();
    cin.ignore(1000, '\n');

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

    //TODO
    //call the find route function

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
        cout << "5 - Go Back" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << "────────────────────────────────────" << endl;

        if(option < 1 || option > 5){
            cout << "Invalid option!" << endl;
        }

    } while(option < 1 || option > 5);



    getMenu();
}

void Menu::airportInfoMenu() {
    string airportCode;
    cout << "──────────Airport Information────────" << endl;
    cout << "────────────────────────────────────" << endl;
    cout << "Airport Code: ";
    cin >> airportCode;
    cout << "────────────────────────────────────" << endl;

    //TODO
    //call the airport info function

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

    } while(option < 1 || option > 3);

    switch(option){
        case 3: default: menuState.pop(); break;
    }

    getMenu();
}

