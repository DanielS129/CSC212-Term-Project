#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "btNode.h"

/*
    B-Tree Class
    ------------
    Rules:
    - Each node contains keys in a sorted order.
    - The number of keys in every node must be at least t-1 and at most 2*t-1.
    - All leaves are at the same level.
    - A non-leaf node with k keys must have k+1 children.

    Note: For this Code we aren't needed to do the Remove Function. Will be Commented Out
*/

class BTree {
    private:
        BTNode* root;
        int Degree;

        void splitNode(BTNode* parent, int index, BTNode* child);
        //void removeR(BTNode* node, const std::string& key);
        void insertR(BTNode* node, const std::string& key);
        int searchR(BTNode* node, const std::string& key, int& count);
        void traverseR(BTNode* node);

        void generate_dot_aux(BTNode* node, std::ofstream& out);
    public:
        BTree(int degree);
        ~BTree();

        //void remove(const std::string& key);
        void insert(const std::string& key);
        int search(const std::string& key);
        void traverse();

        void generate_dot();
        
};

#endif
