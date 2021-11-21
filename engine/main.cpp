#include "GuiController.hpp"
#include "SimpleArrayChess.hpp"

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    GuiController controller;
    controller.gameLoop();

}