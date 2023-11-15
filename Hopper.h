#ifndef HOPPER_H
#define HOPPER_H

#include <SFML/Graphics.hpp>

#include "Bug.h"

class Hopper : public Bug{
    private:
        int hopDistance;
    public:
        Hopper();
        Hopper(std::pair<int, int>, Direction, int, std::list<std::pair<int, int>>, int);
        void move();
        bool isWayBlocked();
        int getHopLength();
        void setHopLength(int);
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
        ~Hopper();
};

#endif