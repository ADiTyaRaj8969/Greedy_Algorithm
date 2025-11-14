// Maximum Meetings in One Room (Activity Selection variant)
// Greedy strategy: Always select the meeting with the earliest end time that does not overlap with
// the last selected meeting. Task: Given start and end times of n meetings, select the maximum
// number of non-overlapping meetings.

#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int maxMeetings(vector<int> s, vector<int> e)
{
    int n = static_cast<int>(s.size());
    vector<pair<int, int>> a;
    a.reserve(n);
    for (int i = 0; i < n; i++) a.emplace_back(e[i], s[i]);
    sort(a.begin(), a.end());
    int cnt = 0;
    int last = INT_MIN;
    for (auto& p : a)
    {
        if (p.second >= last)
        {
            cnt++;
            last = p.first;
        }
    }
    return cnt;
}

int main()
{
    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> e = {2, 4, 6, 7, 9, 9};
    cout << maxMeetings(s, e) << "\n";
    return 0;
}

/*
Time Complexity: O(n log n) — sorting by end time.
Space Complexity: O(n) — storing pairs of (end, start).
*/
