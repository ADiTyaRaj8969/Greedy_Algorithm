"""
Connect n Ropes with Minimum Cost
Task: You are given n ropes of different lengths. The cost to connect two ropes is equal to the sum
of their lengths. Connect the ropes into a single rope with minimum possible cost.
Greedy strategy: Always connect the two shortest ropes first (using a min-heap).
"""
import heapq

def min_cost(ropes):
    pq = list(ropes)
    heapq.heapify(pq)
    cost = 0
    while len(pq) > 1:
        a = heapq.heappop(pq)
        b = heapq.heappop(pq)
        c = a + b
        cost += c
        heapq.heappush(pq, c)
    return cost

if __name__ == "__main__":
    print(min_cost([4,3,2,6]))  # 29
    # Time Complexity: O(n log n) — heap operations.
    # Space Complexity: O(n) — heap of lengths.
