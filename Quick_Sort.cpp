#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int h)
{
    int pivot = v[l];

    int count = 0;
    for (int i = l + 1; i <= h; i++)
    {
        if (v[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = l + count;
    swap(v[l], v[pivotIndex]);

    int i = l, j = h;
    while (i < pivotIndex && j > pivotIndex)
    {
        if (v[i] <= pivot)
        {
            i++;
        }
        else if (v[j] > pivot)
        {
            j--;
        }
        else
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(vector<int> &v, int l, int h)
{
    if (l >= h)
    {
        return;
    }

    int partitionIndex = partition(v, l, h);

    quickSort(v, l, partitionIndex - 1);
    quickSort(v, partitionIndex + 1, h);
}

int main()
{
    vector<int> v = {9, 3, 7, 5, 6, 4, 8, 2};
    quickSort(v, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}