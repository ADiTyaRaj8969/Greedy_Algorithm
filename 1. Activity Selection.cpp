// Activity Selection
// Greedy strategy: Always select the activity with the earliest finish time that does not overlap
// with the last selected activity. Task: You are given n activities with their start and finish
// times. Select the maximum number of activities that can be performed by a single person, assuming
// that a person can only work on a single activity at a time. Return the count of activities.

#include <bits/stdc++.h>
using namespace std;

int activitySelection(vector<int>& start, vector<int>& finish)
{
    const int n = static_cast<int>(start.size());
    if (n == 0)
        return 0;

    vector<pair<int, int>> activities;
    activities.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        activities.emplace_back(finish[i], start[i]);
    }
    sort(activities.begin(), activities.end());

    int count = 1;
    int lastFinish = activities[0].first;
    for (int i = 1; i < n; ++i)
    {
        if (activities[i].second >= lastFinish)
        {
            ++count;
            lastFinish = activities[i].first;
        }
    }
    return count;
}

int main()
{
    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> f = {2, 4, 6, 7, 9, 9};
    cout << activitySelection(s, f) << '\n';  // 4
    return 0;
}

/*
Time Complexity: O(n log n) — sorting activities by finish time dominates.
Space Complexity: O(n) — to store pairs of (finish, start).
*/
