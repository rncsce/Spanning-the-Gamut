#include "WGraph.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

int main(int argc, char** argv){
    string inputFile = argv[1];
    string m_line = ""; // Declare and intialize m_line string
    ifstream inFile(inputFile); // Initalize input file stream 
    WGraph *inputGraph; // Declare WGraph pointer
    
    int i = 0; // Declare and initialize integer, i to 0
    if(inFile.is_open()){
        getline(inFile, m_line); // Read first line
        unsigned int size = stoi(m_line); // Convert line to integer and then assign, declare, and intialize as size
        inputGraph = new WGraph(size); // Initalize WGraph object of size read
        while(getline(inFile, m_line) && i < size){ // While getline reads lines delimited by newline and i is less than size
            stringstream ss(m_line); // Initalize string stream on line
            string num; // Declare string num
            int j = 0; // Declare and initialize integer, j to 0
            while(ss >> num && j < size){ // While string stream reads numbers delimited by spaces and j is less than size
                if (num == "END"){ // If stream stream reads "END"
                    break; // Break out of loop
                }
                double dbl = stod(num); // Convert string read to double and then assign, declare, and intialize as dbl
                inputGraph -> addEdge(i, j, dbl); // Call WGraph's addEdge Function on i, j, and dbl
                ++j; // Increment j by 1
            }  
            ++i; // Increment i by 1
        }
    }
    inputGraph -> computeMST(); // Call WGraph's computeMST Function
    // inputGraph -> displayMST("Output.txt"); // Call WGraph's displayMST Function
    inputGraph -> displayMST(); // Call WGraph's displayMST Function

    if(inFile.is_open()){ // If file is open
        inFile.close(); // Close file
    }
    delete inputGraph; // Deallocate inputGraph

    return 0;
}
