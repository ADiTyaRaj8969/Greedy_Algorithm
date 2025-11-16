// Task Scheduler (cooldown)
// Greedy strategy: Arrange the most frequent tasks first, filling idle slots optimally to minimize
// total time. Task: Given tasks (letters) and cooldown n, CPU does 1 task per unit. Find the
// minimum time required to finish all tasks.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int leastInterval(vector<char>& tasks, int n)
{
    vector<int> cnt(26, 0);
    for (char c : tasks) cnt[c - 'A']++;
    sort(cnt.begin(), cnt.end());
    int maxf = cnt.back();
    int maxCount = count(cnt.begin(), cnt.end(), maxf);
    int res = max(static_cast<int>(tasks.size()), (maxf - 1) * (n + 1) + maxCount);
    return res;
}

int main()
{
    vector<char> t = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << leastInterval(t, n) << "\n";
    return 0;
}

/*
Time Complexity: O(k log k + n) — counting/sorting task frequencies (k ≤ 26), effectively O(n).
Space Complexity: O(1) — fixed-size frequency array (26 letters).
*/
