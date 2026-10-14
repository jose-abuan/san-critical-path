#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Simulator.h"
#include "SANGraph.h"

using namespace std;

int main(int argc, char* argv[]){
    SANGraph G;
    Simulator sim = new Simulator(G, argc[2], argc[2]);
    

    G.parseFile(std::string &argv[1]);
    vector<vector<SANGraph::Edge>> allPaths = G.findAllPaths();
    

    return 0;
}