#include <iostream>
#include <vector>
#include <fstream>

/*
    B-Tree Node Class
*/

/*
    Notes : 
        For Our implementation of this BTree our data will be in Strings. Not Integers
        Our Sorting/How we will insert will be done using Lexicographic order
    Rules :
        - 

*/

class BTNode{
    private:
        int DEGREE; // Will Represent t, The range for # of Keys
        int num; // Represents the Current # of Keys
        std::string *keys; // Will represent the list of the "Data"
        BTNode **children; // Will represent a list of Node Pointers.
        bool isLeaf; // Is true when node is leaf. Otherwise false
        
        friend class BTree;
    public:
        BTNode(int degree, bool isleaf);  
        ~BTNode();
};