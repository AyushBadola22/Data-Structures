#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//* *******************   FUNCTION DECLARATION  START *******************
void addEdge(vector<vector<int>> &, int, int);
void addEdge(vector<vector<int>> &, int, vector<int>);


void BFS(vector<vector<int>> &, int);
void dfsutils(vector<vector<int>> &, vector<bool> &, int);
void DFS(vector<vector<int>> &);

void displayAdjacency(vector<vector<int>> );
vector<int> shortestDistanceSrc(vector<vector<int>> &, int );
bool findPathDFS(vector<vector<int>> , int , int , vector<bool> &);
bool findPath(vector<vector<int>> , int , int );
bool findPathDisjoint(vector<vector<int>> , int , int );
vector<int> shortestPath (vector<vector<int>> , int , int);

int findParent(vector<int> &, int );
void unionOfSets(vector<int> &, vector<int> &, int , int );
vector<int> createDisjointSet(vector<vector<int>> );


//* *******************   FUNCTION DECLARATION END *******************

/**
 *  1 . Create a class graph  that contains
 *          adjacency matrix
 *          number of vertexes
 *  2. Create Graph class functions BFS , DFS ,  addEdge
 *
 */

void BFS(vector<vector<int>> &graph, int source)
{
    cout<<"BFS : "; 
    int size = graph.size();
    queue<int> q;
    vector<bool> visited(size, false);
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        for (int i = 0; i < graph[vertex].size(); i++)
        {
            if (!visited[graph[vertex][i]])
            {
                q.push(graph[vertex][i]);
                visited[graph[vertex][i]] = true;
            }
        }
        cout << vertex << " ";
    }
    cout << endl;
}
void dfsutils(vector<vector<int>> &graph, vector<bool> &visited, int vertex)
{
    visited[vertex] = true;
    for (int i = 0; i < graph[vertex].size(); i++)
    {
        if (!visited[graph[vertex][i]])
        {
            dfsutils(graph, visited, graph[vertex][i]);
        }
    }
    cout << vertex << " ";
}
void DFS(vector<vector<int>> &graph)
{
    cout<<"DFS : "; 
    int size = graph.size();
    vector<bool> visited(size, false);
    for (int i = 0; i < size; i++)
    {
        if (!visited[i])
        {
            dfsutils(graph, visited, i);
        }
    }
    cout << endl;
}

void addEdge(vector<vector<int>> &graph, int source, int destination)
{
    graph[source].emplace_back(destination);
    graph[destination].emplace_back(source);
}
void addEdge(vector<vector<int>> &graph, int source, vector<int> destinations)
{
    for (auto destination : destinations)
    {
        graph[destination].push_back(source);
        graph[source].push_back(destination);
    }
}

void displayAdjacency(vector<vector<int>> graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void displayArray (vector<int> arr ){
    for(int ele : arr){
        cout<<ele<<" "; 
    }
    cout<<endl; 
}


vector<int> shortestDistanceSrc(vector<vector<int>> &graph, int source, string)
{
    queue<pair<int, int>> q;
    vector<int> distance(graph.size(), INT_MAX);
    distance[source] = 0;
  
    q.emplace(pair<int, int>{source, distance[source]});

    while (!q.empty())
    {
        auto curVertex = q.front();
        q.pop();
        int weight = curVertex.second + 1;
        for (auto edge : graph[curVertex.first])
        {
            if (distance[edge] > weight)
            {
                q.emplace(pair<int, int>{edge, weight});
                distance[edge] = weight;
            }
        }
    }
    return distance;
}
vector<int> shortestPath (vector<vector<int>> graph , int source, int destination){
    vector<bool> visited (graph.size(), false);
    vector<int> result; 
    vector<int> parent(graph.size());
    for(int i = 0; i<parent.size(); i++){
        parent[i] = i; 
    } 

    queue<int> q; 
    q.emplace(source); 
    visited[source] = true; 

    while(!q.empty()){
        int curVertex = q.front(); 
        q.pop(); 

        for(auto neighbour : graph[curVertex]){
            if(!visited[neighbour]){
                parent[neighbour] = curVertex; 
                visited[neighbour] = true ; 
                q.push(neighbour); 
            } 
        }
    }

    int currentNode = destination; 
    result.emplace_back(currentNode); 
    while (currentNode != source){
        if(parent[currentNode] == currentNode) return {}; 
        currentNode = parent[currentNode]; 
        result.emplace_back(currentNode); 
    }
    reverse(result.begin(), result.end()); 
    return result; 
}


bool findPathDFS(vector<vector<int>> graph, int source, int destination, vector<bool> &visited)
{
    if (visited.empty())
    {
        visited.resize(graph.size());
        fill(visited.begin(), visited.end(), false);
    }
    if (source == destination)
        return true;
    if (visited[source])
        return false;

    visited[source] = true;

    for (auto vertex : graph[source])
    {
        if (findPathDFS(graph, vertex, destination, visited))
            return true;
    }
    return false;
}
bool findPath(vector<vector<int>> graph, int source, int destination)
{
    vector<bool> visited(graph.size(), false);
    return findPathDFS(graph, source, destination, visited);
}
bool findPathDisjoint(vector<vector<int>> graph, int source, int destination)
{
    vector<int> parent = createDisjointSet(graph); 
    return (findParent(parent, source) == findParent(parent , destination));
}



// **************************** Disjoint Structure ****************************
int findParent(vector<int> &parent, int vertex)
{
    if (parent[vertex] == vertex)
    {
        return parent[vertex];
    }
    return parent[vertex] = findParent(parent, parent[vertex]);
}
void unionOfSets(vector<int> &parent, vector<int> &rank, int source, int destination)
{
    int srcParent = findParent(parent, source);
    int destParent = findParent(parent, destination);

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
vector<int> createDisjointSet(vector<vector<int>> graph)
{
    vector<int> rank(graph.size(), 0);
    vector<int> parent(graph.size());
    for (int i = 0; i < graph.size(); i++)
    {
        parent[i] = i;
    }

    // current parent is itself , rank for  all are zero

    for (int source = 0; source < graph.size(); source++)
    {
        for (auto destination : graph[source])
        {
            unionOfSets(parent, rank, source, destination);
        }
    }
    return parent;
}
// **************************** Disjoint Structure ****************************

int main()
{
    int numberOfVertices = 8;
    vector<vector<int>> graph;
    graph.resize(numberOfVertices);
    addEdge(graph, 0, {1, 2});
    addEdge(graph, 1, 3);
    addEdge(graph, 4, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 5);

}