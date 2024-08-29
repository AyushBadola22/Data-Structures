#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

// Function to find the root of the set containing vertex `v` with path compression
int find(int v, vi &parent) {
    if (parent[v] < 0)
        return v; // If parent[v] is negative, `v` is the root
    return parent[v] = find(parent[v], parent); // Path compression optimization
}

// Function to union two sets containing vertices `u` and `v`
void unionOfSets(int u, int v, vi &parent) {
    int parent1 = find(u, parent);
    int parent2 = find(v, parent);

    if (parent1 == parent2)
        return; // If they are already in the same set, no need to union

    // Union by size: Attach the smaller tree under the root of the larger tree
    if (parent[parent1] < parent[parent2]) {
        parent[parent1] += parent[parent2]; // Update the size of the new root
        parent[parent2] = parent1; // Attach parent2 under parent1
    } else {
        parent[parent2] += parent[parent1]; // Update the size of the new root
        parent[parent1] = parent2; // Attach parent1 under parent2
    }
}

// Function to implement Kruskal's algorithm to find the Minimum Spanning Tree (MST)
vvi kruskal(vvi &edges, int V) {
    vi parent(V, -1); // Initialize each vertex as its own parent with a size of -1

    // Priority queue to sort edges by their weights in ascending order
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vvi mst; // To store the resulting MST

    // Push all edges into the priority queue
    for (auto &edge : edges) {
        int wgt = edge[2];
        int src = edge[0];
        int dest = edge[1];
        pq.push({wgt, {src, dest}});
    }

    // Process edges in order of their weights
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();

        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        // Check if the selected edge forms a cycle
        if (find(u, parent) != find(v, parent)) {
            unionOfSets(u, v, parent); // Union the sets containing u and v
            mst.push_back({u, v, w}); // Add the edge to the MST
        }
    }
    return mst;
}

//-------------------------------------- Driver Code --------------------------------------------//

int main() {
    vvi edges = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 2, 11},
        {1, 3, 6},
        {2, 4, 7},
        {3, 4, 9},
        {3, 5, 10},
        {4, 5, 12},
        {4, 6, 2},
        {5, 6, 5}
    };

    vvi mst = kruskal(edges, 7);
    for (auto &edge : mst) {
        cout << edge[0] << " to " << edge[1] << " with weight " << edge[2] << endl;
    }
    return 0;
}
