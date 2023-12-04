#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "bt.Node.h"

/*
    B-Tree Class
*/

/*
    Rules :
        -

*/

class BTree {
public:
    BTree();
    ~BTree();
    void insert(const std::string& key);
    void remove(const std::string& key);
    bool search(const std::string& key);
    void print();
};
private:
    BTNode* root;
    void insertR(BTNode* node, const std::string& key);
    void removeR(BTNode* node, const std::string& key);
    bool searchR(BTNode* node, const std::string& key);
    void printR(BTNode* node);
};

#endif
