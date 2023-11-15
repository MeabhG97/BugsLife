#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <thread>
#include <chrono>
#include <utility>


#include "Board.h"
#include "Constants.h"
#include "FileReader.h"
#include "LineParser.h"
#include "Crawler.h"
#include "PrintBug.h"
#include "PrintCell.h"
#include "FileWriter.h"

Board::Board(sf::RenderWindow* window){
    this->window = window;
    for(int i = 0; i < BOARD_WIDTH; i++){
        std::vector<Cell> cellCol;
        for(int j = 0; j < BOARD_HEIGHT; j++){
            cellCol.push_back(Cell(i, j));
        }
        cells.push_back(cellCol);
    }
    initialiseBugs();
}

void Board::updateCells(Bug* bug, Bug* removeBug){
    if(!bug->isAlive()){
        return;
    }
    cells.at(bug->getPosition().first).at(bug->getPosition().second).setBug(removeBug);
}

void Board::updateCells(Bug* bug){
    if(!bug->isAlive()){
        return;
    }
    if(cells.at(bug->getPosition().first).at(bug->getPosition().second).getBug() != nullptr){
        Bug* bugInCell = cells.at(bug->getPosition().first).at(bug->getPosition().second).getBug();
        if(bug->getSize() > bugInCell->getSize()){
            bug->setSize(bug->getSize() + bugInCell->getSize());
            bugInCell->die(bug);
            cells.at(bug->getPosition().first).at(bug->getPosition().second).setBug(bug);
        } else {
           bugInCell->setSize(bugInCell->getSize() + bug->getSize());
           bug->die(bugInCell);
        }
    } else {
        cells.at(bug->getPosition().first).at(bug->getPosition().second).setBug(bug);
    }
}

void Board::initialiseBugs(){
    std::vector<std::string>* lines = FileReader::readFile(DATA_FILE);
    for(std::string line : *lines){
        Bug* bug = LineParser::parseLine(line);
        bugs.push_back(bug);
        updateCells(bug);
        if(dynamic_cast<SuperBug*>(bug)){
            this->superBug = dynamic_cast<SuperBug*>(bug);
        }
    }
}

void Board::displayAllBugs(){
    PrintBug::printHeadings();
    for(Bug* bug : bugs){
        PrintBug::printBug(bug);
    }
}

bool Board::findABug(int id){
    for(Bug* bug : bugs){
        if(bug->getId() == id){
            PrintBug::printHeadings();
            PrintBug::printBug(bug);
            return true;
        }
    }
    return false;
}

void Board::tap(){
    for(Bug* bug : bugs){
        updateCells(bug, nullptr);
        bug->move();
        updateCells(bug);
    }
}

void Board::moveSuperBug(int& key){
    updateCells(this->superBug, nullptr);
    this->superBug->moveKeyboard(key);
    updateCells(this->superBug);
}

void Board::displayHistory(){
    for(Bug* bug : bugs){
        PrintBug::printHistory(bug);
    }
}

void Board::displayAllCells(){
    for(std::vector<Cell> cVec : cells){
        for(Cell cell : cVec){
            PrintCell::printCell(&cell);
        }
    }
}

void Board::simulation(){
    while(countAlive() > 1){
        tap();
    }
    writeResults();
}

int Board::countAlive(){
    int count = 0;
    for(Bug* bug : bugs){
        if(bug->isAlive()){
            count++;
        }
    }
    return count;
}

void Board::writeResults(){
    FileWriter::writeResults(bugs);
}

void Board::writeHistory(){
    FileWriter::writeHistory(bugs);
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(std::vector<Cell> cVec : cells){
        for(Cell cell : cVec){
            target.draw(cell);
        }
    }
}