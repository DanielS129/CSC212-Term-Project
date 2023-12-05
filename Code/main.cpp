#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "bTree.h"

// Providing a general layout of main.cpp

int main(int argc, char*argv[]){
    int degree = std :: stoi(argv[1]);

    BTree tree(degree);

    //Will insert the Data into the Tree
    std::ifstream data_file(argv[2]);
    std::string name;
    while (std::getline(data_file, name)) {
        std :: cout << name << "1\n";
        tree.insert(name);
        std :: cout << name << "2\n";
    }
    data_file.close();

    //Will Search through the Tree to see if tree is found
    std::ifstream search_file(argv[3]);
    while (std::getline(search_file, name)) {
        int count = tree.search(name);
        std::cout << "The key \"" << name << "\" was found " << count << " times in the B-Tree." << std::endl;
    }
    search_file.close();

    //Will print out the Tree
    tree.traverse();

    //Will Generate a DOT File
    tree.generate_dot();

    return 0;
}
