#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>
using namespace std;

typedef vector<int> v; 
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<int , int>>> vvpii;

/**
 * Create a graph from edges. 
 * Create a parent , fixed and distance array 
 * Push the source node and distance .  
 While pq is not empty =>
        if its fixed then continue;
        if not then check the egdes related to it . 
            Update the distance and the parent 
            Push in pq if only they are not fixed.
 
*/
vvpii prims(vvpii graph , int vertices){
    v parent (vertices, -1); 
    v fixed (vertices, false); 
    v distance(vertices , INT_MAX); 
    priority_queue<pair<int, int>, vector<pair<int , int>> , greater<pair<int, int>>> pq;
    distance[0] = 0; 
    pq.push({0 , 0});  // where first zero is weight so that it i can have smallest edge weight at the top. Second one is the vertex that have the resp wgt;

    while (!pq.empty())
    {
        int src = pq.top().second;
        pq.pop();
        if(fixed[src]) continue;
        fixed[src] = true;

        // every edge associated with the source edge
        for(auto edge : graph[src]){
            int dest = edge.first;
            int wgt = edge.second; 

            if(!fixed[dest] && distance[dest] > wgt){
                parent[dest] = src;
                distance[dest] = wgt;
                pq.push({wgt , dest});
            }
        }
    }
     vvpii mstGraph(vertices);
    for (int i = 1; i < vertices; ++i) {
        int u = parent[i];
        int v = i;
        int weight = distance[i];
        mstGraph[u].push_back({v, weight});
        mstGraph[v].push_back({u, weight});
    }

    return mstGraph;

}
v dijkstra(vvpii graph, int vertices) {
    v parent(vertices, -1); 
    v fixed(vertices, false);
    v distance(vertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  
    distance[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int src = pq.top().second;
        pq.pop();

        if (fixed[src]) continue;
        fixed[src] = true; 

        for (auto edge : graph[src]) {
            int dest = edge.first;
            int wgt = edge.second; 

            if (!fixed[dest] && distance[dest] > wgt + distance[src]) {
                distance[dest] = wgt + distance[src]; 
                parent[dest] = src; 
                pq.push({distance[dest], dest});
            } 
        }
    }
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < vertices; ++i)
        cout << i << " \t\t " << distance[i] << endl;
    return parent; 
}

void addEdge (vvpii & graph , int src , int dest , int  wgt){
    graph[src].push_back({dest, wgt});
    graph[dest].push_back({src, wgt});
}

int main (){
   vvi edges = {
        {0, 1, 1}, 
        {1, 2, 6}, 
        {2, 3, 6},
        {3, 4, 5},
        {4, 5, 4},
        {5, 0, 3},
        {1, 4, 7},
        {2, 4, 1},
    };
    
    int vertices = 6; 

    // for(auto it : edges){
    //     addEdge(graph, it[0], it[1], it[2]);
    // } 

   auto display = [](vvpii g) {
        for (int i = 0; i < g.size(); ++i) {
            cout << "Vertex " << i << " -> ";
            for (const auto& edge : g[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << endl;
        }
    };
    
   vvpii graph(vertices); 
    addEdge(graph , 0, 1, 3);
    addEdge(graph , 0, 5, 4);
    addEdge(graph , 1, 2, 5);
    addEdge(graph , 1, 4, 11);
    addEdge(graph , 1, 5, 1);
    addEdge(graph , 2, 3, 2);
    addEdge(graph , 2, 5, 4);
    addEdge(graph , 3, 4, 3);
    addEdge(graph , 4, 5, 1);
    
   
    display(graph);

   v parent = dijkstra(graph , vertices); 
   for(auto it : parent){
    cout<<it<<" "; 
    }
}