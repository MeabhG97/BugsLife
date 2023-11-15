#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <mutex>
#include <SFML/Graphics.hpp>

#include "Bug.h"
#include "SuperBug.h"
#include "Cell.h"
#include "Constants.h"

class Board : public sf::Drawable{
    private:
        SuperBug* superBug;
        sf::RenderWindow* window;
        std::vector<Bug*> bugs;
        std::vector<std::vector<Cell>> cells;
        void initialiseBugs();
        void updateCells(Bug*);
        void updateCells(Bug*, Bug*);
    public:
        Board(sf::RenderWindow*);
        void displayAllBugs();
        bool findABug(int);
        void tap();
        void moveSuperBug(int&);
        void displayHistory();
        void displayAllCells();
        void simulation();
        int countAlive();
        void writeResults();
        void writeHistory();
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif