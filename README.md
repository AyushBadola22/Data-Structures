# Data Structures

## Table of Contents
- [Graphs](#graphs)
  - [Kruskal's Algorithm](#kruskals-algorithm)

---

## Graphs

### Kruskal's Algorithm

<details>
  <summary>Expand explanation of Kruskal's Algorithm</summary>  <br>
   
  **Overview**: Kruskal's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a graph. It works by selecting the minimum weight edges and adding them to the MST, ensuring no cycles are formed. Cycle detection is managed using a disjoint set data structure.

  **Procedure**:
  1. **Priority Queue**: Insert all edges into a priority queue (or use a sorted list). This allows quick access to the smallest available edge.
  2. **Cycle Check and MST Construction**: Extract the smallest edge. If adding this edge to the MST does not form a cycle, include it. Otherwise, discard it. Cycle detection is efficiently handled using the `find()` and `union()` operations of the disjoint set.
  3. **Output MST**: Continue until the MST includes \(V-1\) edges (where \(V\) is the number of vertices).

  **Disjoint Set Operations**:
  - **Find Operation**: Determines the root representative (ultimate parent) of the set to which a particular element belongs. This is used to check if two vertices belong to the same set, indicating the potential to form a cycle.
  - **Union Operation**: Merges two disjoint sets into one. This is performed when an edge connects two vertices from different sets, thus safely adding the edge to the MST without forming a cycle.

  **Disjoint Set Data Structure**:
  - Two sets are called disjoint if there intersection is null . 
    Those two sets doesn't have any common element. 


- It supports the `find()` operation to identify the set of a particular element and the `union()` operation to merge two sets.
- In context of the Krushkal `find()`  determines the root parent of the node and `union()` join two subtrees(subsets).

</details>
<br>
Implementation

- [Kruskal's Algorithm C++](https://github.com/AyushBadola22/Data-Structures/blob/main/krushkal.cpp) 
- [Kruskal's Algorithm Python](https://github.com/AyushBadola22/Data-Structures/blob/main/krushkal.py) 

---

`