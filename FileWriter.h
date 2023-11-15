#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <vector>
#include <fstream>

#include "Bug.h"
#include "Constants.h"

class FileWriter{
    public:
        static void writeHeadings(std::fstream&);
        static void writeResults(std::vector<Bug*>);
        static void writeHistory(std::vector<Bug*>);
};

#endif