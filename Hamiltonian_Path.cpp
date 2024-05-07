#include <bits/stdc++.h>
using namespace std;

const int V = 5;

void printSolution(int path[])
{
    cout << "Solution Exists : ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";

    cout << path[0] << endl;
}

bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    // check if there is an edge from the previous vertex in the path to the current vertex.
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // check if the vertex has already been included in the path.
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool helper(bool graph[V][V], int path[], int pos)
{
    if (pos == V)
    {
        // check if there is an edge from the last vertex back to the first vertex.
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            // add vertex v to the path.
            path[pos] = v;

            // recursion to construct rest of the path.
            if (helper(graph, path, pos + 1) == true)
                return true;

            // if adding vertex v doesn't lead to a solution, then remove it -> backtracking.
            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonian(bool graph[V][V])
{
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (helper(graph, path, 1) == false)
    {
        cout << "Solution does not exist.";
        return false;
    }

    printSolution(path);
    return true;
}

int main()
{
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 1},
                         {0, 1, 1, 1, 0}};

    hamiltonian(graph1);

    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};

    hamiltonian(graph2);

    return 0;
}
