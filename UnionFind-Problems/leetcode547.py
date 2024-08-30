"""
    547 - Number of Provinces
    Approach : Using union find method , join two disconnected components if there is edge bw them.
    In the end only disconnected components will be left which will be their own parent. 
    Thus after UNION FIND if we count number of negative values parent array , it will tell number of disconnected components.   
        
"""

class Solution(object):
    
    def find(self , u) : 
        while(self.parent[u] > 0 ) : 
            u = self.parent[u]
        return u 

    def union(self , u , v ): 
        pu = self.find(u)
        pv = self.find(v)

        if pu != pv : 
            if self.parent[pu] < self.parent[pv] : 
                self.parent[pu] += self.parent[pv]
                self.parent[pv] = pu
            else : 
                self.parent[pv] += self.parent[pu]
                self.parent[pu] = pv


    def makeEdges(self, isConnected):
        self.edges = []
        for i in range(len(isConnected)) : 
            for j in range (len(isConnected[0])):
                if isConnected[i][j] : 
                    self.edges.append([i,j])


    
    def findCircleNum(self, isConnected):
        self.makeEdges(isConnected)
        self.parent = [-1] * len(isConnected)

        for u , v  in self.edges : 
            self.union(u , v )
        
        count = 0 
        for i in self.parent : 
            if i < 0 : 
                count +=1 
        return count 


        
        