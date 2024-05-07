#include <bits/stdc++.h>
using namespace std;

int MatrixChain(int arr[], int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    int count;
    for (int k = i; k < j; k++)
    {
        count = MatrixChain(arr, i, k, dp) + MatrixChain(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]);
        mini = min(count, mini);
    }

    return dp[i][j] = mini;
}

int main()
{
    int arr[] = {10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << "Minimum number of multiplications is " << MatrixChain(arr, 1, n - 1, dp);
    return 0;
}