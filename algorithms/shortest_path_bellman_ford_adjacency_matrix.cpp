// This program uses adjacency matrix representation of graph

#include <iostream>
#include <vector>
using namespace std;

#define MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7) // assuming this value aas infinity

int main(int argc, char **argv)
{
    /*
        vertices = total vertices in graph
        edges = total edges in graph
        source = node from which edge is originated
        destination = node at which edge ends
        length = edge length 
    */
    int vertices, edges, source, destination, length;
    cin >> vertices >> edges;
    long int **graph = new long int *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        graph[i] = new long int[vertices];
    }
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

    // taking input of edges
    for (int i = 0; i < edges; i++)
    {
        cin >> source >> destination >> length;
        graph[source - 1][destination - 1] = length;
        graph[destination - 1][source - 1] = length;
    }
    // source from whic shortest distance to every node has to find
    cin >> source;
    vector<vector<int>> paths(vertices);
    long int *dist = new long[vertices];

    // initializing distance array to assumed infinity
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = MAX;
    }

    //distance of source node is 0
    dist[source - 1] = 0;
    vector<int> path;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (dist[j] > dist[i] + graph[i][j])
            {
                dist[j] = dist[i] + graph[i][j];
                path = paths[i];

                // path.push_back(i + 1);

                path.push_back(j + 1);
                paths[j] = path;
            }
        }
    }

    // printing distance array
    cout << "\nshortest distance to every node \n";
    for (int i = 0; i < vertices; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";

    //printing path for every node
    cout << "\npath of shortest distance to every node \n";
    for (int i = 0; i < vertices; i++)
    {
        cout << i + 1 << " - ";
        if (i + 1 != source)
            cout << source << " -> ";
        else
            cout << source;
        for (int j = 0; j < paths[i].size(); j++)
        {
            cout << paths[i][j];
            if (j != paths[i].size() - 1)
                cout << " -> ";
        }
        cout << "\n";
    }
    delete[] dist, delete[] graph;
    cout << "\n";
    return 0;
}