#include <bits/stdc++.h>
using namespace std;

int knapSack(vector<int> &val, vector<int> &wt, int i, int w, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (wt[0] <= w)
            return val[0];

        return 0;
    }

    if (dp[i][w] != -1)
        return dp[i][w];

    int notTake = 0 + knapSack(val, wt, i - 1, w, dp);
    int take = 0;

    if (wt[i] <= w)
        take = val[i] + knapSack(val, wt, i - 1, w - wt[i], dp);

    return dp[i][w] = max(take, notTake);
}

int main()
{
    vector<int> val = {70, 20, 50};
    vector<int> wt = {11, 12, 13};
    int n = val.size();
    int w = 30; // capacity of knapsack.

    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    cout << "Maximum Profit that can be achieved : " << knapSack(val, wt, n - 1, w, dp);
    return 0;
}