import heapq 

# Find method 
def find (u , parent) : 
    while True : 
        if parent[u] < 0 : 
            return u  
        u = parent[u]

# union method 
def union(u , v , parent) : 
    p1 = find(u , parent)
    p2 = find(v , parent)

    if p1 == p2 : 
        return 
    
    if parent[p1] < parent[p2] : 
        parent[p1] = parent[p1] + parent[p2]
        parent[p2] = p1 
    else : 
        parent[p2] = parent[p2] + parent[p1]
        parent[p1] = p2 



# krushkal 

def krushkal (edges , V ): 
    parent = [-1] * V 
    mst = [] 
    heapq.heapify(edges)

    for edge in edges : 
        wgt , u , v = edge 
        if find(u , parent) != find(v , parent) : 
            mst.append([u , v , wgt])
            union(u , v , parent)
    
    return mst 
        

#######################  Driver code ###############


edges = [
    [0, 1, 3],
    [0, 2, 4],
    [0, 3, 2],
    [1, 0, 3],
    [1, 3, 7],
    [2, 0, 4],
    [3, 0, 2]
]

# edges were in order source, destination and weight 
# for priority queue to sort based on weight we needed to re-order the edges , by puting the weight first for straightforward sorting.
def convert (edges):
    converted = [] 

    for edge in edges : 
        u , v , w = edge
        converted.append([w , u , v])

    return converted 



mst = krushkal(convert(edges), 4)

for edge in mst : 
    u , v, w = edge 
    print(f'from {u} to {v} with {w}')