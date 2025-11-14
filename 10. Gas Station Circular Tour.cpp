// Gas Station Circular Tour
// Greedy strategy: Reset the start whenever the current fuel surplus drops below zero; only a
// global surplus allows a solution. Task: Given gas[i] and cost[i] around a circle, find a starting
// index if you can complete the circuit once; else return -1.

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost)
{
    int n = static_cast<int>(gas.size());
    int total = 0, curr = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        total += gas[i] - cost[i];
        curr += gas[i] - cost[i];
        if (curr < 0)
        {
            start = i + 1;
            curr = 0;
        }
    }
    return total >= 0 ? start % n : -1;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << canCompleteCircuit(gas, cost) << "\n";
    return 0;
}

/*
Time Complexity: O(n) — single pass over stations.
Space Complexity: O(1) — constant extra space.
*/
