#include "lexer.hpp"

void Lexer::skip_whitespace(std::size_t& char_index) {
    while (std::isspace((*code)[char_index])) char_index += 1;
}

std::string_view Lexer::read_word(const std::size_t char_index) {
    // check if the first character is an alphabet or an underscore
    if (std::isalpha((*code)[char_index]) || (*code)[char_index] == UNDERSCORE) {
        std::size_t offset = 1;

        // check if the current character is an alphabet, a digit or an underscore
        while (std::isalpha((*code)[char_index + offset]) || std::isdigit((*code)[char_index + offset]) || (*code)[char_index + offset] == UNDERSCORE) offset += 1;

        return std::string_view(code->c_str() + char_index, offset);
    }

    return std::string_view();
}

bool Lexer::is_keyword(const std::string_view& word) {
    for (std::size_t index = 0; index < KEYWORDS.size(); index += 1) {
        if (word == KEYWORDS[index]) return true;
    }

    return false;
}

bool Lexer::is_valid_operator(const char op) {
    for (std::size_t index = 0; index < OPERATORS.size(); index += 1) {
        if (op == OPERATORS[index]) return true;
    }

    return false;
}

bool Lexer::skip_comment(std::size_t& char_index) {
    if ((*code)[char_index] == HASH) {
        char_index += 1;

        // keep skipping while the character isn't '#'
        while ((*code)[char_index] != HASH) char_index += 1;

        return true;
    }

    return false;
}

Token Lexer::read_number_literal(std::size_t& char_index) {
    const std::size_t start = char_index;

    char_index += 1;

    while (std::isdigit((*code)[char_index])) char_index += 1;

    return Token(StringInfo(source_file_path, std::string_view(code->c_str() + start, char_index - start)), TokenType::INTEGER_LITERAL);
}

std::string_view Lexer::read_identifier(std::size_t& char_index) {
    std::string_view identifier = read_word(char_index);
    char_index += identifier.size();
    return identifier;
}

Token Lexer::next(std::size_t& char_index) {
    skip_whitespace(char_index);

    bool found = false;

    while (skip_comment(char_index)) skip_whitespace(char_index);

    if (std::isdigit((*code)[char_index])) return read_number_literal(char_index);

    if (std::isalpha((*code)[char_index]) || (*code)[char_index] == UNDERSCORE) {
        Token identifier;
        identifier.value_info = StringInfo(source_file_path, read_identifier(char_index));
        if (is_keyword(identifier.value_info.value)) identifier.type = KEYWORD;
        else identifier.type = IDENTIFIER;
        return identifier;
    }

    if (is_valid_operator((*code)[char_index])) {
        char_index += 1;
        return Token(StringInfo(source_file_path, std::string_view(code->c_str() + char_index - 1, 1)), OPERATOR);
    }

    std::cerr << "Unresolved token: " << std::string_view(code->c_str() + char_index, 1) << std::endl;
    return Token(StringInfo(nullptr, std::string_view()));
}

std::string Lexer::stringify(const TokenType type) {
    switch (type) {
        case INTEGER_LITERAL:
            return "Integer Literal";
        case OPERATOR:
            return "Operator";
        case IDENTIFIER:
            return "Identifier";
        case KEYWORD:
            return "Keyword";
        case SYMBOL:
            return "Symbol";
        default:
            return std::string("TokenType with the value ") + std::to_string(static_cast<int>(type)) + " does not exist";
    }
}

void Lexer::test() {
    std::size_t char_index = 0;

    while (true) {
        Token token = next(char_index);
        if (!token.value_info.file_path) break;
        std::cout << stringify(token.type) << ": " << token.value_info.value << std::endl;
    }
}