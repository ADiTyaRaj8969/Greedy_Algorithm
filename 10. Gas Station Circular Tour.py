"""
Gas Station Circular Tour
Task: There are n gas stations; gas[i] is fuel at i and cost[i] to go to i+1.
Find starting index if you can travel the entire circuit once, else return -1.
Greedy strategy: Reset the start whenever the current fuel surplus drops below zero; only a global surplus allows a solution.
"""
def can_complete_circuit(gas, cost):
    total = 0
    curr = 0
    start = 0
    for i, (g, c) in enumerate(zip(gas, cost)):
        total += g - c
        curr += g - c
        if curr < 0:
            start = i + 1
            curr = 0
    return start % len(gas) if total >= 0 else -1

if __name__ == "__main__":
    gas = [1,2,3,4,5]
    cost = [3,4,5,1,2]
    print(can_complete_circuit(gas, cost))  # 3
    # Time Complexity: O(n) — single traversal.
    # Space Complexity: O(1) — constant extra space.
