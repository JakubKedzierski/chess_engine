#include "SimpleArrayChess.hpp"

SimpleArrayChess::SimpleArrayChess()
{
    notationType = NotationType::English; // by default polish, in extension enable English notation
    board = {Figure::WRook, Figure::WKnight, Figure::WBishop, Figure::WQueen, Figure::WKing, Figure::WBishop, Figure::WKnight, Figure::WRook,
             Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn, Figure::WPawn,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty, Figure::Empty,
             Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn, Figure::BPawn,
             Figure::BRook, Figure::BKnight, Figure::BBishop, Figure::BQueen, Figure::BKing, Figure::BBishop, Figure::BKnight, Figure::BRook};
    turn = Turn::White;
}

Board SimpleArrayChess::getBoard()
{
    return this->board;
}

Figure SimpleArrayChess::getFigure(const int column, const int row) const
{
    return this->board[row][column];
}

Figure SimpleArrayChess::getFigure(const std::string &moveEncoding) const
{
    const auto column = static_cast<int>(moveEncoding[0]) - 96 - 1;
    const auto row = static_cast<int>(moveEncoding[1]) - 48 - 1;
    return this->getFigure(column, row);
}

inline void SimpleArrayChess::turnChange()
{
    turn = (turn == Turn::White ? Turn::Black : Turn::White);
}

bool SimpleArrayChess::isInBoundries(int row, int column)
{
    return (row >= 0 && row < BOARD_SIZE) && (column >= 0 && column < BOARD_SIZE);
}

void SimpleArrayChess::move(int column1, int row1, int column2, int row2)
{
    board[row2][column2] = board[row1][column1];
    board[row1][column1] = Figure::Empty;
    this->turnChange();
}

Move SimpleArrayChess::decodeKnightMove(const std::string &moveEncoding)
{
    Move move;
    std::vector<std::pair<int, int>> pairsToCheck =
        {std::make_pair(-2, -1),
         std::make_pair(-2, +1),
         std::make_pair(+2, -1),
         std::make_pair(+2, +1),
         std::make_pair(-1, -2),
         std::make_pair(-1, +2),
         std::make_pair(+1, -2),
         std::make_pair(+1, +2)}; // row & column pair

    auto moveEncodingSize = moveEncoding.size();
    if (moveEncodingSize == 3)
    {
        move.column2 = static_cast<int>(moveEncoding[1]) - 96 - 1;
        move.row2 = static_cast<int>(moveEncoding[2]) - 48 - 1;
    }
    else if (moveEncodingSize == 4 || moveEncodingSize == 5)
    {
        if (moveEncodingSize == 4)
        {
            move.column2 = static_cast<int>(moveEncoding[2]) - 96 - 1;
            move.row2 = static_cast<int>(moveEncoding[3]) - 48 - 1;
        }
        else
        {
            move.column2 = static_cast<int>(moveEncoding[3]) - 96 - 1;
            move.row2 = static_cast<int>(moveEncoding[4]) - 48 - 1;
        }

        if (moveEncoding.find("x") == std::string::npos)
        {
            if (isdigit(moveEncoding[1]))
            {
                move.row1 = int(moveEncoding[1]) - 48 - 1;
                auto diff = move.row1 - move.row2;
                if (abs(move.row2 - move.row1) == 2)
                {
                    pairsToCheck = {std::make_pair(diff, -1),
                                    std::make_pair(diff, +1)};
                }
                else
                {
                    pairsToCheck = {std::make_pair(diff, -2),
                                    std::make_pair(diff, +2)};
                }
            }
            else
            {
                move.column1 = static_cast<int>(moveEncoding[1]) - 96 - 1;
                auto diff = move.column1 - move.column2;
                if (abs(diff) == 2)
                {
                    pairsToCheck = {std::make_pair(-1, diff),
                                    std::make_pair(1, diff)};
                }
                else
                {
                    pairsToCheck = {std::make_pair(-2, diff),
                                    std::make_pair(2, diff)};
                }
            }
        }
    }

    Figure figureToCheck = Figure::Empty;

    if (turn == Turn::White)
    {
        figureToCheck = Figure::WKnight;
    }
    else
    {
        figureToCheck = Figure::BKnight;
    }

    for (std::pair<int, int> &pair : pairsToCheck)
    {
        if (isInBoundries(move.row2 + pair.first, move.column2 + pair.second))
        {
            if (board[move.row2 + pair.first][move.column2 + pair.second] == figureToCheck)
            {
                move.row1 = move.row2 + pair.first;
                move.column1 = move.column2 + pair.second;
                break;
            }
        }
    }

    return move;
}

Move SimpleArrayChess::decodePawnMove(const std::string &moveEncoding)
{
    Move move;
    if (moveEncoding.size() == 2)
    {
        move.column2 = static_cast<int>(moveEncoding[0]) - 96 - 1;
        move.row2 = static_cast<int>(moveEncoding[1]) - 48 - 1;
        move.column1 = move.column2;
    }
    else
    {
        move.column2 = static_cast<int>(moveEncoding[2]) - 96 - 1;
        move.row2 = static_cast<int>(moveEncoding[3]) - 48 - 1;
        move.column1 = static_cast<int>(moveEncoding[0]) - 96 - 1;
        if (turn == Turn::White)
        {
            move.row1 = move.row2 - 1;
        }
        else
        {
            move.row1 = move.row2 + 1;
        }
    }

    if (turn == Turn::White && board[move.row2 - 1][move.column2] == Figure::WPawn)
    {
        move.row1 = move.row2 - 1;
    }
    else if (turn == Turn::White && board[move.row2 - 2][move.column2] == Figure::WPawn)
    {
        move.row1 = move.row2 - 2;
    }
    else if (turn == Turn::Black && board[move.row2 + 1][move.column2] == Figure::BPawn)
    {
        move.row1 = move.row2 + 1;
    }
    else if (turn == Turn::Black && board[move.row2 + 2][move.column2] == Figure::BPawn)
    {
        move.row1 = move.row2 + 2;
    }
    return move;
}

void SimpleArrayChess::move(std::string &moveEncoding) // should throw invalid argument when wrogn move
// create function movePawn,  error handling
{
    const auto moveEncodingSize = moveEncoding.size();
    Move move;

    if (moveEncodingSize == 2)
    {
        move = this->decodePawnMove(moveEncoding); //e.g e4
    }

    if (moveEncodingSize == 4 && (moveEncoding.find("x") != std::string::npos))
    {
        move = this->decodePawnMove(moveEncoding); // e.g dxe5
    }

    if (moveEncoding.find("S") != std::string::npos)
    {
        move = this->decodeKnightMove(moveEncoding);
    }

    if (moveEncoding.find("W") != std::string::npos)
    {
        move = this->decodeKnightMove(moveEncoding);
    }

    this->move(move.column1, move.row1, move.column2, move.row2);
}
