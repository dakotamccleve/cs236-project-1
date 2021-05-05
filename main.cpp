#include "Lexer.h"

#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    std::ifstream inputFile;
    inputFile.open(argv[1]);
    std::ostringstream fout;
    fout << inputFile.rdbuf();
    std::string inputString = fout.str();

    lexer->Run(inputString);
    lexer->printTokens();

    delete lexer;

    return 0;
}