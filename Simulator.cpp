#include "Simulator.h"
#include <fstream>
#include <iostream>


Simulator::Simulator(){
    return;
}

void Simulator::parseFile(std::string &filename){
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr << "File cannot be opened.\n";
    }
}

