"""
    Number of Enclaves 

    Given a 2d grid with either zero or one . 1 means land , 0 means water. 
    I can walk on land to reach the boundaries. 
    I need to calculate the number of grids through which directly or indirectly I cant reach the boundary node. 

    We will use DSU to connect the grids that can reach the boundaries directly or indirectly. 
"""


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
        
    def numEnclaves(self, grid):
        rows = len(grid)
        cols = len(grid[0])
        self.parent = [-1] * rows * cols
        self.parent.append(-rows * cols)   # dummy node 

        ones = 0 

        for i in range(rows) : 
            for j in range(cols ) : 
                if grid[i][j] : 
                    if i == 0 or i == rows-1 or j == cols-1 or j == 0 :
                        self.union(i*cols + j , rows * cols)
                    else : 
                        if grid[i+1][j] : 
                            self.union(i * cols + j , (i+1) * cols + j )
                        if grid[i][j+1] :
                            self.union(i * cols + j , i * cols + j + 1 )
                        if grid[i][j-1] :
                            self.union(i * cols + j , i * cols + j - 1 )
                        if grid[i-1][j] :
                            self.union(i * cols + j , (i-1) * cols + j )

        count =  0 

        for i in range(rows):
            for j in range(cols) : 
                if grid[i][j] and self.find(i * cols + j ) != self.find(rows * cols) :
                    count += 1
        return count  
       
        