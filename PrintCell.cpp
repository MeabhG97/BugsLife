#include <iostream>
#include <iomanip>
#include <string>

#include "PrintCell.h"

using namespace std;

void PrintCell::printCell(Cell* cell){
    cout << "(" << to_string(cell->getPosition().first) << "," << to_string(cell->getPosition().second) << ") ";
    if(cell->getBug() == nullptr){
        cout << "Empty";
    } else {
        cout << "Occupied by " << cell->getBug()->getId();
    }
    cout << endl;
}