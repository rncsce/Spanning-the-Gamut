#ifndef GDBLLIST_H
#define GDBLLIST_H
#include "GListNode.h"
#include <stdexcept>

class GDblList{
    public:
        // Default Constructor
        GDblList();
        // Virtual Default Deconstructor
        virtual ~GDblList();
        // getSize Function: returns Graph Double Linked List size
        int getSize();
        // isEmpty Function: returns if the Graph Double Linked List is empty
        bool isEmpty();
        // get Function: get Graph Double Linked List Node
        GListNode* get(int pos);
        // addToFront Function: addeds Graph List Node to front of Graph Double Linked List Node
        void addToFront(int leftVertex, int rightVertex, double edgeWeight);
        // addToBack Function: addeds Graph List Node to back of Graph Double Linked List Node
        void addToBack(int leftVertex, int rightVertex, double edgeWeight);
        // add() Function: addes Graph List Node to index of Graph Double Linked List
        void add(int pos, int leftVertex, int rightVertex, double edgeWeight);
        // removeFront Function: removes front Graph List Node of Graph Double Linked List
        void removeFront();
        // removeBack Function: removes back Graph List Node of Graph Double Linked List
        void removeBack();
        // remove Function: removes Graph List Node at index of Graph Double Linked List
        void remove(int pos);
        // getFront Getter: get's Graph Double Linked List's front Graph Node
        GListNode* getFront();
        // getBack Getter: get's Graph Double Linked List's back Graph Node
        GListNode* getBack();
    private:
        // m_front Graph List Node Pointer: points to front of Double Linked List Graph
        GListNode* m_front;
        // m_back Graph List Node Pointer: points to back of Double Linked List Graph
        GListNode* m_back;
        // m_size Integer: size of Double Linked List Graph
        int m_size;
};
#endif
