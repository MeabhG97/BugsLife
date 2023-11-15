#ifndef CELL_H
#define CELL_H

#include <utility>
#include <SFML/Graphics.hpp>

#include "Bug.h"

class Cell : public sf::Drawable{
    private:
        std::pair<int, int> position;
        Bug* bug;
        bool occupied;
    public:
        Cell(int x, int y);
        Bug* getBug();
        bool isOccupied();
        std::pair<int, int> getPosition();
        void setBug(Bug*);
        void setOccupied(bool);
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
        ~Cell();
};

#endif