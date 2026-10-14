#ifndef SANGraph_H
#define SANGraph_H
#include <vector>
#include <string>

class SANGraph{
     public:
        SANGraph();
        struct Edge{
            double upperBoundWeight_;
            int destinationNode;     
        };
        void parseFile(std::string &filename);
        std::vector<std::vector<Edge>> findAllPaths();
        void dfsHelper(int currentNode, std::vector<Edge> &currentPath, std::vector<std::vector<Edge>> &allPaths);

    private:   
        std::vector<std::vector<Edge>> adjList; 
        std::vector<Edge> paths;
        const int sourceNode_ = 1; // Source node will always be 1
        int terminalNode_ = 0;
   
};

#endif