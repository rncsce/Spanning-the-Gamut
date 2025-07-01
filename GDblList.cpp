#include "GDblList.h"
// Default Constructor
GDblList::GDblList(){
    m_front = NULL; // Initializes m_front to NULL
    m_back = NULL; // Initializes m_back to NULL
    m_size = 0; // Initializes m_size to 0
}
// Default Deconstructor
GDblList::~GDblList(){ 
    while (m_front != NULL) { // While m_front is not NULL
        GListNode* temp = m_front; // Save m_front Graph List Node as temp
        m_front = m_front -> m_next; // Point m_front pointer to next Graph List Node in Graph DblList
        delete temp; // Delete temp variable
    }
    m_size = 0; // Reset m_size to 0
}
// getSize Function
int GDblList::getSize(){ 
    return m_size; // Return m_size variable
}
// is Empty Function
bool GDblList::isEmpty(){
    return(m_size == 0); // Return if m_size is equal to 0
}
// addToFront Function
void GDblList::addToFront(int leftVertex, int rightVertex, double edgeWeight){ // Parameters: left vertex, right vertex, edge weight
    GListNode* newNode = new GListNode(leftVertex, rightVertex, edgeWeight); // Declare and initialize newNode with parameters
    if (!isEmpty()){ // If the Graph DblList is not empty
        m_front -> m_prev = newNode; // Set m_front's m_prev pointer to newNode
        newNode -> m_next = m_front; // Set newNode's m_next pointer to current m_front
    } else { // If the Graph DblList is empty
        m_back = newNode; // Set m_back to newNode
    } 
    m_front = newNode; // Set m_front to newNode
    ++m_size; // Increment m_size by 1
}
// addToBack Function
void GDblList::addToBack(int leftVertex, int rightVertex, double edgeWeight){ // Parameters: left vertex, right vertex, edge weight
    GListNode* newNode = new GListNode(leftVertex, rightVertex, edgeWeight); // Declare and initialize newNode with parameters
    if (!isEmpty()){ // If the Graph DblList is not empty
        m_back -> m_next = newNode; // Set m_back's m_prev pointer to newNode
        newNode -> m_prev = m_back; // Set newNode's m_next pointer to current m_back
    } else {
        m_front = newNode; // Set m_front to newNode
    }
    m_back = newNode; // Set m_back to newNode
    ++m_size; // Increment m_size by 1
}
void GDblList::add(int pos, int leftVertex, int rightVertex, double edgeWeight){ // Parameters: index to add into, left vertex, right vertex, edge weight
    if(isEmpty()){ // If Graph DblList is empty
        addToFront(leftVertex, rightVertex, edgeWeight); // Call addToFrontFunction with left vertex, right vertex, and edge weight parameters
    } else if(pos == 0) { // If index to add into is 0
        addToFront(leftVertex, rightVertex, edgeWeight); // Call addToFrontFunction with left vertex, right vertex, and edge weight parameters
    } else if(pos >= m_size){ // If index to add into is greater than or equal to m_size 
        addToBack(leftVertex, rightVertex, edgeWeight); // Call addToBackFunction with left vertex, right vertex, and edge weight parameters
    } else { // If Graph DblList is not empty
        GListNode* current = m_front; // Declare current as m_front
        int cPos = 0; // Declare and initialize cPos integer as 0 (current position)
        while(cPos != pos){ // While index to add parameter does not equal current position
            current = current -> m_next; // Set current to current's m_next pointer
            ++cPos; // Increment cPos by 1
        }
        GListNode* newNode = new GListNode(leftVertex, rightVertex, edgeWeight); // Declare and initialize newNode with left vertex, right vertex, and edge weight parameters
        current -> m_prev -> m_next = newNode; // Set current's m_prev pointer's m_next to newNode
        newNode -> m_prev = current -> m_prev; // Set newNode's m_prev pointer to current's m_prev 
        current -> m_prev = newNode; // Set current's m_prev pointer to newNode
        newNode -> m_next = current; // Set newNode's m_nex pointer to newNode
        ++m_size;
    }
}
// removeFront Function
void GDblList::removeFront(){ 
    if(isEmpty()){ // If Graph DblList is empty
        throw std::runtime_error("List is empty."); // Throw exception with error message that list is empty
    }
    if (m_size == 1){ // If m_size is 1
        delete m_front; // Delete m_front (m_back is the same)
        m_front = NULL; // Set m_front to NULL
        m_back = NULL; // Set m_back to NULL
    } else { // If m_size not 1
        GListNode* currFront = m_front; // Declare and initialize currFront as m_front
        m_front = m_front -> m_next; // Set m_front to m_front's m_next pointer
        m_front -> m_prev = NULL; // Set m_front's m_prev pointer to NULL
        delete currFront; // Delete currFront 
    }
    --m_size; // Decrement m_size by 1
}
// removeBack Function
void GDblList::removeBack(){
    if(isEmpty()){ // If Graph DblList is empty
        throw std::runtime_error("List is empty."); // Throw exception with error message that list is empty
    }
    if (m_size == 1){ // If m_size is 1
        delete m_back; // Delete m_back (m_front is the same)
        m_front = NULL; // Set m_front to NULL
        m_back = NULL; // Set m_back to NULL
    } else { // If m_size is not 1
        GListNode* currBack = m_back; // Declare and initialize currBack as m_back
        m_back = m_back -> m_prev; // Set m_back to m_back's m_next pointer
        m_back -> m_prev = NULL; // Set m_back's m_prev pointer to NULL
        delete currBack; // Delete currBack 
    }
    --m_size; // Decrement m_size by 1
}
void GDblList::remove(int pos){ // Parameters: index of Graph List Node (to remove from)
    if(isEmpty()){ // If Graph DblList is empty
        throw std::runtime_error("List is empty."); // Throw exception with error message that list is empty
    }
    GListNode*  temp; // Declare Graph List Node temp variable
    if (pos == 0){ // If index to remove is 0
        removeFront(); // Call removeFront Function
    } else if(pos >= m_size){ // If index to remove is greater than or equal to m_size
        removeBack(); // Call removeBack Function 
    } else { // If index to remove is less than m_size
        GListNode* current = m_front; // Declare and initialize current as m_front
        int cPos = 0; // Declare and initialize cPos integer as 0 (current position)
        while(cPos != pos){ // While index to add parameter does not equal current position
            current = current -> m_next; // Set current to current's m_next pointer
            ++cPos; // Increment cPos by 1
        }
        temp = current; // Set temp to current
        current -> m_prev -> m_next = current -> m_next; // Set current's m_prev pointer's m_next pointer to current's m_next
        current -> m_next -> m_prev = current -> m_prev; // Set current's m_prev pointer's m_prev pointer to current's m_prev
        delete current; // Delete current
        --m_size; // Decrement m_size by 1
    }
}
// get Function
GListNode* GDblList::get(int pos){ // Parameters: index of Graph List Node (to get)
    if(pos < 0 || pos >= m_size){ // If index is less than 0 or index is greater than or equal to m_size
        throw std::runtime_error("Index not in range."); // Throw exception with error message that index is not in range
    }
    GListNode* current = m_front; // Declare and initialize current as m_front
    int cPos = 0; // Declare and initialize cPos integer as 0 (current position)
    while(cPos != pos){ // While index to add parameter does not equal current position
        current = current -> m_next; // Set current to current's m_next pointer
        ++cPos; // Increment cPos by 1
    }
    return current; // Return current
}
// getFront Function
GListNode* GDblList::getFront(){
    return m_front; // Returns m_front
}
// getBack Function
GListNode* GDblList::getBack(){
    return m_back; // Returns m_back
}
