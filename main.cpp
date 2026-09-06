#include "y.h"

#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]){
    if(argc > 2){
        std::cout << "Usage: y [script]" << std::endl;
        return 64;
    } else if(argc == 2){
        runFile(argv[1]);
    }else{
       runPrompt();
    }
    return 0;
}