#include <bits/stdc++.h>
// Kruskal's Algorithm for Minimum Spanning Tree (MST)
// Greedy strategy: Always pick the smallest weight edge that does not form a cycle (using DSU).
// Task: Given a connected, undirected graph with weighted edges, find an MST using Kruskal's
// algorithm. Return the sum of the weights of the edges in the MST.

#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

struct Edge
{
    int u;
    int v;
    int w;
};

struct DSU
{
    vector<int> parent;
    vector<int> rankv;

    explicit DSU(int n) : parent(n), rankv(n, 0) { iota(parent.begin(), parent.end(), 0); }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rankv[a] < rankv[b])
            swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b])
            ++rankv[a];
        return true;
    }
};

long long kruskalMST(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.w < b.w; });
    DSU dsu(n);
    long long total = 0;
    int taken = 0;
    for (const auto& e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            total += e.w;
            if (++taken == n - 1)
                break;
        }
    }
    return total;
}

int main()
{
    int n = 4;
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    cout << kruskalMST(n, edges) << '\n';
    return 0;
}

/*
Time Complexity: O(E log E + E α(V)) ≈ O(E log E) — sorting edges dominates (α is inverse
Ackermann). Space Complexity: O(V) — DSU parent/rank arrays.
*/
