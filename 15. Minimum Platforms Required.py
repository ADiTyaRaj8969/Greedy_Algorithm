"""
Minimum Platforms Required
Task: Given arrival and departure times of trains, find the minimum number of platforms
required so that no train has to wait.
Greedy strategy: Always add a platform for each arrival before the next departure, and remove one for each departure.
"""
def min_platforms(arr, dep):
    arr.sort(); dep.sort()
    i = j = 0
    plat = ans = 0
    n = len(arr)
    while i < n and j < n:
        if arr[i] <= dep[j]:
            plat += 1
            ans = max(ans, plat)
            i += 1
        else:
            plat -= 1
            j += 1
    return ans

if __name__ == "__main__":
    arr = [900, 940, 950, 1100, 1500, 1800]
    dep = [910, 1200, 1120, 1130, 1900, 2000]
    print(min_platforms(arr, dep))  # 3
    # Time Complexity: O(n log n) — sorting arrivals and departures.
    # Space Complexity: O(1) extra (ignoring input lists).
