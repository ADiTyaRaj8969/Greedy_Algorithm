"""
Greedy Coin Change
Task: Given a set of coin denominations (e.g., [1,2,5,...]) and a target amount, find the minimum
number of coins required to make the change (works for canonical coin systems).
Greedy strategy: Always take as many as possible of the largest coin denomination first (works for canonical systems).
"""
def greedy_coin_change(coins, amount):
    coins = sorted(coins, reverse=True)
    used = []
    for c in coins:
        while amount >= c:
            amount -= c
            used.append(c)
    if amount != 0:
        return -1, []
    return len(used), used

if __name__ == "__main__":
    coins = [1,2,5,10,20,50,100,200,500,2000]
    amt = 1219
    cnt, used = greedy_coin_change(coins, amt)
    print(cnt)
    print(*used)
    # Time Complexity: O(k log k + m) — sort coin types and greedy picks.
    # Space Complexity: O(m/coin_min) for output list, O(1) extra otherwise.
