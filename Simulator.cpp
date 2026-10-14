#include "Simulator.h"
#include <fstream>
#include <iostream>


Simulator::Simulator(SANGraph* graph, int numReplications, const std::string& randomFileName){
    this->graph_ = graph;
    this->numReplications = numReplications;
    randomFile_.open(randomFileName);
    if(!randomFile_.is_open()){
        std::cerr << "Cannot open file.\n";
    }      
    allPaths_ = graph_->findAllPaths();

    for(const auto &path: allPaths_){
        pathWinCounts_[formatPath(path)] = 0;
    }

}

Simulator::~Simulator(){
    if(randomFile_.is_open()){
        randomFile_.close();
    }
}

void Simulator::performReplication(){
    // 1. Assign a simulated duration to every edge in the graph[cite: 10].
    // Read the next value from randomFile_ and multiply it by the edge's upper bound (b)[cite: 10].
    double b;
    randomFile_ >> static_cast<double>();
    // 2. Traverse all possible paths and sum the simulated edge durations for each path[cite: 10].
    
    // 3. Identify the "critical path" (the path with the longest total duration) for this specific replication[cite: 10].
    
    // 4. Increment a counter for that specific winning path[cite: 10].

}

void Simulator::run(){
    for(int i = 0; i < numReplications; i++){
        performReplication();
    }
}

void Simulator::calculateAndPrintResults() const{

}

std::string Simulator::formatPath(const std::vector<SANGraph::Edge>& path) const{
    return "";
}





