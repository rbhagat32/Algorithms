#include <bits/stdc++.h>
using namespace std;

int minimumNumberOfCoins(vector<int> &coins, int i, int target, vector<vector<int>> dp)
{
    if (i == 0)
    {
        if (target % coins[0] == 0)
            return target / coins[0];

        return INT_MAX;
    }

    if (dp[i][target] != -1)
        return dp[i][target];

    int notTake = 0 + minimumNumberOfCoins(coins, i - 1, target, dp);
    int take = INT_MAX;

    if (coins[i] <= target)
        take = 1 + minimumNumberOfCoins(coins, i, target - coins[i], dp);

    return dp[i][target] = min(take, notTake);
}

int main()
{
    vector<int> coins = {3, 5, 10};
    int n = coins.size();
    int target = 1;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    cout << "Minimum Number of Coins Required : ";
    cout << minimumNumberOfCoins(coins, n - 1, target, dp) << endl;
}
