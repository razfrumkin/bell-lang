#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <cctype>

#include "characters.hpp"
#include "token.hpp"

class Lexer {
    private:
        char* source_file_path;
        std::string* code;

        void skip_whitespace(std::size_t& char_index);
        std::string_view read_word(const std::size_t char_index);
        bool is_keyword(const std::string_view& word);
        bool is_valid_operator(const char op);
        bool skip_comment(std::size_t& char_index);
        Token read_number_literal(std::size_t& char_index);
        std::string_view read_identifier(std::size_t& char_index);

        Token next(std::size_t& char_index);
    public:
        // temporary for debugging
        std::string stringify(const TokenType type);
        void test();

        Lexer() = default;
        Lexer(char* source_file_path, std::string* code) :
            source_file_path(source_file_path),
            code(code) {}
};