#include <random>

#include "Bug.h"
#include "Constants.h"

Bug::Bug(){
    this->alive = true;
    this->eatenBy = nullptr;
}

Bug::Bug(std::pair<int, int> position, Direction direction, int size, std::list<std::pair<int, int>> path){
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->path = path;
    this->alive = true;
    this->eatenBy = nullptr;
    path.push_back(this->getPosition());
}

void Bug::updatePath(){
    path.push_back(this->getPosition());
}

Direction Bug::newDirection(){
    return static_cast<Direction>(rand() % NUMBER_OF_DIRECTIONS);
}

int Bug::getId(){
    return this->id;
}

std::pair<int, int> Bug::getPosition(){
    return this->position;
}

Direction* Bug::getDirection(){
    return &(this->direction);
}

int Bug::getSize(){
    return this->size;
}

bool Bug::isAlive(){
    return this->alive;
}

std::list<std::pair<int, int>> Bug::getPath(){
    return this->path;
}

void Bug::setId(int id){
    this->id = id;
}

void Bug::setPosition(std::pair<int, int> position){
    this->position = position;
    if(this->position.first != -1 || this->position.second != -1){
        updatePath();
    }
}

void Bug::setDirection(Direction direction){
    this->direction = direction;
}

void Bug::setSize(int size){
    this->size = size;
}

void Bug::die(Bug* bug){
    this->alive = false;
    this->eatenBy = bug;
    this->setPosition(std::make_pair(-1, -1));
}

void Bug::setPath(std::list<std::pair<int, int>> path){
    this->path = path;
}

Bug* Bug::getEatenBy(){
    return this->eatenBy;
}

Bug::~Bug(){

}