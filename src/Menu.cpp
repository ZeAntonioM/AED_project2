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
            case 1: routeTypeMenu(); break;
            case 2: coordTypeMenu(); break;
            case 3: coordInputMenu(); break;
            case 4: stopInputMenu(); break;
            case 5: searchDefinitionsMenu(); break;
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
    cout << "1 - Find Route" << endl;
    cout << "3 - Search Settings" << endl;
    cout << "3 - Exit" << endl;
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
        case 1: menuState.push(ROUTE_TYPE_MENU); break;
        case 2: menuState.push(SEARCH_DEFINITIONS_MENU); break;
        case 3:
        default: menuState.pop(); break;
    }

    getMenu();
}

