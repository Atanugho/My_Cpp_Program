#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool cmp(Item i1, Item i2)
{

    double v_w_i1 = static_cast<double>(i1.value) / i1.weight;
    double v_w_i2 = static_cast<double>(i2.value) / i2.weight;

    return v_w_i1 > v_w_i2;
}

double fractional_knapsack(int w, vector<Item> &items)
{

    double ans;
    sort(items.begin(), items.end(), cmp);

    for (const auto &item : items)
    {
        if (item.weight <= w)
        {
            ans += item.value;
            w -= item.weight;
        }
        else
        {
            double fraction = static_cast<double>(w) / item.weight;
            ans += fraction * item.value;
            w = 0;
        }
    }

    return ans;
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<Item> items;
    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> v >> w;
        Item it;
        it.value = v;
        it.weight = w;
        items.push_back(it);
    }

    cout << fractional_knapsack(w, items);

    return 0;
}