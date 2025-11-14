"""
Assign Mice to Holes
Task: There are n mice and n holes on a line. Assign each mouse to a hole such that the maximum
time |x - y| taken by any mouse is minimized.
Greedy strategy: Sort both lists and pair each mouse to the closest available hole in order.
"""
def assign_mice_to_holes(mice, holes):
    mice.sort(); holes.sort()
    return max(abs(m - h) for m, h in zip(mice, holes)) if mice else 0

if __name__ == "__main__":
    print(assign_mice_to_holes([4,-4,2], [4,0,5]))  # 4
    # Time Complexity: O(n log n) — sorting both arrays.
    # Space Complexity: O(1) extra (ignoring input lists).
