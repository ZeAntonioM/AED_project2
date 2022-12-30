#ifndef AED_PROJECT2_MENU_H
#define AED_PROJECT2_MENU_H

#include "SkyLines.h"

using namespace std;

class Menu {
    private:
        /**
         * Menu numbers
         */
        static const int MAIN_MENU;
        static const int FLIGHT_TYPE_MENU;
        static const int COORD_TYPE_MENU;
        static const int AIRPORT_MENU;
        static const int COORDINATE_MENU;
        static const int CITY_MENU;
        static const int SEARCH_DEFINITIONS_MENU;
        static const int AIRPORT_INFO_MENU;

        /**
         * @var SkyLines - SkyLines object containing the graph
         */
        SkyLines skyLines;

        /**
         * @var option - user main menu option
         */
        int option =0;

        /**
         * @var menuState - stack used to navigate through the menu
         */
        stack<int> menuState;

        /**
         * Function that calls the top of the menuState stack
         */
        void getMenu();

        /**
         * Main menu that allows the user to choose between the find route menu or leave the program
         */
        void mainMenu();

        /**
         * Menu that allows the user to find the best route given its criteria
         */
        void flightTypeMenu();

        /**
         * Menu to display information about an airport
         */
        void airportInfoMenu();

        /**
         * Menu that allows the user how to choose the airport (airport, city or coordinate)
         */
        void coordTypeMenu();

        void airportInputMenu();

        void cityInputMenu();

        void coordInputMenu();

        void searchDefinitionsMenu();

        void countryInputMenu();
        


public:
    /**
     * Menu constructor
     */
    Menu();

};


#endif //AED_PROJECT2_MENU_H
