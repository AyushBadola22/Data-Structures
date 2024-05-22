//******************  Libraries  *****************************
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

typedef vector<pair<int, pair<int, int>>> vppii;
typedef vector<int> vi; 

//******************* Graph by Vector of tuples  *********************
void dfsutil(vector<tuple<int, int, int>> graph, vector<bool> &visited, int vertex)
{
    visited[vertex] = true;
    for (auto edge : graph)
    {
        int source = get<1>(edge);
        int destination = get<2>(edge);
        if (!visited[destination] && source == vertex)
        {
            dfsutil(graph, visited, destination);
        }
    }

    cout << vertex << " ";
}

void dfs(vector<tuple<int, int, int>> graph, int numberOfVertices)
{
    vector<bool> visited(numberOfVertices, false);
    for (auto edge : graph)
    {
        int source = get<1>(edge);
        if (!visited[source])
        {
            dfsutil(graph, visited, source);
        }
    }
}

void addEdge(vector<tuple<int, int, int>> &graph, int source, int destination, int weight)
{
    graph.emplace_back(weight, source, destination);
    graph.emplace_back(weight, destination, source);
}

//******************* Graph by Vector of pair of pair  *********************
void addEdge(vector<pair<int, pair<int, int>>> &graph, int source, int destination, int weight)
{
    graph.push_back({weight, {source, destination}});
    graph.push_back({weight, {destination, source}});
}

void dfsutil(vector<pair<int, pair<int, int>>> graph, vector<bool> &visited, int vertex)
{
    visited[vertex] = true;
    for (auto edge : graph)
    {
        int source = edge.second.first;
        int destination = edge.second.second;
        if (!visited[destination] && source == vertex)
        {
            dfsutil(graph, visited, destination);
        }
    }
    cout << vertex << " ";
}

void dfs(vector<pair<int, pair<int, int>>> graph, int numberOfVertices)
{
    vector<bool> visited(numberOfVertices, false);
    for (auto edge : graph)
    {
        int source = edge.second.first;
        if (!visited[source])
        {
            dfsutil(graph, visited, source);
        }
    }
}

//************************ KrushKal ************************
int find(vector<int> &parent, int vertex)
{
    if (parent[vertex] == vertex)
    {
        return vertex;
    }
    return parent[vertex] = find(parent, parent[vertex]);
}
void unionSets(vector<int> &parent, vector<int> &rank, int source, int destination)
{
    int srcParent = find(parent, source);
    int destParent = find(parent, destination);
    if (srcParent == destParent)
        return;
    if (rank[srcParent] < rank[destParent])
    {
        parent[srcParent] = destParent;
    }
    else if (rank[srcParent] > rank[destParent])
    {
        parent[destParent] = srcParent;
    }
    else
    {
        parent[destParent] = srcParent;
        rank[srcParent]++;
    }
}
vector<pair<int, pair<int, int>>> mstKrushkal(vector<pair<int, pair<int, int>>> graph, int vertices)
{
    vector<int> parent(vertices);
    vector<int> rank(vertices);
    vector<pair<int, pair<int, int>>> result;
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    sort(graph.begin(), graph.end());
    for (auto edge : graph)
    {
        int src = edge.second.first;
        int dest = edge.second.second;
        if (find(parent, src) != find(parent, dest))
        {
            result.emplace_back(edge);
            unionSets(parent, rank, src, dest);
        }
    }
    return result;
}
//************************ KrushKal ************************




vi bellmanFord (vppii graph , int V){
    vi distance(V , INT_MAX); 
    vi parent(V, -1);
    distance[0] = 0; 
    for(int i =0; i<V-1; i++){
        for(auto edge : graph){
            int src = edge.first;
            int dest = edge.second.first;
            int wgt = edge.second.second;
            if(distance[src]!= INT_MAX &&  distance[dest] > distance[src]+wgt){
                distance[dest] = distance[src] + wgt; 
                parent[dest] = src; 
            }
        }
    }
    int src = 0; 
    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << src << " to " << i << " : " << distance[i] << endl;
    }
    return parent; 
}


vector<vi> floydWarshall(vector<vi> distance , int V){
    vector<vi> parent (V , vi(V , -1)); 

    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            if(i != j && distance[i][j] != INT_MAX) {
                parent[i][j] = i;
            }
        }
    }

    int i = 0 , j = 0 , k = 0; 

    for( i=0; i<V; i++){
        for(j = 0; j<V; j++){
            for(k = 0; k<V; k++){
                if(distance[i][j] > distance[i][k] + distance[k][j] && distance[i][k] != INT_MAX && distance[k][j]!= INT_MAX){
                    distance[i][j] = distance[i][k] + distance[k][j]; 
                    parent[i][j] = parent[k][i]; 
                }
            }
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (distance[i][j] ==INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << distance[i][j] << "   ";
        }
        cout << endl;
    }


    vector<vi> adj (V , vi(V, INT_MAX));
    for(int i =0; i<V; i++){
        for(int j = i+1; j<V; j++){
            if(parent[i][j] != -1 ){
                int src = parent[i][j]; 
                int weight = distance[src][j];
                adj[src][j] = adj[j][src] = weight;  
            }
        }
    }

    for(int i =0; i<V; i++){
        cout<<"Vertex "<<i<<"  ->  "; 
        for(int j = 0; j<V; j++){
            if(i!=j ){
                if(adj[i][j] == INT_MAX)
                cout<<"("<<j<<", INF )  "; 
                else 
                cout<<"("<<j<<","<<adj[i][j]<<")  "; 
            }
        }
        cout<<endl; 
    }

    return parent; 
}


void displayGraph(vector<pair<int, pair<int, int>>> graph)
{
    for (auto edge : graph)
        cout << "wgt : " << edge.first << "  " << edge.second.first << "-> " << edge.second.second << endl;
}

//******************* Main Function  *********************
int main()
{
    int numberOfVertices = 6;
    // vector<pair<int, pair<int, int>>> graph = {
    //     {0, {1, -1}},
    //     {0, {2, 4}},
    //     {1, {2, 3}},
    //     {1, {3, 2}},
    //     {1, {4, 2}},
    //     {3, {2, 5}},
    //     {3, {1, 1}},
    //     {4, {3, -3}}
    // };
    
  vector<vector<int>> graph = {
        { 0, 5, INT_MAX, 6, INT_MAX },
        { INT_MAX, 0, 1, INT_MAX ,7},
        { 3, INT_MAX, 0, 4, INT_MAX },
        { INT_MAX, INT_MAX, 2, 0, 3 },
        {2 , INT_MAX , INT_MAX, 5 , 0}
    };


    vector<vi> parent = floydWarshall(graph , 5 );
    
} 