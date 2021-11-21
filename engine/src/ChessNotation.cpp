#include "ChessNotation.hpp"

ChessNotation::ChessNotation(std::shared_ptr<SimpleArrayChess> chess)
{
    this->chess = chess;
}

void ChessNotation::setChessState(std::shared_ptr<SimpleArrayChess> chess)
{
    this->chess = chess;
}

Move ChessNotation::decodeMove(const std::string &moveEncoding)
{
    const auto moveEncodingSize = moveEncoding.size();
    Move move;

    if (moveEncodingSize == 2)
    {
        move = this->decodePawnMove(moveEncoding); //e.g e4
    }

    if (moveEncoding.find("S") != std::string::npos)
    {
        move = this->decodeKnightMove(moveEncoding);
    }
    else if (moveEncoding.find("W") != std::string::npos)
    {
        move = this->decodeRookMove(moveEncoding);
    }
    else if (moveEncoding.find("G") != std::string::npos)
    {
    }
    else if (moveEncoding.find("H") != std::string::npos)
    {
    }
    else if (moveEncoding.find("K") != std::string::npos)
    {
    }
    else if (moveEncodingSize == 4 && (moveEncoding.find("x") != std::string::npos))
    {
        move = this->decodePawnMove(moveEncoding); // e.g dxe5
    }
    return move;
}

Move ChessNotation::decodeQueenMove(const std::string &moveEncoding)
{
    return {};
}

Move ChessNotation::decodeBishopMove(const std::string &moveEncoding)
{
    return {};
}

Move ChessNotation::decodeRookMove(const std::string &moveEncoding)
{
    return {};
}

Move ChessNotation::decodeKnightMove(const std::string &moveEncoding)
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

    if (chess->getTurn() == Turn::White)
    {
        figureToCheck = Figure::WKnight;
    }
    else
    {
        figureToCheck = Figure::BKnight;
    }

    for (std::pair<int, int> &pair : pairsToCheck)
    {
        if (chess->isInBoundries(move.row2 + pair.first, move.column2 + pair.second))
        {
            if (chess->getBoard()[move.row2 + pair.first][move.column2 + pair.second] == figureToCheck)
            {
                move.row1 = move.row2 + pair.first;
                move.column1 = move.column2 + pair.second;
                break;
            }
        }
    }

    return move;
}

Move ChessNotation::decodePawnMove(const std::string &moveEncoding)
{
    const auto turn = chess->getTurn();
    const auto board = chess->getBoard();
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
