class Solution(object):

    def find(self , u ): 
        while(self.parent[u] > 0 ) : 
            u = self.parent[u] 
        return u 
    

    def union (self, u , v ) : 
        pu = self.find(u)
        pv = self.find(v)

        if pu != pv : 
            if self.parent[pu] > self.parent[pv] : 
                self.parent[pu] += self.parent[pv]
                self.parent[pv] = pu
            else : 
                self.parent[pv] += self.parent[pu]
                self.parent[pu] = pv

    def findRedundantConnection(self, edges):
        maxV = 0 

        for i , j in edges : 
            maxV = max(i , j  , maxV)
        
        self.parent = [-1] * (maxV+1)
        
        for u , v in edges : 
            if self.find(u) == self.find(v) : 
                return [u,v]
            else : 
                self.union(u , v)
        return [] 
    
        