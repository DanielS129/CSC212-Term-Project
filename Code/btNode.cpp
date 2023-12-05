#include "btNode.h"

// BTNode Class Implementation 

// Public Functions

BTNode :: BTNode(int degree, bool isleaf){
    this->DEGREE = degree;
    this->isLeaf = isleaf;
    this->num = 0;

    // Allocate memory for keys and children pointers
    keys = new std::string[2 * DEGREE - 1]; // Max keys in a node is 2*t - 1

    // Initialize keys to empty strings
    for (int i = 0; i < 2 * DEGREE - 1; ++i) {
        keys[i] = std::string();
    }
    
    children = new BTNode*[2 * DEGREE]; // Max children is 2*t
    
    // Initialize children pointers to nullptr
    for (int i = 0; i < 2 * DEGREE; ++i) {
        children[i] = nullptr;
    }
}

BTNode :: ~BTNode(){
    delete[] keys; // Deallocate keys array
    // Recursively delete child nodes
    for (int i = 0; i <= num; ++i) {
        delete children[i];
    }
    delete[] children; // Deallocate children pointers array
}
