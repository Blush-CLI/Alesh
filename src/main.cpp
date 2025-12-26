#include <print>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tui/colors.hpp>
#include <filesystem>
#include "lexer/lexer.hpp"

std::string readFile(std::string fn) {
    std::ifstream input(fn);

    if(!input.is_open()){
        return "";
    }

    std::stringstream ss;
    ss << input.rdbuf();

    return ss.str();
}

int main(int argc, char* argv[], char* envp[]) {
    if(argc < 2) {
        std::cerr << Color::Red << "> Usage: " << Color::Bold <<"alesh <file.ash>" << Color::Reset;
        return 1;
    };

    if (!std::filesystem::exists(argv[1])) {
        std::cerr << Color::Red << "> File not found" << Color::Reset;
        return 1;
    }
    
    Lexer lexer(readFile(argv[1]));

    lexer.tokenize();

    return 0;
}