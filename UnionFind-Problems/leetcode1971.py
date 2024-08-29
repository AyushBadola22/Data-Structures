"""
    FIND IF PATH EXISTS IN GRAPH
    Approach : 
    First we assume each node is seperate and there is no path bw them. 
    Then we traverse the edges and join the two edges . 
    We continue to add the edges and create components. 
    If in last we try to find the parent of source and parent of destination , if they are from same component they will share same parent thus find(src) == find(dest)
    But if its not equal then they lie in different components and there is no edge that can join them.

"""
class Solution(object):
    def find (self , v) : 
        while(self.parent[v] > 0) : 
            v = self.parent[v]
        return v

    def union (self , u , v) : 
        pu = self.find(u)
        pv = self.find(v)

        if pu != pv : 
            if self.parent[pu] < self.parent[pv] : 
                self.parent[pu] += self.parent[pv]
                self.parent[pv] = pu 
            else : 
                self.parent[pv] += self.parent[pu]
                self.parent[pu] = pv
        
    def validPath(self, n, edges, source, destination):
        self.parent = [-1] * n 

        for src , dest in edges :  
                self.union(src , dest)
        return self.find(source) == self.find(destination)