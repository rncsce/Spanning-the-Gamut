#include "WGraph.h"
#include <iomanip>
// Default Constructor
WGraph::WGraph(){
    m_size = 0; // Initialize m_size to 0
    m_adj = NULL; // Initialize m_adj Matrix to NULL
    m_conn = NULL; // Initialize m_conn Matrix to NULL
    m_totalCost = 0; // Initalize m_total Cost to 0
    gMinQueue = NULL; // Initalize gMinQueue to NULL
}
// Overloaded Constructor
WGraph::WGraph(unsigned int sz){ // Parmeters: Graph's size
    m_size = sz; // Initialize m_size to sz paramter
    // Allocate sz * sz adj matrix
    m_adj = new double*[sz]; // Initalize m_adj with an array of pointers 
    m_conn = new double *[sz]; // Initalize m_conn with an array of pointers 
    for(int i = 0; i < m_size; ++i){ // For m_size iterations
        m_adj[i] = new double[sz]; // Set m_adj at index i to new array of parameter size
        m_conn[i] = new double[sz]; // Set m_conn at index i to new array of parameter size
    }
    for(int i = 0; i < m_size; ++i){ // For m_size iterations
        for(int j = 0; j < m_size; ++j){  // For m_size iterations
            m_adj[i][j] = std::numeric_limits<double>::max(); // Essentially infinity // Set m_adj at i, j to infinity
            m_conn[i][j] = std::numeric_limits<double>::max(); // Set m_conn at i, j to infinity
        }
    }
    m_totalCost = 0; // Initalize m_total Cost to 0
    gMinQueue = new GPQueue(true); // Initialize gMinQueue to new Graph Priority Queue
}
// Default Deconstructor 
WGraph::~WGraph(){
    for(int i = 0; i < m_size; ++i){ // For m_size iterations
        delete[] m_adj[i]; // Delete array at m_adj[i]
    }
    delete[] m_adj; // Delete m_adj array
    for(int i = 0; i < m_size; ++i){ // For m_size iterations
        delete[] m_conn[i]; // Delete array at m_conn[i]
    }
    delete[] m_conn; // Delete m_conn array
    delete gMinQueue; // Delete gMinQueue
}
// addEdge Function
void WGraph::addEdge(VertexID i, VertexID j, double w){ // Parameters: left vertex, right vertex, weight
    if(i < m_size && j < m_size){ // If i is less than m_size and j is less than m_size 
        m_adj[i][j] = w; // Set m_adj[i][j] to weight parameters
        m_adj[j][i] = w; // Set m_adj[j][i] to weight parameters
    }
}
// removeEdge Function
void WGraph::removeEdge(VertexID i, VertexID j){ // Parameters: left vertex, right vertex
    if(i < m_size && j < m_size){ // If i is less than m_size and j is less than m_size 
        m_adj[i][j] = std::numeric_limits<double>::max(); // Set m_adj[i][j] to infinity
        m_adj[j][i] = std::numeric_limits<double>::max(); // Set m_adj[j][i] to infinity
    }
}
// areAdjecent Function
bool WGraph::areAdjacent(VertexID i, VertexID j){ // Parameters: left vertex, right vertex
    return(m_adj[i][j] < std::numeric_limits<double>::max()); // Return if weight at  m_adj[j][i] is less than infinity
}
// calcFW Function
void WGraph::calcFW(){ // Runtime complexity O(V^3)
    for(int i = 0; i < m_size; ++i){
        for(int j = 0; j < m_size; ++j){
            m_conn[i][j] = m_adj[i][j]; // Start with conn = adj matrix
        }
    }
    for(int im = 0; im < m_size; ++im){ // Intermediate points -> Transitive closure
        for(int source = 0; source < m_size; ++source){ // Source = starting point
            for(int sink = 0; sink < m_size; ++sink){ // Sink = ending point
                if(source == sink){
                    continue;
                } else if (m_conn[source][sink] != std::numeric_limits<double>::max() &&
                m_conn[im][sink] != std::numeric_limits<double>::max() && 
                m_conn[im][sink] != std::numeric_limits<double>::max()){
                    m_conn[im][sink] = m_conn[source][im] + m_conn[im][sink];
                }
            }
        }
    }
}
// cheapestCost Function
double WGraph::cheapestCost(VertexID i, VertexID j){ // Parameters: left vertex, right vertex
    return m_conn[i][j]; // Return m_conn[i][j]
}
// computeMST Function
void WGraph::computeMST(){
    for(int i = 0; i < m_size; i++){ // For m_size iterations
        for(int j = 0; j < m_size; j++){ // For m_size iterations
            gMinQueue -> add(i, j, m_adj[i][j]); // Add edge to gMinQueue
        }
    }
    set<set<int>*>* visitedSets = new set<set<int>*>; // Declare and intitalize set pointer of set of integer pointers
    while(gMinQueue -> size() > 0){ // While gMinQueue's size is greater than 0
        bool found = false; // Declare and initalize found variable to false
        int currLeftVertex = gMinQueue -> getFrontLeftVertex(); // Declare and initalize currLeftVertex integer to gMinQueue's front left vertex
        int currRightVertex = gMinQueue -> getFrontRightVertex(); // Declare and initalize currRightVertex integer to gMinQueue's front right vertex
        double currWeight = gMinQueue -> getFrontEdgeWeight(); // Declare and initalize currEdgeWeight integer to gMinQueue's front edge weight
        gMinQueue -> remove(); // Remove front from gMinQueue
        if (visitedSets -> empty() != true){ // If visistedSet is not empty
            for (auto islandSet : *visitedSets){ // Iterate through sets in visitedSet
                if ((islandSet -> count(currRightVertex) == 1) && (islandSet -> count(currLeftVertex) == 1)){ // If right vertes and left vertex are found in same set
                    found = true; // Set found to true
                    break; // Break out of loop
                } 
            }
            if (found == false){ // If right vertes and left vertex were not found in same set
                for (auto islandSet : *visitedSets){  // Iterate through sets in visitedSet
                    if (islandSet -> count(currLeftVertex) == 1){ // If left vertex found in a set
                        found = true; // Set found to true
                        for(auto islandSet2 : *visitedSets){ // Iterate through sets in visitedSet (looking through all sets for right vertex)
                            if (islandSet2 -> count(currRightVertex) == 1){ // If right vertex found in a set
                                for (auto num : *islandSet2){ // Iterate through the second found set's numbers
                                    islandSet -> insert(num); // Add each number to first found set
                                }
                                visitedSets -> erase(islandSet2); // Erase second found set from visitedSets
                                delete islandSet2; // Delete second found set from visitedSEts
                                break; // Break out of loop
                            }
                        }
                        m_conn[currLeftVertex][currRightVertex] = currWeight; // Set m_con at left and right indicies to current weight
                        m_conn[currRightVertex][currLeftVertex] = currWeight; // Set m_con at right and left indicies to current weight
                        break; // Break out of loop
                    }
                    if (islandSet -> count(currRightVertex) == 1){  // If left vertex found in a set
                        found = true; // Set found to true
                        for(auto islandSet2 : *visitedSets){  // Iterate through sets in visitedSet (looking through all sets for right vertex)
                            if (islandSet2 -> count(currLeftVertex) == 1){  // If left vertex found in a set 
                                for (auto num : *islandSet2){ // Iterate through the second found set's numbers
                                    islandSet -> insert(num); // Add each number to first found set
                                }
                                visitedSets -> erase(islandSet2); // Erase second found set from visitedSets
                                delete islandSet2; // Delete second found set from visitedSEts
                                break; // Break out of loop
                            }
                        }
                        m_conn[currLeftVertex][currRightVertex] = currWeight; // Set m_con at left and right indicies to current weight
                        m_conn[currRightVertex][currLeftVertex] = currWeight; // Set m_con at right and left indicies to current weight
                        break; // Break out of loop
                    } 
                }
            }
        }
        if (found == false){ // If both left and righ verticies were not found in visitedSets' sets
            m_conn[currLeftVertex][currRightVertex] = currWeight; // Set m_con at left and right indicies to current weight
            m_conn[currRightVertex][currLeftVertex] = currWeight; // Set m_con at right and left indicies to current weight
            set<int>* newSet = new set<int>{currLeftVertex, currRightVertex}; // Create new set pointer of integers
            visitedSets -> insert(newSet); // Add set to visistedSets
            found = true; // Set found to true
        }
    }
    for(auto set : *visitedSets){ // For each set in visistedSets
        delete set; // Delte set
    }
    delete visitedSets; // Delete visitedSets
}
// displayMST Function
void WGraph::displayMST(){ // 
    cout << calcTotalCost() << ".0" << endl; // Output returned value of calcTotalCost Function
    for(int i = 0; i < m_size; ++i){ // For m_size iterations
        for(int j = 0; j < m_size; ++j){ // For m_size iterations
            if(m_conn[i][j] != numeric_limits<double>::max()){ // If m_conn[i][j] is not infinity
                cout << m_conn[i][j] << ".0 "; // Output m_conn[i][j] to output file
            } else { // If m_conn[i][j] is infinity
                cout << "0.0 "; // If output 0.0 in place
            }
        }
        cout << endl; // Output new line after each row (outer loop iteration)
    }
}
// displayMST Overloaded Function
void WGraph::displayMST(const string& fileName){ // Parameter: file name
    ofstream outFile(fileName); // Initialize output file stream on parameter
    outFile << calcTotalCost() << ".0" << endl; // Output returned value of calcTotalCost Function
    for(int i = 0; i < m_size; ++i){ // For m_size iterations
        for(int j = 0; j < m_size; ++j){ // For m_size iterations
            if(m_conn[i][j] != numeric_limits<double>::max()){ // If m_conn[i][j] is not infinity
                outFile << m_conn[i][j] << ".0 "; // Output m_conn[i][j] to output file
            } else { // If m_conn[i][j] is infinity
                outFile << "0.0 "; // If output 0.0 in place
            }
        }
        outFile << endl; // Output new line after each row (outer loop iteration)
    }
    if (outFile.is_open()){ // If outFile is open
        outFile.close(); // Close outFile
    }
}
// calcTotalCost Function
double WGraph::calcTotalCost(){
    m_totalCost = 0;
    for(int i = 0; i < m_size; ++i){ // For m_size iterations
        for(int j = 0; j < m_size; ++j){ // For m_size iterations
            if (m_conn[i][j] != numeric_limits<double>::max()){ // If m_conn[i][j] is not infinity
                m_totalCost += m_conn[i][j]; // Add m_conn[i][j]'s weight to m_totalCost
            }
        }
    } 
    return m_totalCost / 2; // Return m_totalCost divide by 2 (counts [i][j] and [j][i] connections that are same edge)
}
