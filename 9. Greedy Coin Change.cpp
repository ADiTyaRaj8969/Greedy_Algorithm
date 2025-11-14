// Greedy Coin Change
// Greedy strategy: Always take as many as possible of the largest coin denomination first (works
// for canonical systems). Task: Given a set of coin denominations (canonical system) and a target
// amount, find the minimum number of coins required to make the change.

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

pair<int, vector<int>> minCoins(vector<int> coins, int amount)
{
    sort(coins.rbegin(), coins.rend());
    vector<int> used;
    int cnt = 0;
    for (int c : coins)
    {
        while (amount >= c)
        {
            amount -= c;
            used.push_back(c);
            cnt++;
        }
    }
    if (amount != 0)
        return {-1, {}};
    return {cnt, used};
}

int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int amt = 1219;
    auto [cnt, used] = minCoins(coins, amt);
    cout << cnt << "\n";
    for (size_t i = 0; i < used.size(); ++i) cout << used[i] << (i + 1 == used.size() ? '\n' : ' ');
    return 0;
}

/*
Time Complexity: O(k log k + m) — sort k coin types, then greedy picks up to m/coin operations.
Space Complexity: O(m/coin_min) for the list of used coins (output), O(1) extra otherwise.
*/
