#include "bTree.h"

BTree::BTree() {
  root = nullptr;
}

BTree::BTree() {
}

void BTree::insert(const std::string& key) {
  if (!root) {
    root = new BTNode(true);
  }
  // insertion logic
}

void BTree::remove(const std::string& key) {
  if (!root) {
    return;
  }
  // removal logic
}

bool BTree::search(const std::string& key) {
    // Implement the search logic 
}


void BTree::print(int mode) {
  if (!root) {
    return;
  }


}

