project(bell-lang-compiler)

set(SOURCE_FILES
    src/main.cpp

    src/lexer.cpp
    src/symbols.cpp
)

add_executable(bell ${SOURCE_FILES})

set_target_properties(bell PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)