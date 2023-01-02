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
        static const int COORD_TYPE_MENU;
        static const int AIRPORT_MENU;
        static const int COORDINATE_MENU;
        static const int CITY_MENU;
        static const int SEARCH_DEFINITIONS_MENU;
        static const int GENERAL_INFO_MENU;
        static const int AIRPORT_CODE_SEARCH;
        static const int LIST_AIRPORTS;
        static const int DISABLE_AIRPORT_MENU;
        static const int DISABLE_AIRLINE_MENU;
        static const int LIST_AIRLINES;
        static const int AIRLINE_CODE_SEARCH;

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
         * Menu to display information about an airport
         */
        void GeneralInfoMenu();

        /**
         * Menu that allows the user how to choose the airport (airport, city or coordinate)
         */
        void coordTypeMenu();

        //TODO fazer documentacao
        void airportInputMenu();
        void cityInputMenu();
        void coordInputMenu();
        void searchDefinitionsMenu();
        void countryInputMenu();
        void listAirlines();
        void airportCodeSearch();
        void listAirports();
        void disableAirportMenu();
        void disableAirlineMenu();
        void airlineCodeSearch();


public:
    /**
     * Menu constructor
     */
    Menu();


};


#endif //AED_PROJECT2_MENU_H
