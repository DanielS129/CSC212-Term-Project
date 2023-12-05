#include "bTree.h"

// BTree Class Implementation

// Private Functions

void BTree::splitNode(BTNode* parent, int index, BTNode* child){
  // Create a new node which is going to store (DEGREE - 1) keys of 'child'
    BTNode* newNode = new BTNode(child->DEGREE, child->isLeaf);
    newNode->num = Degree - 1;

    // Copy the last (DEGREE - 1) keys of 'child' to 'newNode'
    for (int j = 0; j < Degree - 1; j++) {
        newNode->keys[j] = child->keys[j + Degree];
    }

    // Copy the last DEGREE children of 'child' to 'newNode'
    if (!child->isLeaf) {
        for (int j = 0; j < Degree; j++) {
            newNode->children[j] = child->children[j + Degree];
        }
    }

    // Reduce the number of keys in 'child'
    child->num = Degree - 1;

    // Since this node is going to have a new child,
    // create space for the new child
    for (int j = parent->num; j >= index + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }

    // Link the new child to this node
    parent->children[index + 1] = newNode;

    // A key of 'child' will move to this node. Find the location of
    // the new key and move all greater keys one space ahead
    for (int j = parent->num - 1; j >= index; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }

    // Copy the middle key of 'child' to this node
    parent->keys[index] = child->keys[Degree - 1];

    // Increment the number of keys in this node
    parent->num++;
}

//Function for insertion recursively + Finsih Split Node Function
void BTree::insertR(BTNode* node, const std::string& key) {
  // If the node is a leaf, insert the key directly into the node
  if (node->isLeaf) {
    int i;
    for (i = node->num - 1; (i >= 0 && node->keys[i] > key); i--) {
      node->keys[i + 1] = node->keys[i]; // Shift keys to the right
    }
    node->keys[i + 1] = key; // Insert the new key
    node->num++; // Increment the number of keys in the node
  }else{
    // If the node is not a leaf, find the child which is going to have the new key
    int i = node->num - 1;
    while (i >= 0 && node->keys[i] > key) {
      i--;
    }
    // Check if the found child is full
    if (node->children[i + 1]->num == 2 * this->Degree - 1) {
      // Split the full child node
        splitNode(node, i, node->children[i]);

        // After splitting, the middle key of node->children[i] goes up and
        // node is split into two. Decide which of the two is going to have the new key
        if (key > node->keys[i]) {
            i++;
        }
    }
    insertR(node->children[i + 1], key); // Recursively insert the key in the appropriate child
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
// Creating basic preorder/inorder/postorder functions for implementation
void BTree::preorder(std::ostream& os){
    preorder(root, os);
    std::cout << std::endl;
}

void BTree::inorder(std::ostream& os){
    inorder(root, os);
    std::cout << std::endl;
}

void BTree::postorder(std::ostream& os){
    postorder(root, os);
    std::cout << std::endl;
}



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
