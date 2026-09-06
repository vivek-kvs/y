#include "Token.h"

std::string literalToString(const Literal& literal){
    return std::visit([](const auto& value) -> std::string{
        using T = std::decay_t<decltype(value)>;

        if constexpr (std::is_same_v<T, std::monostate>)
            return "nil";
        else if constexpr (std::is_same_v<T, std::string>)
            return value;
        else if constexpr(std::is_same_v<T, bool>)
            return value ? "true" : "false";
        else
            return std::to_string(value);
    }, literal);
}

Token::Token(TokenType type, std::string lexeme, Literal literal, int line)
    : type(type), lexeme(lexeme), literal(literal), line(line)
{
}

std::string Token::toString() {
    return std::to_string(static_cast<int>(type)) + " " + lexeme + " " + literalToString(literal);
}