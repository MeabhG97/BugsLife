#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "synchapi.h"

#include "Board.h"
#include "Menu.h"
#include "Constants.h"

int main(int, char**) {
    sf::RenderWindow window(sf::VideoMode(700, 700), "Bugs Life");
    Board* board = new Board(&window);

    bool run = true;
    bool findId = false;
    bool sim = false;
    int input = 0;
    int id = 0;

    Menu::displayOptions();

    while(run && window.isOpen()){
        window.draw(*board);
        window.display();
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                run = false;
            }
            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down ||
                    event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right){
                        input = event.key.code;
                        board->moveSuperBug(input);
                }else if(!sim){
                    input = event.key.code - KEYBOARD_NUMBER_OFFSET;
                    if(input == 2 && !findId){
                        std::cout << input << std::endl;
                        std::cout << "Enter bug id:" << std::endl;
                        findId = true;
                    } else if(findId & event.key.code != sf::Keyboard::Enter){
                        std::cout << input;
                        id = id * 10;
                        id += input;
                    } else if(findId && event.key.code == sf::Keyboard::Enter){
                        std::cout << std::endl;
                        input = 2;
                        Menu::selectOption(*board, run, input, id);
                        Menu::displayOptions();
                        id = 0;
                        findId = false;
                    }else if(input == 6 && !findId){
                        sim = true;
                        std::cout << input << std::endl;
                    } else if(input == 7){
                        std::cout << input << std::endl;
                        Menu::selectOption(*board, run, input, id);
                    } else {
                        std::cout << input << std::endl;
                        Menu::selectOption(*board, run, input, id);
                        Menu::displayOptions();
                    }
                }
            }
        }

        if(board->countAlive() <= 1 && sim){
            sim = false;
            board->writeResults();
            std::cout << "Results writtern to bugs-results.txt" << std::endl; 
            Menu::displayOptions();
        }

        if(sim){
            board->tap();
            Sleep(1000);
        }
    }
    board->writeHistory();
    std::cout << "History writtern to bugs-history.txt" << std::endl; 
}