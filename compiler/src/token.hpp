#pragma once

#include "string_info.hpp"

enum TokenType {
    INTEGER_LITERAL,
    OPERATOR,
    IDENTIFIER,
    KEYWORD,
    SYMBOL
};

struct Token {
    StringInfo value_info;
    TokenType type;

    Token() = default;
    Token(const StringInfo& value_info) :
        value_info(value_info) {}
    Token(const StringInfo& value_info, const TokenType type) :
        value_info(value_info),
        type(type) {}
};