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
        
        if (v > terminalNode_) {
            terminalNode_ = v;
        }
    }
    file.close();
}

std::vector<std::vector<SANGraph::Edge>> SANGraph::findAllPaths(){
    int currentNode = sourceNode_;
    std::vector<std::vector<Edge>> allPaths; 
    std::vector<Edge> currentPath; 

    dfsHelper(currentNode, currentPath, allPaths);

    return allPaths;
}

// Start from starting vertex, go to the next thing in the adj list.
// Set source to be the current start for the recursive call. 
// Keep doing that till you hit the terminalNode_.
// Save that path, now pop that node and then 
void SANGraph::dfsHelper(int currentNode, std::vector<Edge> &currentPath, std::vector<std::vector<Edge>> &allPaths){
    // Base case - if currentNode  = terminalNode_, pop back up
    if(currentNode == terminalNode_){
        allPaths.push_back(currentPath);
        return;
    }

    for (const Edge& edge: adjList[currentNode]){
        currentPath.push_back(edge);
        
        dfsHelper(edge.destinationNode, currentPath, allPaths);
        
        currentPath.pop_back();
    }    
}
