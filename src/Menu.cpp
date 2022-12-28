//
// Created by sergiopeixoto on 26-12-2022.
//

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

    if(option < 1 || option > 3){
        cout << "Invalid option!" << endl;
    }

    cin.clear();
    cin.ignore(1000, '\n');

    } while(option < 1 || option > 3);

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
        cout << "──────────────Find Flight──────────────" << endl;
        cout << "───────────────────────────────────────" << endl;
        cout << "1 - Airport" << endl;
        cout << "2 - City" << endl;
        cout << "3 - Coordinate" << endl;
        cout << "4 - Go Back" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << "───────────────────────────────────────" << endl;

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
}

