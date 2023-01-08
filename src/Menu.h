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
                static const int CITY_MENU;
                static const int COORDINATE_MENU;
        static const int SEARCH_DEFINITIONS_MENU;
            static const int DISABLE_MENU;
                static const int DISABLE_AIRPORT_MENU;
                static const int DISABLE_AIRLINE_MENU;
            static const int ENABLE_MENU;
                static const int ENABLE_AIRLINE_MENU;
                static const int ENABLE_AIRPORT_MENU;
            static const int CHANGE_MAX_AIRPORTS;
        static const int GENERAL_INFO_MENU;
            static const int AIRPORT_CODE_SEARCH;
            static const int AIRLINE_CODE_SEARCH;
            static const int AIRPORT_CITY_SEARCH;
            static const int INFO_FROM_AIRPORT;
            static const int LIST_AIRPORTS;
            static const int LIST_AIRLINES;


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
         * Time complexity: O(1)
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

        /**
         * Menu that finds the closest flight route from a provided departure and an arrival airport
         */
        void airportInputMenu();

        /**
         * Menu that shows all the airports of the departure and arrival cities and finds the closest flight route between them
         */
        void cityInputMenu();

        /**
         * Menu that finds the closest airports to each of the coordinates provided, and then finds the closest flight route between them
         */
        void coordInputMenu();

        /**
         * Menu used to define various search parameters for finding flights
         */
        void searchDefinitionsMenu();

        /**
         * Menu that lists all of the airports in a book-like fashion, with each page containing 20 entries
         * Time complexity: O(V), V being the number of nodes
         */
        void listAirports();

        /**
         * Menu that lists all of the airlines in a book-like fashion, with each page containing 20 entries
         * Time complexity: O(A), A being the number of airlines
         */
        void listAirlines();

        /**
         * Menu used for obtaining information about a specified airport
         */
        void airportCodeSearch();

        /**
         * Menu used for obtaining information about a specified airline
         */
        void airlineCodeSearch();

        /**
         * Menu used for choosing an airport/airline to disable
         */
        void disableMenu();

        /**
         * Menu used for disabling certain airports from being used in the calculation of flight routes
         */
        void disableAirportMenu();

        /**
         * Menu used for disabling certain airlines from being used in the calculation of flight routes
         */
        void disableAirlineMenu();

        /**
         * Menu used for choosing an airport/airline to enable
         */
        void enableMenu();

        /**
         * Menu where the user inputs the airline code to enable
         */
        void enableAirlineMenu();

        /**
         * Menu where the user inputs the airport code to enable
         */
        void enableAirportMenu();

        /**
         * Menu used to find the Airports on the same city as the one provided
         */
        void airportCitySearch();

        /**
         * Menu used to limit the number of flights that can be used in the calculation of the flight route
         */
        void changeMaxStops();

        /**
         * Menu where the user inputs the radius of the circle to search for airports.
         */
        int distanceInputMenu();

        /**
         * Menu where the user inputs the code of an airport and a desired amount of max flights, and shows how many different reachable airports, cities and countries there are
         */
        void infoFromAirport();
public:
    /**
     * Menu constructor
     */
    Menu();


};


#endif //AED_PROJECT2_MENU_H
