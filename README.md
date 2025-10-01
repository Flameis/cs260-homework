# CS260 - Data Structures Course

This repository contains all assignments and projects completed for CS260 Data Structures course. The coursework covers fundamental data structures and algorithms implemented in C++, including dynamic data structures, search algorithms, and graph theory.

## Repository Structure

```
CS260/
├── README.md                  # This file
└── Src/                      # Source code directory
    ├── assignment0/          # Course introduction
    ├── assignment1/          # Bag of Marbles (Dynamic Arrays/Vectors)
    ├── assignment2/          # [Assignment content]
    ├── assignment3/          # Linked Queue Implementation
    ├── assignment4/          # Linked List Implementation
    ├── assignment6/          # Binary Search Tree
    ├── assignment7/          # Hash Table Implementation
    └── final/               # Graph Data Structure Implementation
```

## Assignments Overview

### Assignment 0 - Course Introduction
- **Purpose**: Getting started with the course
- **Files**: README.txt
- **Topics Covered**: Course setup and introduction

### Assignment 1 - Bag of Marbles
- **Purpose**: Implement a dynamic container using C++ classes
- **Key Files**:
  - `marbles.cpp` - Implementation of marble bag class
  - `marbles.exe` - Compiled executable
  - `README.md` - Documentation and requirements
- **Key Features**:
  - Dynamic marble storage using containers
  - `addMarble()` - Add marbles to the bag
  - `removeMarble()` - Remove random marble from bag
  - `isEmpty()` - Check if bag is empty
  - `getNumberOfMarbles()` - Get count of marbles
- **Topics Covered**: Classes, dynamic arrays/vectors, basic data structure operations


### Assignment 3 - Linked Queue
- **Purpose**: Implement a queue using linked list structure
- **Key Files**:
  - `queue.cpp` - Queue implementation using linked list
  - `queue.exe` - Compiled executable
  - `README.md` - Documentation with complexity analysis
  - Images: `image.png`, `image-1.png` through `image-4.png`
- **Key Features**:
  - Linked-list based queue storage
  - `enqueue()` - Add elements to rear of queue (O(1))
  - `dequeue()` - Remove elements from front of queue (O(1))
  - `peek()` - View front element without removal (O(1))
  - `isEmpty()` - Check if queue is empty (O(1))
- **Topics Covered**: Linked lists, queue ADT, pointer manipulation, time complexity analysis

### Assignment 6 - Binary Search Tree
- **Purpose**: Implement a binary search tree with full CRUD operations
- **Key Files**:
  - `binary_search_tree.cpp` - BST implementation
  - `binary_search_tree.h` - Header file
  - `binary_search_tree.exe` - Compiled executable
  - `README.MD` - Comprehensive documentation
  - Images: `image.png`, `image-1.png` through `image-3.png`
- **Key Features**:
  - Node structure with left/right pointers
  - `insert(value)` - Add nodes maintaining BST property
  - `search(value)` - Find nodes efficiently
  - `delete(value)` - Remove nodes with proper restructuring
  - `traverse()` - In-order, pre-order, post-order traversals
  - `get_root()` - Access root node
  - `locate_parent(value)` - Find parent of given value
- **Topics Covered**: Binary trees, recursive algorithms, tree traversals, search algorithms

### Assignment 7 - Hash Table
- **Purpose**: Implement hash table with collision handling
- **Key Files**:
  - `hashtable.cpp` - Basic hash table implementation
  - `hashtable.h` - Header file
  - `hashtable.exe` - Compiled executable
  - `smarter_hashtable.cpp` - Enhanced implementation
  - `smarter_hashtable.exe` - Enhanced executable
  - `main.cpp` - Test driver
  - `main.exe` - Test executable
  - `README.md` - Documentation with complexity analysis
  - Images: `image.png`, `image-1.png` through `image-5.png`
- **Key Features**:
  - Custom hash function using Unicode values and seed
  - `add(key)` - Insert with collision handling
  - `remove(key)` - Delete keys from table
  - `find(key)` - Search for keys
  - `getSize()` - Get number of stored keys
  - `getCapacity()` - Get table capacity
  - Dynamic resizing capabilities
- **Complexity Analysis**:
  - Insert: Best O(log n), Worst O(n)
  - Search: Best O(1), Worst O(n)
- **Topics Covered**: Hash functions, collision resolution, dynamic resizing, amortized analysis

### Final Project - Graph Data Structure
- **Purpose**: Implement graph with pathfinding and spanning tree algorithms
- **Key Files**:
  - `graph.cpp` - Graph implementation
  - `graph.h` - Header file
  - `graph.exe` - Compiled executable
  - `README.md` - Comprehensive documentation
  - Images: `image.png`, `image-1.png` through `image-4.png`
- **Key Features**:
  - Adjacency list representation
  - `add_vertex(vertex)` - Add new vertices
  - `add_edge(source, destination, weight)` - Add weighted edges
  - `shortest_path(source, destination)` - Dijkstra's algorithm implementation
  - `min_span_tree()` - Prim's algorithm for minimum spanning tree
- **Applications**: Game world navigation, AI pathfinding, network optimization
- **Topics Covered**: Graph theory, Dijkstra's algorithm, Prim's algorithm, priority queues

## Technologies Used

- **Language**: C++
- **Compiler**: g++ (MinGW-w64)
- **Development Environment**: VS Code with C++ extensions
- **Version Control**: Git
- **Build System**: Manual compilation with g++

## Getting Started

### Prerequisites
- C++ compiler (g++ recommended)
- Text editor or IDE (VS Code recommended)
- Basic understanding of C++ and data structures

### Building and Running

#### Individual Assignments
1. Navigate to the assignment directory:
   ```bash
   cd Src/assignment[number]/
   ```

2. Compile the C++ source:
   ```bash
   g++ -o program_name source_file.cpp
   ```

3. Run the executable:
   ```bash
   ./program_name
   ```

#### Using VS Code Task (Recommended)
1. Open the source file in VS Code
2. Use the build task: `C/C++: g++.exe build active file`
3. Run the generated executable

### Example Commands
```bash
# Assignment 1 - Marbles
cd Src/assignment1/
g++ -o marbles marbles.cpp
./marbles

# Assignment 6 - Binary Search Tree
cd Src/assignment6/
g++ -o binary_search_tree binary_search_tree.cpp
./binary_search_tree

# Final Project - Graph
cd Src/final/
g++ -o graph graph.cpp
./graph
```

## Course Learning Objectives

This repository demonstrates proficiency in:

- ✅ **Dynamic Data Structures**: Arrays, linked lists, trees, graphs
- ✅ **Algorithm Design**: Search, insertion, deletion, traversal algorithms
- ✅ **Time Complexity Analysis**: Big O notation, best/worst case analysis
- ✅ **Memory Management**: Dynamic allocation, pointers, destructors
- ✅ **Object-Oriented Programming**: Classes, encapsulation, abstraction
- ✅ **Advanced Algorithms**: Dijkstra's shortest path, Prim's MST
- ✅ **Problem Solving**: Real-world applications of data structures

## Assignment Status

| Assignment | Status | Key Data Structure | Complexity |
|------------|--------|-------------------|------------|
| Assignment 0 | ✅ Complete | Introduction | - |
| Assignment 1 | ✅ Complete | Dynamic Array/Vector | O(1) add/remove |
| Assignment 2 | 🚧 Pending | TBD | - |
| Assignment 3 | ✅ Complete | Linked Queue | O(1) operations |
| Assignment 4 | 🚧 In Progress | Linked List | O(n) search |
| Assignment 6 | ✅ Complete | Binary Search Tree | O(log n) average |
| Assignment 7 | ✅ Complete | Hash Table | O(1) average |
| Final Project | ✅ Complete | Graph | O(V log V + E) paths |

## Key Concepts Covered

### Data Structures
- **Linear**: Arrays, Linked Lists, Stacks, Queues
- **Non-Linear**: Binary Trees, Binary Search Trees, Graphs
- **Hash-Based**: Hash Tables with collision resolution

### Algorithms
- **Searching**: Linear search, binary search, hash-based lookup
- **Tree Operations**: Insertion, deletion, traversal (in-order, pre-order, post-order)
- **Graph Algorithms**: Dijkstra's shortest path, Prim's minimum spanning tree
- **Sorting**: Implicit in BST operations

### Advanced Topics
- **Time Complexity**: Analysis of algorithm efficiency
- **Space Complexity**: Memory usage optimization
- **Collision Handling**: Hash table collision resolution strategies
- **Graph Theory**: Pathfinding and spanning tree applications

## Testing and Validation

Each assignment includes comprehensive testing:
- **Unit Tests**: Individual function validation
- **Integration Tests**: Complete data structure operations
- **Edge Cases**: Empty structures, boundary conditions
- **Performance Tests**: Time complexity verification

## Notes

- All implementations use standard C++ without external libraries
- Code follows C++ best practices and coding standards
- Each assignment builds upon previous concepts progressively
- Documentation includes complexity analysis and visual diagrams
- Executables are provided for immediate testing

## Author

**Course**: CS260 Data Structures  
**Academic Year**: 2023  
**Institution**: Oregon State University  
**Student**: Luke Scovel

---
