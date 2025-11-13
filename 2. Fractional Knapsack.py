"""
Fractional Knapsack
Task: Given the weights and values of n items, and a knapsack of capacity W, find the maximum
total value you can carry. You are allowed to take fractions of an item.
Greedy strategy: Always take as much as possible of the item with the highest value-to-weight ratio first.
"""
def fractional_knapsack(values, weights, capacity):
    items = sorted(((v, w) for v, w in zip(values, weights)), key=lambda x: x[0]/x[1], reverse=True)
    res = 0.0
    cap = capacity
    for v, w in items:
        if w <= cap:
            res += v
            cap -= w
        else:
            res += v * (cap / w)
            break
    return res

if __name__ == "__main__":
    val = [60, 100, 120]
    wt = [10, 20, 30]
    W = 50
    print(f"{fractional_knapsack(val, wt, W):.6f}")  # 240.000000
    # Time Complexity: O(n log n) — sorting by value/weight ratio.
    # Space Complexity: O(1) extra (ignoring input lists).
