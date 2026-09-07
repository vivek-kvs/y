#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "Token.h"

class Scanner {
    private:
        const std::string source;
        std::vector<Token> tokens;
        static const std::unordered_map<std::string, TokenType> keywords;

        int start = 0;
        int current = 0;
        int line = 1;

        bool isAtEnd();
        void scanToken();
        char advance();
        void addToken(TokenType type, Literal literal = std::monostate{});
        bool match(char expected);
        char peek();
        void string();
        bool isDigit(char c);
        void number();
        char peekNext();
        void identifier();
        bool isAlpha(char c);
        bool isAlphaNumeric(char c);

    public:
        Scanner(const std::string& source);

        std::vector<Token> scanTokens();
};