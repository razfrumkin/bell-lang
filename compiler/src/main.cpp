#include <iostream>
#include <cstring>
#include <filesystem>
#include <fstream>

#include "lexer.hpp"

static int transpile(const char* source_file, const char* output_file) {
    std::ifstream source(source_file);
    if (!source.is_open()) {
        std::cerr << source_file << " does not exist" << std::endl;
        return 1;
    }

    std::string code = std::string(std::istreambuf_iterator<char>(source), std::istreambuf_iterator<char>());

    Lexer lexer(const_cast<char*>(source_file), &code);
    lexer.test();

    std::ofstream stream(output_file, std::ofstream::out);
    if (!stream.is_open()) {
        std::cerr << output_file << " does not exist" << std::endl;
        return 1;
    }

    // stream << [translate unit class to string]
    stream.close();

    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Bell is a programming language and a personal project." << std::endl;
        return 0;
    }

    if (!strcmp(argv[1], "help")) {
        std::cout << "Help has not been implemented yet." << std::endl;
        return 0;
    }

    if (!strcmp(argv[1], "transpile")) {
        if (argc < 3) {
            std::cerr << "No source file specified" << std::endl;
            return 1;
        }
        return transpile(std::filesystem::canonical(std::filesystem::path(argv[2])).c_str(), argc > 3 ? argv[3] : "main.c");
    }

    std::cerr << "Invalid subcommand" << std::endl;
    return 1;
}