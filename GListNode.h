#ifndef GLISTNODE_H
#define GLISTNODE_H
#include <cstdlib>
using namespace std;

class GListNode{
    public:
        // Default Constructor: initializes Graph List Node object
        GListNode(int leftVertex, int rightVertex, double edgeWeight);
        // Virtual Default Deconstructor: deallocates memory used by Graph List Node
        virtual ~GListNode();
        // getLeftVertex() Getter: get's Graph List Node's left vertex
        int getLeftVertex();
        // getRightVertex Getter: get's Graph List Node's right vertex
        int getRightVertex();
        // getEdgeWeight Getter: get's Graph List Node's edge weight
        double getEdgeWeight(); 
        // m_next ListNode Pointer: points to next node in list
        GListNode* m_next;
        // n_preve ListNode Pointer: points to previous node in list
        GListNode* m_prev;
    private:
        // m_leftVertex Integer: data of left vertex
        int m_leftVertex;
        // m_rightVertex Integer: data of right vertex
        int m_rightVertex;
        // m_edgeWeight Double: data of edge weight
        double m_edgeWeight;
};
#endif
