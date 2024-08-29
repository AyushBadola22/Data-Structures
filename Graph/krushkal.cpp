#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int find(int v, vi &parent){//pass the parent vector by reference for optimise code
    while(1){
        if(parent[v] < 0) return v; 
        v = parent[v]; 
    }
    // if the parent of vertex is negative that means the ultimate parent is itself.
    // else then find its ultimate parent
}

void unionOfSets(int u, int v, vi &parent){

    // first find the parent for both of them
    // the returned value from the find is the index for that parent so we need to check the value of there

    int parent1 = find(u, parent);
    int parent2 = find(v, parent);

    if(parent1 == parent2) return ;
    

    if (parent[parent1] > parent[parent2])
    {
        parent[parent1] += parent[parent2];//we will update the parent of that vertex which have greater abs value
        parent[parent2] = parent1;//we will update parent of smaller abs value with new parent value
    }
    else if (parent[parent2] >= parent[parent1])
    {
        parent[parent2] += parent[parent1];
        parent[parent1] = parent2;
    }
}

vvi krushkal(vvi edges, int V)
{
    vi parent(V, -1); // first initialize all of them as -1 indicates that they are there own parent.

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vvi mst;

    for (auto edge : edges)
    {
        int wgt = edge[2];
        int src = edge[0];
        int dest = edge[1];

        pq.push({wgt, {src, dest}});
    }

    while (!pq.empty())
    {
        auto edge = pq.top();
        int parent1 = find(edge.second.first, parent);
        int parent2 = find(edge.second.second, parent);
        if (  parent1 != parent2)
        {
            cout<<"cur edge : "<<edge.second.first<<" , "<<edge.second.second<<endl; 
            unionOfSets(edge.second.first, edge.second.second, parent);
            mst.push_back({edge.second.first, edge.second.second, edge.first});
        }
        pq.pop(); 
    }
    return mst;
}


//-------------------------------------- Driver Code --------------------------------------------//


int main()
{

    vvi edges = {
        {0, 1, 3},
        {0, 2, 4},
        {0, 3, 2},
        {1, 0, 3},
        {1, 3, 7},
        {2, 0, 4},
        {3, 0, 2}};

    vvi mst = krushkal(edges , 4);
    for(auto edge : mst){
        cout<<edge[0]<< " to "<<edge[1]<< " with wgt "<<edge[2]<<endl; 
    } 

}