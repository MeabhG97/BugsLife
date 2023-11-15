#ifndef LINEPARSER_H
#define LINEPARSER_H

#include <string>
#include <sstream>

#include "Bug.h"
#include "Hopper.h"

class LineParser{
    private:
        static void parseBugInfo(Bug*, std::stringstream*);
        static void parseHopLength(Hopper*, std::stringstream*);
    public:
        static Bug* parseLine(std::string);
};

#endif