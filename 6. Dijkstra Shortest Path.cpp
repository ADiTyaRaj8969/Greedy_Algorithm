#include <bits/stdc++.h>
// Dijkstra's Shortest Path Algorithm
// Greedy strategy: Always expand the node with the smallest tentative distance (using a min-heap).
// Task: Given a weighted, directed graph with non-negative edge weights and a source vertex,
// find the shortest path from the source to all other vertices in the graph.

#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<long long> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int s)
{
    const long long INF = 4e18;
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int n = 5, s = 0;
    vector<vector<pair<int, int>>> adj(n);
    auto add = [&](int u, int v, int w) { adj[u].push_back({v, w}); };
    add(0, 1, 10);
    add(0, 4, 5);
    add(1, 2, 1);
    add(4, 1, 3);
    add(4, 2, 9);
    add(4, 3, 2);
    add(3, 2, 4);
    add(2, 3, 6);
    add(3, 0, 7);
    auto dist = dijkstra(n, adj, s);
    for (int i = 0; i < n; ++i) cout << dist[i] << (i + 1 == n ? '\n' : ' ');
    return 0;
}

/*
Time Complexity: O((V + E) log V) — binary heap implementation.
Space Complexity: O(V + E) — adjacency list and distance array.
*/
