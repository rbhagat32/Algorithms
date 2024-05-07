#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int h)
{
    int mid = (l + h) / 2;

    int i = l, j = mid + 1, k = 0;
    vector<int> sorted(h - l + 1, -1);

    while (i <= mid && j <= h)
    {
        if (v[i] <= v[j])
        {
            sorted[k++] = v[i++];
        }
        else
        {
            sorted[k++] = v[j++];
        }
    }

    while (i <= mid)
    {
        sorted[k++] = v[i++];
    }

    while (j <= h)
    {
        sorted[k++] = v[j++];
    }

    int x = l;
    int y = 0;
    while (x <= h)
    {
        v[x++] = sorted[y++];
    }
}

void merge_sort(vector<int> &v, int l, int h)
{
    if (l >= h)
    {
        return;
    }

    int mid = (l + h) / 2;

    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, h);

    merge(v, l, h);
}

int main()
{
    vector<int> v = {9, 3, 7, 5, 6, 4, 8, 2};
    merge_sort(v, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}