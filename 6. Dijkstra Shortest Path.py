"""
Dijkstra's Shortest Path Algorithm
Task: Given a weighted, directed graph with non-negative edge weights and a source vertex, find the
shortest path from the source to all other vertices in the graph.
Greedy strategy: Always expand the node with the smallest tentative distance (using a min-heap).
"""
import heapq

def dijkstra(n, adj, src):
    INF = 10**18
    dist = [INF]*n
    dist[src] = 0
    pq = [(0, src)]
    while pq:
        d, u = heapq.heappop(pq)
        if d != dist[u]:
            continue
        for v, w in adj[u]:
            if dist[v] > d + w:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))
    return dist

if __name__ == "__main__":
    n, src = 5, 0
    adj = [[] for _ in range(n)]
    def add(u, v, w):
        adj[u].append((v,w))
    add(0,1,10); add(0,4,5); add(1,2,1); add(4,1,3); add(4,2,9); add(4,3,2);
    add(3,2,4); add(2,3,6); add(3,0,7)
    print(*dijkstra(n, adj, src))
    # Time Complexity: O((V + E) log V) — binary heap.
    # Space Complexity: O(V + E).
