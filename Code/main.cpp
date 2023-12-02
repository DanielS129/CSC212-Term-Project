#include <iostream>
#include <fstream>
#include <sstream>

void print_tree(BTree* tree, int mode);

// Providing a general layout of main.cpp
// <file_name> <traversal_method>
int main(int argc, char*argv[]){
    std::ifstream ifs(argv[1]);
    int mode = std::stoi(argv[2]);

    BTree tree;

    std::string line;

    // Get the numbers to be inserted
    std::getline(ifs, line);
    std::stringstream ss(line);

    int num;
    // Insert the numbers
    while(ss >> num){
        tree.insert(num);
        print_tree(&tree, mode);
    }

    // Get the numbers to be removed
    std::getline(ifs, line);
    ss.clear();
    ss.str(line);

    // Remove the numbers
    while(ss >> num){
        tree.remove(num);
        print_tree(&tree, mode);
    }
}
