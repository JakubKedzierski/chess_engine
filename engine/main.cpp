#include "GuiController.hpp"
#include "SimpleArrayChess.hpp"

int main(int argc, char *argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    GuiController controller;
    controller.gameLoop(argc, argv);
}
