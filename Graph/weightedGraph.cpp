//******************  Libraries  *****************************
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std; 




//******************* Graph by Vector of tuples  *********************
void dfsutil(vector<tuple<int , int , int>>graph, vector<bool>&visited , int vertex){
    visited[vertex]  = true; 
    for(auto edge : graph){
        int source = get<1>(edge);
        int destination = get<2>(edge);
        if(!visited[destination] && source == vertex){
            dfsutil(graph , visited, destination); 
        }
    }

    cout<<vertex<<" "; 
}

void dfs(vector<tuple<int , int , int>>graph, int numberOfVertices){
    vector<bool>visited (numberOfVertices, false); 
    for(auto edge : graph){
        int source = get<1>(edge);
        if(!visited[source]){
            dfsutil(graph , visited , source); 
        }
    }
}

void addEdge(vector<tuple<int , int , int>>&graph, int source , int destination , int weight){
    graph.emplace_back(weight, source , destination); 
    graph.emplace_back(weight, destination , source); 
}


//******************* Graph by Vector of pair of pair  ********************* 
void addEdge(vector<pair<int , pair<int, int>>> &graph , int source , int destination , int weight){
    graph.push_back({weight, {source, destination}});
    graph.push_back({weight, {destination , source}});
}

void dfsutil(vector<pair<int, pair<int, int>>> graph , vector<bool> &visited , int vertex){
    visited[vertex] = true; 
    for(auto edge : graph){
        int source = edge.second.first;
        int destination = edge.second.second;  
        if(!visited[destination] && source == vertex){
            dfsutil(graph, visited, destination);
        }
    }
    cout<<vertex<<" ";
}

void dfs(vector<pair<int , pair<int , int>>> graph, int numberOfVertices){
    vector<bool> visited(numberOfVertices , false); 
    for(auto edge : graph){
        int source = edge.second.first;
        if(!visited[source]){
            dfsutil(graph , visited , source);
        }
    }
}

                /* 
                * ##############################################
                * ######||       Kruskal Algorithm      ######||
                * ##############################################
                */

int find (int vertex  , vector<int> parent){
    if(parent[vertex] == vertex){
        return vertex; 
    }
    return find(parent[vertex], parent); 
}

void unionOfDisjoint(int source , int destination , vector<int>&parent, int){
    int srcParent = find(source , parent); 
    int destParent = find(source , parent); 

    if(srcParent != destParent){
        parent[destParent] = srcParent; 
    }
}

vector<pair<int, pair<int, int>>> kruskalAlgo(vector<pair<int, pair<int, int>>> graph, int  numberOfVertices){
    vector<int>parent(numberOfVertices); 
    for(int i =0; i<numberOfVertices; i++){
        parent[i]=i; 
    }

    sort(graph.begin(), graph.end()); 
    int edges = graph.size();
    vector<pair<int, pair<int, int>>> mst; 
    
}

//******************* Main Function  *********************
int main(){
    vector<tuple<int , int , int>>graph; 
    vector<pair<int , pair<int , int>>> graph2; 
    int numberOfVertices = 6;
    graph2.resize(numberOfVertices);
    graph.resize(numberOfVertices); 
    addEdge(graph , 0 , 3, 2);  
    addEdge(graph , 0 , 4, 1);  
    addEdge(graph , 3, 4, 7);  
    addEdge(graph , 4, 2 , 4);  
    addEdge(graph , 2, 5, 6);  
    addEdge(graph , 1, 5, 2);  
    dfs(graph, numberOfVertices); 
    cout<<endl; 
    addEdge(graph2 , 3, 4, 7);  
    // addEdge(graph2 , 2, 5, 6);  
    addEdge(graph2 , 0 , 3, 2);  
    addEdge(graph2 , 0 , 4, 1);  
    addEdge(graph2 , 4, 2 , 4);  
    addEdge(graph2 , 1, 5, 2);  
    dfs(graph2, numberOfVertices); 
}