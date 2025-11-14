// Assign Mice to Holes
// Greedy strategy: Sort both lists and pair each mouse to the closest available hole in order.
// Task: Given positions of n mice and n holes on a line, assign each mouse to a hole to minimize
// the maximum |x - y|.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int assignMiceHoles(vector<int> mice, vector<int> holes)
{
    sort(mice.begin(), mice.end());
    sort(holes.begin(), holes.end());
    int n = static_cast<int>(mice.size());
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, abs(mice[i] - holes[i]));
    return ans;
}

int main()
{
    vector<int> mice = {4, -4, 2};
    vector<int> holes = {4, 0, 5};
    cout << assignMiceHoles(mice, holes) << "\n";
    return 0;
}

/*
Time Complexity: O(n log n) — sorting mice and holes arrays.
Space Complexity: O(1) extra (ignoring input arrays).
*/
