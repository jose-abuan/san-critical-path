#include "SANGraph.h"
#include <fstream>
#include <iostream>
#include <vector>

SANGraph::SANGraph(){
}

void SANGraph::parseFile(std::string &filename){
    //Take in some form of file 
    // Use this file to develop the paths
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr << "Failed to open SAN description file.\n";
        return;
    }

    int u, v;
    double b;

    while(file >> u >> v >> b){
        if (u >= adjList.size()){
            adjList.resize(u+1);
        }
        adjList[u].push_back({b,v});
    }
    file.close();
}

void SANGraph::findAllPaths(){
    int currentNode = sourceNode_;
    std::vector<std::vector<Edge>> allPaths; 
    std::vector<Edge> currentPath = adjList[sourceNode_]; 

    dfsHelper(currentNode, currentPath, allPaths);
}

void SANGraph::dfsHelper(int currentNode, std::vector<Edge> &currentPath, std::vector<std::vector<Edge>> &allPaths){

}