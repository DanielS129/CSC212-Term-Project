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
    void insertRec(BTNode* node, const std::string& key);
    void removeRec(BTNode* node, const std::string& key);
    bool searchRec(BTNode* node, const std::string& key);
    void printRec(BTNode* node);
};

#endif
