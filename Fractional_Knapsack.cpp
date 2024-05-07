#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit, weight;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

bool comparator(struct Item a, struct Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(struct Item arr[], int n, int w)
{
    sort(arr, arr + n, comparator);

    double ans = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight < w)
        {
            w -= arr[i].weight;
            ans += arr[i].profit;
        }
        else
        {
            ans += arr[i].profit * (double(w) / double(arr[i].weight));
            break;
        }
    }

    return ans;
}

int main()
{
    int w = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Total Profit : " << fractionalKnapsack(arr, n, w);
    return 0;
}