#include <bits/stdc++.h>
// Job Scheduling with Deadlines
// Greedy strategy: Schedule jobs with earliest deadlines first, always keeping the highest profit
// jobs within available slots. Task: Given jobs with deadlines and profits (each takes 1 unit
// time), schedule to maximize profit if only one job can be scheduled at a time.
using namespace std;
// Returns {count, totalProfit}
pair<int, int> jobSequencing(vector<int> deadline, vector<int> profit)
{
    const int n = static_cast<int>(deadline.size());
    vector<pair<int, int>> jobs;
    jobs.reserve(n);
    for (int i = 0; i < n; ++i) jobs.emplace_back(deadline[i], profit[i]);
    sort(jobs.begin(), jobs.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (const auto& job : jobs)
    {
        if (static_cast<int>(pq.size()) < job.first)
        {
            pq.push(job.second);
        }
        else if (!pq.empty() && pq.top() < job.second)
        {
            pq.pop();
            pq.push(job.second);
        }
    }

    int cnt = 0, prof = 0;
    while (!pq.empty())
    {
        prof += pq.top();
        pq.pop();
        ++cnt;
    }
    return {cnt, prof};
}

int main()
{
    vector<int> d = {2, 1, 2, 1, 1};
    vector<int> p = {100, 19, 27, 25, 15};
    auto [c, s] = jobSequencing(d, p);
    cout << c << ' ' << s << '\n';
    return 0;
}

/*
Time Complexity: O(n log n) — sorting by deadline and heap operations overall O(n log n).
Space Complexity: O(n) — priority queue can hold up to n profits.
*/
