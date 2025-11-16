"""
Task Scheduler (cooldown)
Task: Given a list of tasks and cooldown n, CPU completes one task per time unit.
Find the minimum time to finish all tasks.
Greedy strategy: Arrange the most frequent tasks first, filling idle slots optimally to minimize total time.
"""
from collections import Counter

def least_interval(tasks, n):
    counts = sorted(Counter(tasks).values())
    maxf = counts[-1]
    max_count = counts.count(maxf)
    return max(len(tasks), (maxf - 1) * (n + 1) + max_count)

if __name__ == "__main__":
    print(least_interval(list("AAABBB"), 2))  # 8
    # Time Complexity: O(k log k + n), with k ≤ 26 → effectively O(n).
    # Space Complexity: O(1) — bounded frequency table.
