#include "SuperBug.h"
#include "Constants.h"

SuperBug::SuperBug() : Bug(){}

void SuperBug::move(){}

bool SuperBug::isWayBlocked(){
    return false;
}

void SuperBug::moveKeyboard(int& key){
    if(key == sf::Keyboard::Up){
        this->position.second -= 1;
    } else if(key == sf::Keyboard::Right){
        this->position.first += 1;
    } else if(key == sf::Keyboard::Down){
        this->position.second += 1;
    } else if(key == sf::Keyboard::Left){
        this->position.first -= 1;
    }

    if(isAlive()){
        offBoard();
    }
    Bug::updatePath();
}

void SuperBug::offBoard(){
    if(this->position.first < 0){
        this->position.first = 0;
    }else if(this->position.second >= BOARD_WIDTH){
        this->position.second = BOARD_WIDTH - 1;
    } else if(this->position.first >= BOARD_HEIGHT){
        this->position.first = BOARD_HEIGHT - 1;
    } else if(this->position.second < 0){
        this->position.second = 0;
    }
}

void SuperBug::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    int bugSize = BUG_CIRCLE_SIZE_MIN + (this->size / BUG_CIRCLE_SIZE_MIN);
    if(bugSize > BUG_CIRCLE_SIZE_MAX){
        bugSize = BUG_CIRCLE_SIZE_MAX;
    }
    sf::CircleShape circle(bugSize);
    circle.setPosition(BOARDER_GAP + this->position.first * CELL_SIZE + this->position.first * CELL_GAP +(CELL_SIZE/2) - bugSize, 
        BOARDER_GAP + this->position.second * CELL_SIZE + this->position.second * CELL_GAP + (CELL_SIZE/2) - bugSize);
    circle.setFillColor(sf::Color(255, 0, 255));
    target.draw(circle);
}