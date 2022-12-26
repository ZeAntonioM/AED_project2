//
// Created by sergiopeixoto on 26-12-2022.
//

#ifndef AED_PROJECT2_MENU_H
#define AED_PROJECT2_MENU_H

#include <iostream>
#include <stack>

/**
 * Menu's numbers
 */
#define MAIN_MENU 0
#define ROUTE_TYPE_MENU 1
#define COORD_TYPE_MENU 2
#define COORDINATE_MENU 3
#define STOP_MENU 4
#define SEARCH_DEFINITIONS_MENU 5

using namespace std;

class Menu {
    private:
        /**
         * @var option - user main menu option
         */
        int option;

        /**
         * @var menuState - stack used to navigate through the menu
         */
        stack<short int> menuState;

        /**
         * Function that calls the top of the menuState stack
         */
        void getMenu();

        /**
         * Main menu that allows the user to choose between the find route menu or leave the program
         */
        void mainMenu();
public:
    /**
     * Menu constructor
     */
    Menu();
};


#endif //AED_PROJECT2_MENU_H
