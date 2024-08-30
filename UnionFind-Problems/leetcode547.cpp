class Solution {
public:
    vector<pair<int, int>> edges; 
    vector<int> parent; 

    void makeEdges (vector<vector<int>>isConnected){
        for(int i = 0 ; i<isConnected.size(); i++){
            for(int j = 0 ; j<isConnected[0].size(); j++){
                if(isConnected[i][j]){
                    this->edges.push_back({i, j}); 
                }
            }
        }
    }

    int find(int u ){
        while(parent[u] > 0)
            u = parent[u]; 
        return u; 
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
                parent[pu] = pv; 
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        makeEdges(isConnected); 
        this->parent.resize(isConnected.size() , -1); 
        for (auto edge : edges){
            unite(edge.first , edge.second); 
        }
        int count = 0 ; 
        for (auto i : parent){
            if( i < 0 ) count++; 
        }
        return count ; 
    }
};