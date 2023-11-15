#ifndef PRINTBUG_H
#define PRINTBUG_H

#include "Bug.h"

class PrintBug{
    public:
        static void printHeadings();
        static void printBug(Bug*);
        static void printHistory(Bug*);
};

#endif