#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &v, int l, int h, int x)
{
    if (l > h)
    {
        return -1;
    }

    int mid = (l + h) / 2;

    if (x == v[mid])
    {
        return mid;
    }

    if (x < v[mid])
    {
        return binary_search(v, l, mid - 1, x);
    }

    if (x > v[mid])
    {
        return binary_search(v, mid + 1, h, x);
    }
}

int main()
{
    vector<int> v = {0, 1, 2, 6, 8, 9, 18, 54, 60, 74, 112};
    cout << binary_search(v, 0, v.size() - 1, 8) << endl;
    return 0;
}