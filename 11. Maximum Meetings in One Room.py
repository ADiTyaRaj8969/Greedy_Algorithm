"""
Maximum Meetings in One Room (Activity Selection variant)
Task: There is one meeting room. Given start and end times of n meetings, find the maximum
number of meetings that can be accommodated (select max non-overlapping meetings).
Greedy strategy: Always select the meeting with the earliest end time that does not overlap with the last selected meeting.
"""
def max_meetings(start, end):
    meetings = sorted(zip(end, start))
    cnt = 0
    last = -10**18
    for e, s in meetings:
        if s >= last:
            cnt += 1
            last = e
    return cnt

if __name__ == "__main__":
    s = [1,3,0,5,8,5]
    e = [2,4,6,7,9,9]
    print(max_meetings(s, e))  # 4
    # Time Complexity: O(n log n) — sort by end time.
    # Space Complexity: O(n) — to hold pairs.

# Greedy strategy: Always select the meeting with the earliest end time that does not overlap with the last selected meeting.
