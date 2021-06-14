// This program uses adjacency matrix representation of graph

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)

// function to find the node which is not visited and having minimum distance
int find_min_distance_element(long int dist[], int size, vector<int> non_visited)
{
    int index = non_visited[0] - 1;
    long int min = dist[index];

    for (int i = index; i < size; i++)
    {
        if (dist[i] <= min && find(non_visited.begin(), non_visited.end(), i + 1) != non_visited.end())
        {
            min = dist[i];
            index = i;
        }
    }
    return index + 1;
}

int main(int argc, char **argv)
{
    int vertices, edges, source, destination, length, node;
    cin >> vertices >> edges;

    long int **graph = new long int *[vertices];

    // a vector to maintain path to every node
    vector<vector<int>> paths(vertices);

    for (int i = 0; i < vertices; i++)
    {
        graph[i] = new long int[vertices];
    }

    //initializing graph with assumed infinity value
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = MAX;
        }
    }

    long int *dist = new long int[vertices];

    // intializing distance array to assumed infinity
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = MAX;
    }

    //taking input of edges
    for (int i = 0; i < edges; i++)
    {
        cin >> source >> destination >> length;
        graph[source - 1][destination - 1] = length;
        graph[destination - 1][source - 1] = length;
    }

    // source from which minimum distance has to find
    cin >> source;

    // making distance of source node 0
    dist[source - 1] = 0;

    vector<int> non_visited;
    vector<int> visited;

    // intializing non-visited list
    for (int i = 0; i < vertices; i++)
    {
        non_visited.push_back(i + 1);
    }

    vector<int> path;
    //calculating minimum distance for every node
    while (non_visited.size() > 0)
    {
        node = find_min_distance_element(dist, vertices, non_visited);
        auto ptr = find(non_visited.begin(), non_visited.end(), node);

        non_visited.erase(ptr);
        visited.push_back(node);
        for (int i = 0; i < vertices; i++)
        {
            if (graph[node - 1][i] < MAX)
            {
                if (dist[i] > dist[node - 1] + graph[node - 1][i])
                {
                    dist[i] = dist[node - 1] + graph[node - 1][i];
                    path = paths[node - 1];
                    path.push_back(i + 1);
                    paths[i] = path;
                }
            }
        }
    }

    //printing minimum distance for every node
    cout << "\nminimum distance to every node \n";
    for (int i = 0; i < vertices; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";

    //printing path for minimum distance to every node

    cout << "\npath to every node with minimum distance\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << i + 1 << " - " << source;
        if (source != i + 1)
            cout << " -> ";
        for (int j = 0; j < paths[i].size(); j++)
        {
            cout << paths[i][j];
            if (j != paths[i].size() - 1)
                cout << " -> ";
        }
        cout << "\n";
    }
    return 0;
}
