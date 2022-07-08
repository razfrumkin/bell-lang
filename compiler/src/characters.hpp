#pragma once

#include <string>
#include <array>

const std::string PROCEDURE = "proc";
const std::string RETURN = "ret";
const std::string END = "end";

const std::array<std::string, 3> KEYWORDS = {
    PROCEDURE,
    RETURN,
    END
};

constexpr char HASH = '#';
constexpr char UNDERSCORE = '_';

constexpr char DOT = '.';
constexpr char COMMA = ',';
constexpr char COLON = ':';
constexpr char PLUS =                   '+';
constexpr char DASH =                   '-';
constexpr char ASTERISK =               '*';
constexpr char SLASH =              '/';
constexpr char OPEN_PARENTHESIS = '(';
constexpr char CLOSED_PARENTHESIS = ')';

constexpr std::array<char, 9> OPERATORS = {
    DOT,
    COMMA,
    COLON,
    PLUS,
    DASH,
    ASTERISK,
    SLASH,
    OPEN_PARENTHESIS,
    CLOSED_PARENTHESIS
};