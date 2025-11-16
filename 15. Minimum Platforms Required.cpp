// Minimum Platforms Required
// Greedy strategy: Always add a platform for each arrival before the next departure, and remove one
// for each departure. Task: Given arrival and departure times of trains, find the minimum number of
// platforms required so that no train has to wait.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minPlatforms(vector<int> arr, vector<int> dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0, j = 0, n = static_cast<int>(arr.size());
    int plat = 0, ans = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            plat++;
            ans = max(ans, plat);
            i++;
        }
        else
        {
            plat--;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minPlatforms(arr, dep) << "\n";
    return 0;
}

/*
Time Complexity: O(n log n) — sorting arrival and departure times, two-pointer scan is linear.
Space Complexity: O(1) extra (ignoring the input arrays).
*/
