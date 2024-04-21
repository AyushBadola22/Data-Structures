#include<iostream> 
#include<vector>
#include<queue>
#include<algorithm>
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

void addEdge (vector<vector<int>> & graph , int source , vector<int> destinations){
    for(auto destination : destinations){
        graph[destination].push_back(source); 
        graph[source].push_back(destination); 
    }
}

void displayAdjacency (vector<vector <int>> graph){
    for(int i =0; i<graph.size(); i++){
        cout<<i<<" -> "; 
        for (int j = 0; j<graph[i].size() ; j++){
            cout<<graph[i][j]<<" "; 
        }
        cout<<endl; 
    }
    cout<<endl; 
}

vector<int> shortestPathBFS(vector<vector<int>> &graph , int source ){
    queue<pair<int , int>> q; 
    vector<int> distance (graph.size(), INT_MAX); 
    distance[source] = 0; 
    q.emplace(pair<int , int>{source , distance[source]});

    while(!q.empty()){
        auto curVertex = q.front(); 
        q.pop(); 
        int weight = curVertex.second + 1 ; 
        for(auto edge : graph[curVertex.first]){
            if(distance[edge] > weight){
                q.emplace(pair<int , int> {edge , weight});
                distance[edge] = weight; 
            }
        }
    } 
    return distance; 
}

bool findPathDFS (vector<vector<int>> graph , int source , int destination , vector<bool>&visited){
    if(visited.empty()){
        visited.resize(graph.size());
        fill(visited.begin() , visited.end(), false);    
    }
    if(source == destination) return true; 
    if(visited[source]) return false; 

    visited[source] = true; 

    for(auto vertex : graph[source]){
        if(findPathDFS(graph, vertex , destination , visited)) return true; 
    }
    return false; 
}
bool findPath(vector<vector<int>> graph , int source , int destination ){
    vector<bool> visited (graph.size() , false); 
    return findPathDFS(graph , source , destination, visited); 
}


// **************************** Disjoint Structure ****************************


int main(){
    int numberOfVertices = 8; 
    vector<vector<int>> graph;
    graph.resize(numberOfVertices);
    addEdge (graph, 0 , {1, 2}); 
    addEdge (graph, 1, 3); 
    addEdge (graph, 2, 4); 
    addEdge (graph, 4, 6); 
    addEdge (graph, 6, 7); 
    addEdge (graph, 7, 5);

}