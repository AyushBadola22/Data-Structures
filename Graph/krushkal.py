import heapq 
class DisjointSet : 

    # constructor 
    def __init__(self, n ) :
        # initialized a parent array , -1 denotes there is only one node inside the current tree 
        self.parent = [-1 for _ in range(n)]
    

    # find the ultimate parent of a node 
    def find (self , v ) : 
        while True : 
            # if the parent of node shows negative value that denotes that its the ultimate parent . 
            # The value stored denotes the number of nodes inside its tree. 
            if self.parent[v] < 0 : 
                return v
            else : 
                v = self.parent[v]

    # union method to join two edges if the two nodes doesn't form a cycle
    def union (self , u , v ) : 
        parent_u = self.find(u)
        parent_v = self.find(v)

        if parent_u == parent_v : 
            return 
            
        if self.parent[parent_u] <= self.parent[parent_v] : 
            self.parent[parent_u] += self.parent[parent_v]
            self.parent[parent_v] = parent_u 
        else : 
            self.parent[parent_v] += self.parent[parent_u]
            self.parent[parent_u] = parent_v
    

    def __str__ (self ) : 
        return str(self.parent)
    


class Graph : 
    def __init__(self , V ) :
        self.V = V 
        self.edges = []

    def add_edge (self , src , dest , wgt) : 
        self.edges.append([src , dest, wgt])

    # return a new graph that is a minimum spanning tree 
    def krushkal_mst (self) :
        # create a new disjoint structure to detect that there is no cycle formation  
        disjoint = DisjointSet(self.V)

        # build min heap to choose minimum weight edges each time 
        min_heap = [] 
        for src , dest , wgt in self.edges : 
            heapq.heappush(min_heap ,(wgt , src , dest))


        # build a new graph to store the result 
        mst = Graph(self.V)

        # run a loop till the minHeap is not empty and add the edge in the result if it doesnt form cycle 
        while min_heap : 
            # minimum weight edge taken from the heap 
            wgt , src , dest = heapq.heappop(min_heap)

            # since we need to build the mst by adding the edges which doesn't form edges so we will check for cycles
            # since we are already checking it here before joining them thus we need not to check inside union function again 
            parent_src = disjoint.find(src)
            parent_dest = disjoint.find(dest)

            if parent_src != parent_dest : 
                mst.add_edge(src , dest, wgt)
                disjoint.union(src, dest)
        
        return mst   

    def __str__(self) : 
        result = ''
        if not self.edges:
            return result 
        for src, dest , wgt in self.edges : 
            result += f'\nFrom {src} to {dest} with weight {wgt}'
        return result 
    

### ############### Driver Code  ####################### ###

graph = Graph(4)
graph.add_edge(0 , 1 , 4)
graph.add_edge(0 , 2 , 3)
graph.add_edge(0 , 3 , 2)
graph.add_edge(1 , 2 , 5)
graph.add_edge(1 , 3 , 1)
graph.add_edge(2, 3 , 6)


print(graph.krushkal_mst())

"""
Expected output : 
From 1 to 3 with weight 1
From 0 to 3 with weight 2
From 0 to 2 with weight 3
"""


graph = Graph(6)
graph.add_edge(0, 1, 7)
graph.add_edge(0, 2, 9)
graph.add_edge(0, 3, 14)
graph.add_edge(1, 2, 10)
graph.add_edge(1, 4, 15)
graph.add_edge(2, 3, 2)
graph.add_edge(2, 4, 11)
graph.add_edge(3, 4, 6)
graph.add_edge(3, 5, 9)
graph.add_edge(4, 5, 7)

print ("\n\nTestcase two answer : ", graph.krushkal_mst())
"""
Testcase two answer :  
From 2 to 3 with weight 2
From 3 to 4 with weight 6
From 0 to 1 with weight 7
From 4 to 5 with weight 7
From 0 to 2 with weight 9 
"""