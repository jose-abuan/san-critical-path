#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <vector>
class Simulator{
    private:
        struct Edge{
            float upperBoundWeight_;
            int destinationNode;     
        };   
        std::vector<std::vector<Edge>> adjList; 
        
    public:

};


#endif