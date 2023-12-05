#include "bTree.h"

/*
  BTree Class Implementation
*/

/*
  Private Functions
*/

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
      BTNode* child = node->children[i];
      BTNode* newChild = new BTNode(Degree, child->isLeaf);

      node->keys.insert(node->keys.begin() + i, child->keys[Degree - 1]);
      newChild->keys.assign(child->keys.begin() + Degree, child->keys.end());
      child->keys.erase(child->keys.begin() + Degree - 1, child->keys.end());

      if (!child->isLeaf) {
        newChild->children.assign(child->children.begin() + Degree, child->children.end());
        child->children.erase(child->children.begin() + Degree, child->children.end());
      }

      node->num++;
      child->num = Degree - 1;
      node->children.insert(node->children.begin() + i + 1, newChild);
    }
  }
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

/*
  Public Functions
*/

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

bool BTree::search(const std::string& key) {
  if (!root) {
    return false;
  }
  return searchR(root, key);
}

void BTree::print(int mode) {
  if (!root) {
    return;
  }
  std::cout << "" << std::endl;
  printR(root);
  std::cout << std::endl;
}

/*
  Functions That will not be used in this Program
  
  *Note: In a real world situation this code is needed and is part of this Class
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
