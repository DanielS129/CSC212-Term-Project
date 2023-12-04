#include "bTree.h"

BTree::BTree() {
  root = nullptr;
}

void BTree::insert(const std::string& key) {
  if (!root) {
    root = new BTNode(true);
  }
  insertR(root,key);
}

void BTree::insertR(BTNode* node, const std::string& key) {
  if (node->isLeaf) {
    // if node is a leaf, insert key into this node
  } else {
    // find child node to insert to
    // recursive call
  }
}

void BTree::remove(const std::string& key) {
  if (!root) {
    return;
  }
  removeR(root, key);
}

void BTree::removeRec(BTNode* node, const std::string& key) {
  if (node->isLeaf) {
    // node is a leaf, remove the key from this node
  } else {
    // find the child node where the key might be
    // recursive call 
  }
}


bool BTree::search(const std::string& key) {
  if (!root) {
    return false;
  }
  return searchR(root, key);
}

bool BTree::searchRec(BTNode* node, const std::string& key) {
  // Search logic
  // true if found, false otherwise
}

void BTree::print(int mode) {
  if (!root) {
    return;
  }
  std::cout << "" << std::endl;
  printR(root);
  std::cout << std::endl;
}

void BTree::printRec(BTNode* node) {
  if (node) {
    for (int i = 0; i < node->keys.size(); ++i) {
      if (!node->isLeaf) {
        printR(node->children[i]);
      }
      std::cout << node->keys[i] << " ";
    }
    if (!node->isLeaf) {
      printR(node->children.back());
    }
  }
}
