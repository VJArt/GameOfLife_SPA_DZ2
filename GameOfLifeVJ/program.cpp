#include <iostream>
#include <cstdlib> 
#include "game_of_life.h"
#include <thread>  
#include <chrono> 


#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

using namespace std;

int main() {
    game_of_life the_game;

    int choice;
    do {
        
        system(CLEAR_SCREEN);

        the_game.iscrtaj();
        the_game.sljedeca_generacija();

        cout << "1. Next generation" << endl;
        cout << "2. Run simulation automatically (WARNING: This is a forever loop, you must manually close the window)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            break; 
        case 2:
           
            while (true) {
                system(CLEAR_SCREEN);
                the_game.iscrtaj();
                the_game.sljedeca_generacija();
                this_thread::sleep_for(chrono::milliseconds(75));
            }
        case 0:
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
