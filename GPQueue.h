#ifndef GPQUEUE_H
#define GPQUEUE_H
#include "GDblList.h"
#include <set>
#include <iterator>

class GPQueue{
    public:
        // Default Constructor: intializes Graph Priority Queue Object
        GPQueue(bool isMin); // Min q or not
        // Virtual Default Deconstructor: deallocates memory used by Graph Priority Queue Object
        virtual ~GPQueue();
        // add Function: add's Graph List Node to Graph Priority Queue
        void add(int leftVertex, int rightVertex, double edgeWeight);
        // remove Function: removes from top of Graph Priority Queue
        void remove();
        // getFrontLeftVertex Getter: gets left vertex of Graph Priority Queue's front
        int getFrontLeftVertex();
        // getFrontRightVertex Getter: gets right vertex of Graph Priority Queue's front
        int getFrontRightVertex();
        // getFrontEdgeWeight Getter: gets edge weight of Graph Priority Queue's front
        double getFrontEdgeWeight();
        // size Getter: gets size of Graph Priority Queue
        int size();
        // isEmpty Function: returns if the Graph Double Linked List is empty
        bool isEmpty();
    private:
        // isMinQ Boolean: whether the Graph Priority Queue is a min or max priority queue
        bool isMinQ;
        // m_list GDblList: holds Graph List Node's of Graph Prority Queue in order
        GDblList* m_list;
};
#endif
