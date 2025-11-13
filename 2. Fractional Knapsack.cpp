#include <bits/stdc++.h>
// Fractional Knapsack
// Greedy strategy: Always take as much as possible of the item with the highest value-to-weight
// ratio first. Task: Given the weights and values of n items, and a knapsack of capacity W, find
// the maximum total value you can carry. You are allowed to take fractions of an item.
using namespace std;

struct Item
{
    int value;
    int weight;
};

double fractionalKnapsack(vector<Item> items, int capacity)
{
    sort(items.begin(), items.end(),
         [](const Item& a, const Item& b)
         {
             return static_cast<double>(a.value) / a.weight >
                    static_cast<double>(b.value) / b.weight;
         });

    double result = 0.0;
    int cap = capacity;
    for (const auto& it : items)
    {
        if (it.weight <= cap)
        {
            result += it.value;
            cap -= it.weight;
        }
        else
        {
            result += static_cast<double>(it.value) * cap / it.weight;
            break;
        }
    }
    return result;
}

int main()
{
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    cout << fixed << setprecision(6) << fractionalKnapsack(items, W) << '\n';  // 240
    return 0;
}

/*
Time Complexity: O(n log n) — sorting items by value/weight ratio.
Space Complexity: O(1) extra (ignoring input storage) — in-place processing after sort.
*/
