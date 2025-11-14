// Merge Overlapping Intervals
// Greedy strategy: Always merge intervals if they overlap, otherwise start a new merged interval.
// Task: Given a collection of time intervals, merge all overlapping intervals.

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> v)
{
    if (v.empty())
        return {};
    sort(v.begin(), v.end());
    vector<pair<int, int>> res;
    res.push_back(v[0]);
    for (size_t i = 1; i < v.size(); ++i)
    {
        if (v[i].first <= res.back().second)
            res.back().second = max(res.back().second, v[i].second);
        else
            res.push_back(v[i]);
    }
    return res;
}

int main()
{
    vector<pair<int, int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto r = mergeIntervals(v);
    for (auto& p : r) cout << '[' << p.first << ',' << p.second << "] ";
    cout << '\n';
    return 0;
}

/*
Time Complexity: O(n log n) — sorting intervals, then linear merge.
Space Complexity: O(n) — for the merged output list.
*/
