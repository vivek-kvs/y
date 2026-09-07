#include "y.h"
#include "Scanner.h"
#include "Token.h"

#include <iostream>   // std::cout, std::cin, std::cerr
#include <fstream>    // std::ifstream
#include <iterator>   // std::istreambuf_iterator
#include <cstdlib>    // std::exit
#include <vector>

// Definition of Global Error Flag
bool hadError = false;

// Run y file
void runFile(const std::string& path){
    std::ifstream file(path);

    if(!file){
        std::cerr << "Could not open file: " << path << std::endl;
        std::exit(74);
    }

    std::string source{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
    run(source);
    if(hadError) std::exit(65);
}


// REPL
void runPrompt(){
    std::string line;

    while(true){
        std::cout << "> ";
        if(!std::getline(std::cin, line)){
            break; // Cntrl+D
        }

        run(line);
        hadError = false; // 
    }
}

// Run source code
void run(const std::string& source){
    Scanner scanner(source);

    std::vector<Token> tokens = scanner.scanTokens();

    // For now, just print the tokens.
    for(Token& token: tokens){
        std::cout << token.toString() << '\n';
    }
}

// Error Handling
void error(int line, const std::string& message){
    report(line, "", message);
}

void report(int line, const std::string& where, const std::string& message){
    std::cerr << "[line " << line << " ] Error" << where << ": " << message << std::endl;

    hadError = true;
}