"""
Activity Selection
Task: You are given n activities with their start and finish times. Select the maximum number of
activities that can be performed by a single person, assuming that a person can only work on a
single activity at a time. Return the count of activities.
Greedy strategy: Always select the activity with the earliest finish time that does not overlap with the last selected activity.
"""
def activity_selection(start, finish):
    activities = sorted(zip(finish, start))
    if not activities:
        return 0
    count = 1
    last_end = activities[0][0]
    for f, s in activities[1:]:
        if s >= last_end:
            count += 1
            last_end = f
    return count

if __name__ == "__main__":
    s = [1, 3, 0, 5, 8, 5]
    f = [2, 4, 6, 7, 9, 9]
    print(activity_selection(s, f))  # 4
    # Time Complexity: O(n log n) — sorting by finish time.
    # Space Complexity: O(n) — to store paired activities.
