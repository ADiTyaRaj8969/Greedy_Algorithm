"""
Prim's Algorithm for Minimum Spanning Tree
Task: Given a connected, undirected graph with weighted edges, find an MST using Prim's algorithm.
Return the sum of the weights of the edges in the MST.
Greedy strategy: Always expand the MST by picking the smallest edge crossing the cut (using a min-heap).
"""
import heapq

def prim_mst(n, adj):
    visited = [False]*n
    pq = [(0, 0)]  # (weight, node)
    total = 0
    count = 0
    while pq and count < n:
        w, u = heapq.heappop(pq)
        if visited[u]:
            continue
        visited[u] = True
        total += w
        count += 1
        for v, wt in adj[u]:
            if not visited[v]:
                heapq.heappush(pq, (wt, v))
    return total if count == n else float('inf')

if __name__ == "__main__":
    n = 4
    adj = [[] for _ in range(n)]
    def add(u, v, w):
        adj[u].append((v,w)); adj[v].append((u,w))
    add(0,1,10); add(0,2,6); add(0,3,5); add(1,3,15); add(2,3,4)
    print(prim_mst(n, adj))  # 19
    # Time Complexity: O(E log V) — binary heap.
    # Space Complexity: O(V + E) — adjacency + heap.
