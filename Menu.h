#ifndef MENU_H
#define MENU_H

#include "Board.h"

class Menu {
    private:
        static void invalidArgument();
        static int* bugIdInput();
    public:
        static void displayOptions();
        static void selectOption(Board&, bool&, int&, int&);
};

#endif