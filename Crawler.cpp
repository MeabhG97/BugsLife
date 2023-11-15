#include "Crawler.h"
#include "Constants.h"

Crawler::Crawler() : Bug(){}

Crawler::Crawler(std::pair<int, int> position, Direction direction, int size, std::list<std::pair<int, int>> path) 
    : Bug(position, direction, size, path) {}

void Crawler::move(){
    if(!alive){
        return;
    }
    
    while(this->isWayBlocked()){
        this->direction = this->newDirection();
    }
    switch (this->direction){
        case Direction::NORTH :
            this->position.first -= 1;
            break;
        case Direction::EAST :
            this->position.second += 1;
            break;
        case Direction::SOUTH :
            this->position.first += 1;
            break;
        case Direction::WEST :
            this->position.second -= 1;
            break;
    }
    Bug::updatePath();
}

bool Crawler::isWayBlocked(){
    bool blocked = false;
    switch (this->direction){
        case Direction::NORTH :
            if(this->position.first - 1 < 0){
                blocked = true;
            }
            break;
        case Direction::EAST :
            if(this->position.second + 1 >= BOARD_WIDTH){
                blocked = true;
            }
            break;
        case Direction::SOUTH :
            if(this->position.first + 1 >= BOARD_HEIGHT){
                blocked = true;
            }
            break;
        case Direction::WEST :
            if(this->position.second - 1 < 0){
                blocked = true;
            }
            break;
    }
    return blocked;
}

void Crawler::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    int bugSize = BUG_CIRCLE_SIZE_MIN + (this->size / BUG_CIRCLE_SIZE_MIN);
    if(bugSize > BUG_CIRCLE_SIZE_MAX){
        bugSize = BUG_CIRCLE_SIZE_MAX;
    }
    sf::CircleShape circle(bugSize);
    circle.setPosition(BOARDER_GAP + this->position.first * CELL_SIZE + this->position.first * CELL_GAP +(CELL_SIZE/2) - bugSize, 
        BOARDER_GAP + this->position.second * CELL_SIZE + this->position.second * CELL_GAP + (CELL_SIZE/2) - bugSize);
    circle.setFillColor(sf::Color(255, 0, 0));
    target.draw(circle);
}

Crawler::~Crawler(){
    
}