#pragma once

#include <string_view>

struct StringInfo {
    char* file_path;
    std::string_view value;

    StringInfo() = default;
    StringInfo(char* file_path, const std::string_view& value) :
        file_path(file_path),
        value(value) {}
};