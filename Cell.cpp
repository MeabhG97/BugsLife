#include "Cell.h"
#include "Constants.h"

Cell::Cell(int x, int y){
    this->bug = nullptr;
    this->position.first = x;
    this->position.second = y;
}



Bug* Cell::getBug(){
    return this->bug;
}

bool Cell::isOccupied(){
    if(this->bug != nullptr){
        return true;
    }
    return false;
}

std::pair<int, int> Cell::getPosition(){
    return this->position;
}

void Cell::setBug(Bug* bug){
    this->bug = bug;
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    sf::RectangleShape rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    rect.setPosition(BOARDER_GAP + this->position.first * CELL_SIZE + this->position.first * CELL_GAP, 
        BOARDER_GAP + this->position.second * CELL_SIZE + this->position.second * CELL_GAP);
    target.draw(rect);

    if(bug != nullptr){
        target.draw(*bug);
    }
}

Cell::~Cell(){}