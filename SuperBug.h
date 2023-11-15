#ifndef SUPERBUG_H
#define SUPERBUG_H

#include <SFML/Graphics.hpp>

#include "Bug.h"

class SuperBug : public Bug{
    public:
        SuperBug();
        void move();
        bool isWayBlocked();
        void moveKeyboard(int&);
        void offBoard();
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif