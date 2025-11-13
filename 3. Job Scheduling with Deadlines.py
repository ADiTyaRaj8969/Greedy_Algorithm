"""
Job Scheduling with Deadlines
Task: Given an array of jobs where every job has a deadline and an associated profit if the job is
finished before the deadline. Every job takes a single unit of time. Maximize total profit if only one
job can be scheduled at a time.
Greedy strategy: Schedule jobs with earliest deadlines first, always keeping the highest profit jobs within available slots.
"""
import heapq

def job_scheduling(deadline, profit):
    jobs = sorted(zip(deadline, profit))
    pq = []  # min-heap of profits
    for d, p in jobs:
        if len(pq) < d:
            heapq.heappush(pq, p)
        elif pq and pq[0] < p:
            heapq.heapreplace(pq, p)
    return len(pq), sum(pq)

if __name__ == "__main__":
    d = [2, 1, 2, 1, 1]
    p = [100, 19, 27, 25, 15]
    print(*job_scheduling(d, p))  # e.g. 2 127
    # Time Complexity: O(n log n) — sort by deadline + heap ops.
    # Space Complexity: O(n) — heap of profits.
