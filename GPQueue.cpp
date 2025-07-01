#include "GPQueue.h"
// Defaul Constructor
GPQueue::GPQueue(bool isMin){ // Parameter: whether GPQueue is min or max
    isMinQ = isMin; // Initialize MinQ to isMin parameter
    m_list = new GDblList(); // Intialize m_list as new GDblList
}
// Default Deconstructor
GPQueue::~GPQueue(){
    delete m_list; // Delete m_list
}
// remove Function
void GPQueue::remove(){
    if(isMinQ){ // If isMinQ is true
        m_list -> removeFront(); // Call m_list's removeFront Function
    } else {
        m_list -> removeBack(); // Call m_list's removeBack Function
    }
}
// isEmpty Function
bool GPQueue::isEmpty(){
    return m_list -> getSize() == 0; // Returns if calling getSize on m_list returns 0
}
// add Function
void GPQueue::add(int leftVertex, int rightVertex, double edgeWeight){ // Paramters: left vertex, right vertex, edge weight
    if(isEmpty()){ // If list is empty
        m_list -> addToFront(leftVertex, rightVertex, edgeWeight); // Call m_list's addToFront Function on parameters
    } else { // If list is not empty
        int currIdx = 0; // Declear and intialize current index as 0
        GListNode* currNode = m_list -> getFront(); // Declare and initalize curNode as m_list's front
        while(currNode != NULL && ((isMinQ == true && currNode -> getEdgeWeight() < edgeWeight) || (isMinQ == false && currNode -> getEdgeWeight() > edgeWeight))){ // While currNode is not NULL and either: isMinQ is true and currNode's edge weight is greater than parameter edge weight OR isMinQ is false and currNode's edge weight is less than than parameter edge weight 
            ++currIdx; // Increment currIdx by 1
            currNode = currNode -> m_next; // Set currNode to currNode's m_next pointer
        }
        m_list -> add(currIdx, leftVertex, rightVertex, edgeWeight); // Call m_list's add on currIdx and paramters
    }
}
// size Function
int GPQueue::size(){
    return m_list -> getSize(); // Returns returned value from m_list's getSize function call 
}
// getFrontLeftVertex Function
int GPQueue::getFrontLeftVertex(){
    return m_list -> getFront() -> getLeftVertex(); // Returns returned value from m_list's getFront, getLeftVertex function call 
}
// getFrontRightVertex Function
int GPQueue::getFrontRightVertex(){
    return m_list -> getFront() -> getRightVertex(); // Returns returned value from m_list's getFront, getRightVertex function call 
}
// getFrontEdgeWeight Function
double GPQueue::getFrontEdgeWeight(){
    return m_list -> getFront() -> getEdgeWeight(); // Returns returned value from m_list's getFront, getEdgeWeight function call 
}
