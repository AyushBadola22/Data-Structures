#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int find(int v, vi parent)
{
    while (1)
    {
        if (parent[v] < 0)
            return v;
        v = parent[v];
    }
    // if the parent of vertex is negative that means the ultimate parent is itself.
    // else then find its ultimate parent
}

void unionOfSets(int u, int v, vi &parent)
{

    // first find the parent for both of them
    // the returned value from the find is the index for that parent so we need to check the value of there

    int p1 = find(u,parent);
        int p2 = find(v,parent);
        if (p1 == p2) return;
        if (abs(parent[p1]) > abs(parent[p2])) {
            parent[p1] += parent[p2];
            parent[p2] = p1;
        } else {
            parent[p2] += parent[p1];
            parent[p1] = p2;
        }
}

vvi krushkal(vvi edges, int V)
{
    vi parent(V, -1); // first initialize all of them as -1 indicates that they are there own parent.

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vvi mst;

    for (auto edge : edges)
    {
        int wgt = edge[2];
        int src = edge[0];
        int dest = edge[1];

        pq.push({wgt, {src, dest}});
    }

    while (!pq.empty())
    {
        auto edge = pq.top();
        int parent1 = find(edge.second.first, parent);
        int parent2 = find(edge.second.second, parent);
        if (parent1 != parent2)
        {
            unionOfSets(edge.second.first, edge.second.second, parent);
            mst.push_back({edge.second.first, edge.second.second, edge.first});
        }
        pq.pop();
    }
    return mst;
}

//-------------------------------------- Driver Code --------------------------------------------//

int main()
{

    // vvi edges = {
    //     {0, 1, 3},
    //     {0, 2, 4},
    //     {0, 3, 2},
    //     {1, 0, 3},
    //     {1, 3, 7},
    //     {2, 0, 4},
    //     {3, 0, 2}};
    vvi edges = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 2, 11},
        {1, 3, 6},
        {2, 4, 7},
        {3, 4, 9},
        {3, 5, 10},
        {4, 5, 12},
        {4, 6, 2},
        {5, 6, 5}};

    vvi mst = krushkal(edges, 7);
    int mstWt=0;
    for (auto edge : mst)
    {
        cout << edge[0] << " to " << edge[1] << " with wgt " << edge[2] << endl;
        mstWt+=edge[2];
    }
    cout<<"Toatal Weight to MST is "<<mstWt<<endl;
}