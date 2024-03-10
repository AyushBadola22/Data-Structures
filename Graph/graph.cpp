#include<iostream> 
#include<vector>
#include<queue>
using namespace std; 

/**
 *  1 . Create a class graph  that contains 
 *          adjacency matrix
 *          number of vertexes 
 *  2. Create Graph class functions BFS , DFS ,  addEdge 
 *      
*/

void BFS(vector<vector<int>> & graph, int source){
    int size = graph.size(); 
    queue<int> q; 
    vector<bool> visited(size , false); 
    q.push(source);
    visited[source] = true; 
    while(!q.empty()){
        int vertex = q.front(); 
        q.pop(); 
        for(int i =0; i<graph[vertex].size(); i++){
            if(!visited[graph[vertex][i]]){
                q.push(graph[vertex][i]);
                visited[graph[vertex][i]] = true; 
            }
        }
        cout<<vertex<<" ";  
    }
}
void dfsutils(vector<vector<int>> & graph, vector<bool> &visited, int vertex){
    visited[vertex] = true; 
    for(int i =0 ; i<graph[vertex].size(); i++){
        if(!visited[graph[vertex][i]]){
            dfsutils(graph, visited , graph[vertex][i]); 
        }
    }
    cout<<vertex<<" "; 
}
void DFS (vector<vector<int>> & graph){
    int size = graph.size(); 
    vector<bool>visited(size , false); 
    for(int i =0; i<size; i++){
        if(!visited[i]){
            dfsutils(graph , visited, i); 
        }
    }
}

void addEdge (vector<vector<int>> & graph , int source , int destination){
    graph[source].emplace_back(destination);
    graph[destination].emplace_back(source); 
}

int main(){
    int numberOfVertices = 5; 
    vector<vector<int>> graph;
    graph.resize(numberOfVertices);
    addEdge(graph, 0, 1 );
    addEdge(graph, 1, 2 );
    addEdge(graph, 3, 4 );
    DFS(graph ); 
}