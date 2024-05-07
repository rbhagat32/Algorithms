#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char name;
    int deadline, profit;
    Job(char name, int deadline, int profit)
    {
        this->name = name;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool comparator(struct Job a, struct Job b)
{
    return (a.profit > b.profit);
}

void jobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparator);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            // if free slot is found.
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i] == true)
            cout << arr[result[i]].name << " ";
}

int main()
{
    Job arr[] = {{'a', 2, 100},
                 {'b', 1, 19},
                 {'c', 2, 27},
                 {'d', 1, 25},
                 {'e', 3, 15}};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sequence of Jobs with maximum profits : ";

    jobScheduling(arr, n);
    return 0;
}
