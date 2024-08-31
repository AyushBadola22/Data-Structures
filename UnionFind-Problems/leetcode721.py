"""
721  :   Account Merge 

Solved using the DSU 
All persons are treated as indexes. 
For each email they represent to a index. 
If the email already exists and its not the same index then we will union the two sets.
In last what we will create a structure and emails pointing to same index are merged .

For any query regarding the code can ask in the discussion. 
"""


class Disjoint : 
    def __init__ (self , n ) : 
        self.parent = [-1] * n

    def union(self , u , v) : 
        pu = self.find(u)
        pv = self.find(v)
        if pu == pv :
            return
        print(pu , pv)
        self.parent[pv] = pu

    def find(self , u) : 
        while self.parent[u] > 0:
            u = self.parent[u]
        return u

class Solution(object):
    def accountsMerge(self, accounts):
        dsu = Disjoint(len(accounts))

        map = {}

        for i in range(len(accounts)) : 
            for email in accounts[i][1:]:
                if email in map :
                    dsu.union(i , map[email])
                map[email] = dsu.find(i)
        
        map = sorted(map.items() , key = lambda  x : (x[0] , x[1]))
        result = [[] for _ in range (len(accounts))] 

        for mail , index in map : 
            parent = dsu.find(index)
            result[parent].append(mail)
        
        ans = [] 
        for i in range(len(accounts)):
            if result[i] :
                owner = accounts[i][0]
                result[i].insert(0 , owner)
                ans.append(result[i])             
        return ans

