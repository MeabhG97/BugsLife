#ifndef CRAWLER_H
#define CRAWLER_H

#include <SFML/Graphics.hpp>

#include "Bug.h"

class Crawler : public Bug{
    public:
        Crawler();
        Crawler(std::pair<int, int>, Direction, int, std::list<std::pair<int, int>>);
        void move();
        bool isWayBlocked();
        ~Crawler();
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif
