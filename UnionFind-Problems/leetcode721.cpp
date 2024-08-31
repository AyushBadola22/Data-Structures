/*
721  :   Account Merge 

Solved using the DSU 
All persons are treated as indexes. 
For each email they represent to a index. 
If the email already exists and its not the same index then we will union the two sets.
In last what we will create a structure and emails pointing to same index are merged .

For any query regarding the code can ask in the discussion. If you are shy just refer to the striver's video of Account merge , you will get the idea of approach.
The implementation can greatly differ so please don't just mug up the solution , take a notebook and learn how it flows. `
*/

class Solution {
public:
    vector<int> parent ; 

    int find(int u ){
        while(parent[u] > 0 )
            u = parent[u];
        return u ; 
    }

    void union_sets(int u , int v ){
        int pu = find(u); 
        int pv = find(v);

        if(pu == pv) return ; 
        parent[pv] = pu;  
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string , int > map;
        int n =  accounts.size();  
        parent.resize(n, -1); 
        for(int i = 0; i<n; i++ ){
            for(int j = 1; j < accounts[i].size();j++){
                string mail = accounts[i][j]; 
                if(map.find(mail) != map.end()){
                    union_sets(i , map[mail]); 
                }
                map[mail] = find(i) ;
            }
        }
        vector<vector<string>> result(n, vector<string>());

        for(auto data : map){
            int parent = find(data.second); 

            result[parent].push_back(data.first); 
        }
        vector<vector<string>>ans; 
        for (int  i = 0 ; i<n ; i++){

            if(result[i].size() != 0 ){
                result[i].insert(result[i].begin() , accounts[i][0]); 
                cout<<result[i].size();
                ans.push_back(result[i]); 
            }
        }
        return ans;
    }
};