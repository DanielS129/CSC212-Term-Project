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

void BTree::print(int mode) {
  if (!root) {
    return;
  }


}

