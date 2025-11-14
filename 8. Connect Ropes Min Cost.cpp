// Connect Ropes with Minimum Cost
// Greedy strategy: Always connect the two shortest ropes first (using a min-heap).
// Task: Given N ropes with different lengths, connect them into one rope with minimum total cost.
// Each time, connecting two ropes of lengths a and b costs a + b.

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minCost(vector<int>& a)
{
    priority_queue<int, vector<int>, greater<int>> pq(a.begin(), a.end());
    long long cost = 0;
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        int c = x + y;
        cost += c;
        pq.push(c);
    }
    return static_cast<int>(cost);
}

int main()
{
    vector<int> a = {4, 3, 2, 6};
    cout << minCost(a) << "\n";
    return 0;
}

/*
Time Complexity: O(n log n) — heapify O(n) + (n-1) extractions/insertions O(log n).
Space Complexity: O(n) — min-heap stores rope lengths.
*/
