"""
We are given a 2-D plane with n stones placed at integer coordinates,
where a stone can be removed only if another stone shares either its row or column. 
Our task is to determine the maximum number of stones that can be removed from the plane under these conditions.


Since every stone in a connected component shares a row or column with at least one other stone,
we can remove all but one stone.
The remaining stone cannot be removed as it no longer shares coordinates with any other stone,
having eliminated all others in its component.


So I will use DSU to connect the points which shares the same row or column . 
I will maintain a count to tell number of disconnected components. 

Using disconnected components I can find the connected component count which is our final answer. 

WHY ???

Because all the points which shares same row and column are to be removed , that means we need to remove connected components . 

EDITORIAL : 
So, len(stones) - self.count tells you the number of stones you can remove because every connected component must retain at least one stone, and the rest can be removed. This is why subtracting the count of components from the total number of stones gives the correct answer.

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

        self.count -=1 
        if self.parent[pu] < self.parent[pv] : 
            self.parent[pu] += self.parent[pv]
            self.parent[pv] = pu
        else :
            self.parent[pv] += self.parent[pu]
            self.parent[pu] = pv
        
    def removeStones(self, stones):
        self.parent = [-1 for _ in range(len(stones))]
        self.count = len(stones)
        for i in range (len(stones)) : 
            for j in range (i+1 , len(stones)) :
                if stones[i][1] == stones[j][1] or stones[i][0] == stones[j][0] :
                    self.union(i , j )
        return len(stones) - self.count