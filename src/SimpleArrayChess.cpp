#include "SimpleArrayChess.hpp"

SimpleArrayChess::SimpleArrayChess()
{
    board = {Figure::WRook, Figure::WKnight, Figure::WBishop, Figure::WQueen, Figure::WKing, Figure::WBishop, Figure::WKnight, Figure::WRook,
             Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn,
             Figure::BRook, Figure::BKnight, Figure::BBishop, Figure::BQueen, Figure::BKing, Figure::BBishop, Figure::BKnight, Figure::BRook};
}

Board SimpleArrayChess::getBoard()
{
    return this->board;
}

void SimpleArrayChess::move(std::string &)
{
}

bool SimpleArrayChess::isPossibleMove(std::string &)
{
    return true;
}