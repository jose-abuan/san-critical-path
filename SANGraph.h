#ifndef SANGraph_H
#define SANGraph_H
#include <vector>
#include <string>

class SANGraph{
    private:
        struct Edge{
            double upperBoundWeight_;
            int destinationNode;     
        };   
        std::vector<std::vector<Edge>> adjList; 
        std::vector<Edge> paths;
        int sourceNode_ = 1;
        int sinkNode_ = 0;

    public:
        SANGraph();
        void parseFile(std::string &filename);
        void findAllPaths();
        void dfsHelper(int currentNode, std::vector<Edge> &currentPath, std::vector<std::vector<Edge>> &allPaths);

};

#endif