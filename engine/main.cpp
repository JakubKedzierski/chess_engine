#include "GuiController.hpp"
#include "SimpleArrayChess.hpp"

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::unique_ptr<Chess> chess = std::make_unique<SimpleArrayChess>();
    GuiController controller;
    controller.printBoardToConsole(chess->getBoard());

    std::string move = "h3";
    chess->move(move);

}