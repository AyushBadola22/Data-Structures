"""
Number of operations to make Network Connected 

Using DSU I will find the number of connected components , number of cycles 
By finding number of connected components I can find total number of components that are already connected
As well as I can find the remaining computers that are needed to be connected. 
Purpose of finding cycle is because we need to connect all nodes so we can't remove the normal edges , we need to remove cycles as they are reductant. 


After all the tasks , i know there are N-1 edges to make everyone connected. 
If the remaining computers are greater than cycles that means we will never be able to connect all devices. 
Else we will return the minimum of the required edges and remaining . 
"""

class Solution(object):
    def find(self , u ) : 
        if self.parent[u] < 0 :
            return u 
        self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u ,v) : 
        pu = self.find(u)
        pv = self.find(v)

        if pu == pv :
            return 
        if self.parent[pu] < self.parent[pv] : 
            self.parent[pu] += self.parent[pv]
            self.parent[pv] = pu
        else :
            self.parent[pv] += self.parent[pu]
            self.parent[pu] = pv
        
    # main function 
    def makeConnected(self, n, connections):
        self.parent = [-1 for _ in range(n)]

        cycles = 0 
        connected = 0 
        for comp1 , comp2 in connections : 
            if(self.find(comp1) == self.find(comp2)) :
                cycles +=1 
            else : 
                self.union(comp1 , comp2)
                connected += 1
        print(self.parent, cycles, connected)

        remaining = n - connected -1 

        if cycles - remaining  < 0 :
            return -1  
        return min(remaining , cycles)
        
         