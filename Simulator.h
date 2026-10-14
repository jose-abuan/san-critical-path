#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include "SANGraph.h"

 
class Simulator{
    private:
        SANGraph* graph_;
        int numReplications;
        std::vector<int> uniformValues_;
        std::ifstream randomFile_;
        std::map<std::string, int> pathWinCounts_;
        std::vector<std::vector<SANGraph::Edge>> allPaths_;
        std::string formatPath(const std::vector<SANGraph::Edge>& path) const;
        void performReplication();
    public:
        Simulator(SANGraph* graph, int numReplications, const std::string& randomFileName);
        ~Simulator(); // Destructor to also close the file stream
        void run();
        void calculateAndPrintResults() const;
};


#endif