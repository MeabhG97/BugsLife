#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>

class FileReader{
    public:
        static std::vector<std::string>* readFile(const std::string);
};

#endif