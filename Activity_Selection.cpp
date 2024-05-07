#include <bits/stdc++.h>
using namespace std;

void activitySelection(int start[], int finish[], int n)
{
    cout << "Selected Activities are : ";

    int i = 0, j;
    cout << i << " ";

    for (j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            cout << j << " ";
            i = j;
        }
    }
}

int main()
{
    int start[] = {4, 1, 7, 12, 15};
    int finish[] = {6, 13, 13, 14, 19};
    int n = sizeof(start) / sizeof(start[0]);

    activitySelection(start, finish, n);
    return 0;
}