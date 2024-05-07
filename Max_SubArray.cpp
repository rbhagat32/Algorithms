#include <bits/stdc++.h>
using namespace std;

int max_subarray_sum(vector<int> &v, int l, int h)
{
    if (l == h)
    {
        return v[l];
    }

    int mid = (l + h) / 2;

    int leftMSS = max_subarray_sum(v, l, mid);
    int rightMSS = max_subarray_sum(v, mid + 1, h);

    int sum = 0;
    int left_sum = 0;
    for (int i = mid; i >= l; i--)
    {
        sum += v[i];
        left_sum = max(sum, left_sum);
    }

    sum = 0;
    int right_sum = 0;
    for (int i = mid + 1; i < h; i++)
    {
        sum += v[i];
        right_sum = max(sum, right_sum);
    }

    int crossMSS = left_sum + right_sum;

    return max(crossMSS, max(leftMSS, rightMSS));
}

int main()
{
    vector<int> v = {-1, 3, 4, -5, 9, -2};
    cout << max_subarray_sum(v, 0, v.size() - 1) << endl;
    return 0;
}