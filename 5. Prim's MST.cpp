#include <bits/stdc++.h>
// Prim's Algorithm for Minimum Spanning Tree (MST)
// Greedy strategy: Always expand the MST by picking the smallest edge crossing the cut (using a
// min-heap). Task: Given a connected, undirected graph with weighted edges, find an MST using
// Prim's algorithm. Return the sum of the weights of the edges in the MST.

#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

long long primMST(int n, vector<vector<pair<int, int>>>& adj)
{
    vector<int> visited(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        pq;  // {weight, node}
    pq.push({0, 0});

    long long total = 0;
    int taken = 0;
    while (!pq.empty() && taken < n)
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = 1;
        total += w;
        ++taken;
        for (auto [v, wt] : adj[u])
        {
            if (!visited[v])
                pq.push({wt, v});
        }
    }
    return (taken == n) ? total : static_cast<long long>(1e18);
}

int main()
{
    int n = 4;
    vector<vector<pair<int, int>>> adj(n);
    auto add = [&](int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    add(0, 1, 10);
    add(0, 2, 6);
    add(0, 3, 5);
    add(1, 3, 15);
    add(2, 3, 4);
    cout << primMST(n, adj) << '\n';
    return 0;
}

/*
Time Complexity: O(E log V) — using a binary heap (priority queue).
Space Complexity: O(V + E) — adjacency list and heap.
*/
