#pragma once

#include <string>
#include <variant>
#include "TokenType.h"

using Literal = std::variant<std::monostate, double, std::string, bool>;

class Token {
    public:
        TokenType type;
        std::string lexeme;
        Literal literal;
        int line;

        Token(TokenType type, std::string lexeme, Literal literal, int line);

        std::string toString();
};