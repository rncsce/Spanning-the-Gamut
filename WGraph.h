#ifndef WGRAPH_H
#define WGRAPH_H
#include "GPQueue.h"

#include <iostream>
#include <limits>
#include <set>
#include <iostream>
#include <fstream>

// A weighted, undirecte WGraph implemented with adjacency matrix
// Fixed size
typedef unsigned int VertexID;

class WGraph{
    public:
        // Default Constructor: initializes Graph Object
        WGraph();
        // Overloaded Constructor: initializes Graph Objects with Graph's size
        WGraph(unsigned int sz);
        // Default Deconstructor: deallocates memory used by Graph Object
        ~WGraph();
        // addEdge Function: add's edge to Graph
        void addEdge(VertexID i, VertexID j, double w);
        // removeEdge Function: remove's edge from graph
        void removeEdge(VertexID i, VertexID j);
        // areAdjacent Function: returns if two edge's are adjacent
        bool areAdjacent(VertexID i, VertexID j);
        // cheaptestCost Function: returns cheapest cost of two edges
        double cheapestCost(VertexID i, VertexID j);
        // calcFW: calculates Floyd-warshall Algorithm
        void calcFW();
        // computeMST Function: computes Kruskal's Minimum Spanning Tree
        void computeMST();
        // calcTotalCost Function: calculates total cost of graph
        double calcTotalCost();
        // displayMST Function: outputs MST to terminal
        void displayMST();
        // displayMST Overloaded Function: outputs MST to file 
        void displayMST(const std::string& fileName);
    private:
        // m_adj Matrix: edge's adjacency matrix
        double** m_adj; // Is there an edge between two vertices and what's the weight of the edge
        // m_conn Matrix: edge's connection matrix
        double** m_conn; // More General, is there a path between a start and a finish and what's the cost (all parts summed)
        // m_size Unsigned Integer: number of vertixes in Graph
        unsigned int m_size; // Nodes in WGraph (fixed)
        // m_totalCost Double: total cost of Graph
        double m_totalCost;
        // gMinQueue GPQueue: Graph's Priority Queue
        GPQueue* gMinQueue;
};
#endif
