"""
Merge Overlapping Intervals
Task: Given a collection of intervals, merge all overlapping intervals.
Greedy strategy: Always merge intervals if they overlap, otherwise start a new merged interval.
"""
def merge_intervals(intervals):
    if not intervals:
        return []
    intervals.sort()
    res = [intervals[0][:]]
    for s, e in intervals[1:]:
        if s <= res[-1][1]:
            res[-1][1] = max(res[-1][1], e)
        else:
            res.append([s, e])
    return res

if __name__ == "__main__":
    print(merge_intervals([[1,3],[2,6],[8,10],[15,18]]))  # [[1,6],[8,10],[15,18]]
    # Time Complexity: O(n log n) — sorting + linear merge.
    # Space Complexity: O(n) — merged output.
