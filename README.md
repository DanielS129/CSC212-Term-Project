# CSC212-Term-Project
Here is our Group Consisting of:
- Daniel Sevilla
- Mithilesh Pabba
- Joseph Fernandez
- Danny Tran


# Description
## B-Tree
A B-Tree (also known as Balanced Tree) is a self-balancing tree designed to overcome the limitations of traditional binary search trees. Unlike binary trees, B-Trees can store multiple keys in a single node, leading to a larger branching factor and shallower height. Shallow height results in faster search and insertion operations, making B-Trees ideal for storage systems with slow data access (e.g., hard drives, flash memory, CD-ROMs).
### Common Used For: 
- Databases: B-Trees store indexes for efficient data searching and retrieval.
- File Systems: B-Trees organize and store files efficiently.
- Operating Systems: B-Trees manage memory efficiently.
- CAD Systems: B-Trees organize and search geometric data.
- Natural Language Processing, Computer Networks, and Cryptography also utilize B-Trees.

## Dependencies
- C++ Compiler (e.g., g++, clang++)

## Compilation Instructions
To compile the B-tree project, follow these steps:

1. **Clone the Repository**
2. **Compile the Code**
- If you are compiling manually, run:
  ```
  g++ -o BTree main.cpp BTree.cpp BTNode.cpp -std=c++11
  ```
3. **Run the Executable**

## Project Structure
- `main.cpp`: The entry point of the application.
- `BTree.cpp`: Implementation of the B-tree class.
- `BTNode.cpp`: Implementation of the B-tree node class.