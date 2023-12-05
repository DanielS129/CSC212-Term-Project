#include "bTree.h"

// BTree Class Implementation

// Private Functions

//Function for insertion recursively + Finsih Split Node Function
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

int BTree::searchR(BTNode* node, const std::string& key, int& count) {
  int i = 0;
  while (i < node->num && key > node->keys[i]) {
    i++;
  }
  if (i < node->num && key == node->keys[i]) {
    count++; // Increment the count if the key is found
    // Continue searching in the right subtree in case of duplicates
    if (!node->isLeaf) {
      searchR(node->children[i + 1], key, count);
    }
    return count; // Return the count of the key
  } else if (node->isLeaf) {
    return count; // Return the count (which will be 0 if the key is not found)
  } else {
    // Recursively search the appropriate child node
    return searchR(node->children[i], key, count);
  }
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

// Public Functions

BTree::BTree(int degree) {
  this->root = nullptr;
  this->Degree = degree;
}

BTree::~BTree() {
  delete this->root;
}

void BTree::insert(const std::string& key) {
  if (!root) {
    root = new BTNode(Degree, true);
  }
  insertR(root,key);
}

int BTree::search(const std::string& key) {
  int count = 0;
  if (root) {
    count = searchR(root, key, count);
  }
  return count;
}

void BTree::print() {
  if (!root) {
    return;
  }
  std::cout << "" << std::endl;
  printR(root);
  std::cout << std::endl;
}

/*
  Functions That will not be used in this Program
  
  Note: In a real world situation this code is needed and is part of this Class
  but for this case We won't use them. 
  For this Program ONLY
*/

// void BTree::remove(const std::string& key) {
//   if (!root) {
//     return;
//   }
//   removeR(root, key);
// }

// void BTree::removeR(BTNode* node, const std::string& key) {
//   int i = 0;
//   if (node->isLeaf) {
//     // If node is a leaf, remove the key from this node
//     for (int i = 0; i < node->keys.size(); ++i) {
//       if (node->keys[i] == key) {
//         node->keys.erase(node->keys.begin() + i);
//         return;
//       }
//     }
//   }
//   else {
//     // Find the child node where the key might be
//     int i = 0;
//     while (i < node->keys.size() && key > node->keys[i]) {
//       i++;
//     }
//     removeR(node->children[i], key);
//     // Handle the case when the child node has too few keys
//     if (node->children[i]->keys.size() < MIN_KEYS) {
      
//     }
//   }
// }
