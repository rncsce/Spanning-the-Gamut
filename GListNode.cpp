#include "GListNode.h"
// Default Constructor
GListNode::GListNode(int leftVertex, int rightVertex, double edgeWeight){
    m_leftVertex = leftVertex; // Set m_leftVertex to parameter leftVertex
    m_rightVertex = rightVertex; // Set m_righVertex to parameter rightVertex
    m_edgeWeight = edgeWeight; // Set m_righVertex to parameter edgeWeight
    m_next = NULL; // Initialize m_next as null
    m_prev = NULL; // Initialize m_prev as null
}
// Default Deconstructor
GListNode::~GListNode(){
    m_next = NULL; // Deallocated m_next
    m_prev = NULL; // Deallocate m_prev
}
// getLeftVertex Getter
int GListNode::getLeftVertex(){
    return m_leftVertex; // return Graph List Node's left vertex
}
// getRightVertex Getter
int GListNode::getRightVertex(){
    return m_rightVertex; // return Graph List Node's right vertex
} 
// getEdgeWeight
double GListNode::getEdgeWeight(){
    return m_edgeWeight; // return Graph List Node's edge weight
}
