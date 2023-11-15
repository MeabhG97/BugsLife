#include <iostream>
#include <string>

#include "Menu.h"
#include "Board.h"

void Menu::invalidArgument(){
    std::cout << "Not a valid argument" << std::endl;
}

void Menu::displayOptions(){
    std::cout << "Menu\n"
        << "1. Display all bugs\n"
        << "2. Find a bug\n"
        << "3. Tap the board\n"
        << "4. Display all bugs history\n"
        << "5. Display all cells\n"
        << "6. Run simulation\n"
        << "7. Exit\n"
        << "Enter the number of chosen option: " << std::endl;
}

void Menu::selectOption(Board& board, bool& run, int& opt, int& id){
    try{
        switch(opt) {
            case 1 : {
                board.displayAllBugs();
                break;
            }
            case 2 : {
                if(!board.findABug(id)){
                    std::cout << "Bug not found" << std::endl;
                }
                break;
            }
            case 3 : {
                board.tap();
                break;
            }
            case 4 : {
                board.displayHistory();
                break;
            }
            case 5 : {
                board.displayAllCells();
                break;
            }
            case 6 : {
                board.simulation();
                break;
            }
            case 7 : {
                run = false;
                break;
            }
            default : {
                std::cout << "Not an option" << std::endl;
            }
        }
    } catch(std::invalid_argument &ia){
        Menu::invalidArgument();
    }
}