#ifndef BUG_H
#define BUG_H

#include <utility>
#include <list>
#include <SFML/Graphics.hpp>

#include "Direction.h"

class Bug : public sf::Drawable{
    protected:
        int id;
        std::pair<int, int> position;
        Direction direction;
        int size;
        bool alive;
        std::list<std::pair<int, int>> path;
        void updatePath();
        Bug* eatenBy;
    public:
        Bug();
        Bug(std::pair<int, int>, Direction, int, std::list<std::pair<int, int>>);
        virtual void move() =0;
        virtual bool isWayBlocked() =0;
        Direction newDirection();
        int getId();
        std::pair<int, int> getPosition();
        Direction* getDirection();
        int getSize();
        bool isAlive();
        std::list<std::pair<int, int>> getPath();
        void setId(int);
        void setPosition(std::pair<int, int>);
        void setDirection(Direction);
        void setSize(int);
        void die(Bug*);
        void setPath(std::list<std::pair<int, int>>);
        Bug* getEatenBy();
        virtual ~Bug();
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const =0;
};
#endif
