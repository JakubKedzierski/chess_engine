#pragma once
#include "Commons.hpp"
#include "SimpleArrayChess.hpp"

class ChessNotation
{
private:
    Move decodeKnightMove(const std::string &moveEncoding);
    Move decodePawnMove(const std::string &moveEncoding);
    Move decodeRookMove(const std::string &moveEncoding);
    Move decodeQueenMove(const std::string &moveEncoding);
    Move decodeKingMove(const std::string &moveEncoding);
    Move decodeBishopMove(const std::string &moveEncoding);
    std::shared_ptr<SimpleArrayChess> chess = nullptr;

public:
    ChessNotation() = default;
    ChessNotation(std::shared_ptr<SimpleArrayChess> chess);
    void setChessState(std::shared_ptr<SimpleArrayChess> chess);
    Move decodeMove(const std::string &moveEncoding);
};

// make it simpler -> one function decodeMove with board pointer as argument