"""
    Question is that given points in a graph , connect such that cost is less
    cost is defined by | xi - xj | + | yi - yj |    
"""

import heapq
class Solution(object):
    def find(self , u ): 
        if self.parent[u] < 0 : 
            return u 
        self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union (self , u ,  v) : 
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
        
        
    def minCostConnectPoints(self, points):
        total = len(points)
        self.parent = [-1 for _ in range (total)]
        mstwgt = 0 
        edges = [] 

        for i in range(total-1) : 
            for j in range(i+1 , total) : 
                wgt = abs(points[i][0] - points[j][0] ) + abs(points[i][1] - points[j][1])
                heapq.heappush(edges , [wgt , i , j ])

        while edges : 
            wgt , src , dest = heapq.heappop(edges)
            if self.find(src) != self.find(dest) : 
                mstwgt += wgt
                self.union(src, dest)

        return mstwgt 
                