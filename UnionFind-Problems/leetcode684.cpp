class Solution {
public:
    vector<int> parent ; 

    int find(int u ){
        while(parent[u] > 0) 
            u = parent[u]; 
        return u ;
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
                parent[pu] += parent[pv]; 
                parent[pv] = pu; 
            }
        } 
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int maxV = 0; 
        for(auto edge : edges){
            maxV = max({maxV , edge[0], edge[1]}); 
        }

        this->parent.resize(maxV + 1 , -1); 

        for (auto edge : edges){
            int u = edge[0]; 
            int v = edge[1]; 
            if(find(u) == find(v)){
                return {u , v}; 
            }
            else unite(u , v); 
        }
        return {}; 
    }
}; 