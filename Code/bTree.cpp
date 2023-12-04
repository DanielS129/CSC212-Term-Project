#include "bTree.h"

BTree::BTree() {
  root = nullptr;
}

BTree::~BTree() {
  delete root;
}

void BTree::insert(const std::string& key) {
  if (!root) {
    root = new BTNode(true);
  }
  insertR(root,key);
}

void BTree::insertR(BTNode* node, const std::string& key) {
  int i = 0;
  if (node->isLeaf) {
    // If node is a leaf, insert key into this node
    node->keys.push_back(key);
  }
  else {
    // Find child node to insert to   
    while (i < node->keys.size() && key > node->keys[i]) {
      i++;
    }
    insertR(node->children[i], key);
    // Handle the case when the child node is full
    if (node->children[i]->keys.size() > MAX_KEYS) {
      
    }
  }
}
void BTree::remove(const std::string& key) {
  if (!root) {
    return;
  }
  removeR(root, key);
}

void BTree::removeR(BTNode* node, const std::string& key) {
  int i = 0;
  if (node->isLeaf) {
    // If node is a leaf, remove the key from this node
    for (int i = 0; i < node->keys.size(); ++i) {
      if (node->keys[i] == key) {
        node->keys.erase(node->keys.begin() + i);
        return;
      }
    }
  }
  else {
    // Find the child node where the key might be
    int i = 0;
    while (i < node->keys.size() && key > node->keys[i]) {
      i++;
    }
    removeR(node->children[i], key);
    // Handle the case when the child node has too few keys
    if (node->children[i]->keys.size() < MIN_KEYS) {
      
    }
  }
}


bool BTree::search(const std::string& key) {
  if (!root) {
    return false;
  }
  return searchR(root, key);
}

bool BTree::searchR(BTNode* node, const std::string& key) {
  int i = 0;
  while (i < node->keys.size() && key > node->keys[i]) {
    i++;
  }
  if (i < node->keys.size() && key == node->keys[i]) {
    return true; // True if found, false otherwise
  }
  else if (node->isLeaf) {
    return false;
  }
  else {
    return searchR(node->children[i], key); // Recursively search 
  }
}

void BTree::print(int mode) {
  if (!root) {
    return;
  }
  std::cout << "" << std::endl;
  printR(root);
  std::cout << std::endl;
}

void BTree::printR(BTNode* node) {
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
