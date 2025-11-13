"""
Kruskal's Algorithm for Minimum Spanning Tree
Task: Given a connected, undirected graph with weighted edges, find an MST using Kruskal's algorithm.
Return the sum of the weights of the edges in the MST.
Greedy strategy: Always pick the smallest weight edge that does not form a cycle (using DSU).
"""
class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.r = [0]*n
    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]
    def unite(self, a, b):
        a = self.find(a); b = self.find(b)
        if a == b:
            return False
        if self.r[a] < self.r[b]:
            a, b = b, a
        self.p[b] = a
        if self.r[a] == self.r[b]:
            self.r[a] += 1
        return True

def kruskal_mst(n, edges):
    edges.sort(key=lambda x: x[2])
    dsu = DSU(n)
    total = 0
    taken = 0
    for u, v, w in edges:
        if dsu.unite(u, v):
            total += w
            taken += 1
            if taken == n-1:
                break
    return total

if __name__ == "__main__":
    n = 4
    edges = [(0,1,10),(0,2,6),(0,3,5),(1,3,15),(2,3,4)]
    print(kruskal_mst(n, edges))  # 19
    # Time Complexity: O(E log E + E α(V)) ≈ O(E log E).
    # Space Complexity: O(V) — DSU.
