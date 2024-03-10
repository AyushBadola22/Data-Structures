#include<vector> 
#include<iostream>
#include<queue> 
#include<sstream> 
using namespace std; 

void display(vector<vector<int>> graph, int numberOfVertices){
       std::cout << "Resulting Graph:" << std::endl;
        for (int i = 0; i < numberOfVertices; i++) {
        std::cout << "Vertex " << i << ": ";
        for (int j = 0; j < graph[i].size(); j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addEdge(vector<vector<int>> &graph, int source , int destination ){
    graph[source].emplace_back(destination);
    graph[destination].emplace_back(source);
}

void BFS(vector<vector<int>> graph , int numberOfVertices , int source){
    queue<int> q; 
    vector<bool> visited (numberOfVertices , false); 

    q.push(source);
    visited[source] = true; 

    while(!q.empty()){
        int vertex = q.front();
        q.pop(); 
        std::cout<<vertex<<" "; 

        for(int i = 0; i<graph[vertex].size(); i++){
            if(!visited[graph[vertex][i]]){
                visited[graph[vertex][i]] = true; 
                q.emplace(graph[vertex][i]);
            }
        } 
    }
}

void dfsUtils (vector<vector<int>> graph , vector<bool> &visited, int vertex ){
        visited[vertex] = true; 
        for(int i =0; i<graph[vertex].size(); i++){
            if(!visited[graph[vertex][i]]){
                dfsUtils(graph , visited , graph[vertex][i]); 
            }
        }
        cout<<vertex<<" "; 
}

void dfs(vector<vector<int>> graph , int numberOfVertices){
    vector<bool> visited(numberOfVertices  , false); 
    for(int i =0; i<numberOfVertices; i++){
        if(!visited[i]){
            dfsUtils(graph , visited , i );
        }
    }
}

int main(){
    vector<vector<int>> graph ; 
    int numberofVertexes = 0; 
    cout<<"NUmber of vertexes : "; 
    cin>>numberofVertexes; 
    graph.resize(numberofVertexes); 
    for(int i = 0; i < numberofVertexes; i++){
        string connections; 
        cin.ignore(); 
        cout<<"Source vertex : "<<i<<endl; 
        cout<<"Enter the destination vertices : "; 
        getline(cin , connections); 
        stringstream inputStream (connections);
        string destination;  
        while(inputStream >> destination){
            if(destination != "no")
            addEdge(graph , i , stoi(destination));
        }
    }

    display(graph,numberofVertexes); 
    dfs(graph , numberofVertexes);
}
