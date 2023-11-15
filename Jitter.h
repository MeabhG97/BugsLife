#ifndef JITTER_H
#define JITTER_H

#include <SFML/Graphics.hpp>

#include "Bug.h"

class Jitter : public Bug {
    public:
        Jitter();
        void move();
        bool isWayBlocked();
        ~Jitter();
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif