#include <vector>
/*
    FIND IF PATH EXISTS IN GRAPH
    Approach : 
    First we assume each node is seperate and there is no path bw them. 
    Then we traverse the edges and join the two edges . 
    We continue to add the edges and create components. 
    If in last we try to find the parent of source and parent of destination , if they are from same component they will share same parent thus find(src) == find(dest)
    But if its not equal then they lie in different components and there is no edge that can join them.
*/

class Solution {
public:
    vector<int> parent ; 

    int find (int u ){
        while (parent[u] > 0 ){
            u = parent[u]; 
        }
        return  u; 
    }

    void unite(int u , int v){
        int pu = find(u); 
        int pv = find(v); 

        if(pu != pv){
            if(parent[pu] < parent[pv]){
                parent[pu] += parent[pv]; 
                parent[pv] = pu; 
            }
            else {
                parent[pv] += parent[pu]; 
                parent[pu]= pv; 
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        this->parent.resize(n , -1); 

        for(auto edge : edges){
            unite(edge[0] , edge[1]); 
        }
        return find(source) == find(destination); 
    }
};


