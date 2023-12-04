#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>
#include <fstream>

/*
    B-Tree Class
*/

/*
    Rules :
        -

*/

class BTree {
private:
    BTNode* root;

public:
    BTree();
    ~BTree();

    void insert(const std::string& key);
    void remove(const std::string& key);
    bool search(const std::string& key);
    void print(int mode);
};

#endif
