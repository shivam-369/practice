//this program uses adjency list kind of graph structure

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)

int find_min_distance_node(vector<long int> dist, vector<int> non_visited)
{
    int index = non_visited[0] - 1;
    long min = dist[index];
    for (int i = index; i < dist.size(); i++)
    {
        if (dist[index] < min && find(non_visited.begin(), non_visited.end(), index + 1) != non_visited.end())
        {
            index = i;
            min = dist[index];
        }
    }
    return index + 1;
}

int main(int argc, char **argv)
{
    int vertices, edges, source, destination, length;
    cin >> vertices >> edges;
    vector<vector<pair<int, long>>> graph(vertices);
    for (int i = 0; i < edges; i++)
    {
        cin >> source >> destination >> length;
        graph[source - 1].push_back(make_pair(destination, length));
        graph[destination - 1].push_back(make_pair(source, length));
    }
    cin >> source >> destination;
    vector<int> visited;
    vector<int> non_visited(vertices);
    vector<long int> dist(vertices, MAX);
    dist[source - 1] = 0;
    for (int i = 0; i < vertices; i++)
    {
        non_visited[i] = i + 1;
    }

    while (non_visited.size() > 0)
    {
        int node = find_min_distance_node(dist, non_visited);
        auto ptr = find(non_visited.begin(), non_visited.end(), node);
        if (ptr != non_visited.end())
        {
            non_visited.erase(ptr);
        }
        visited.push_back(node);
        for (int i = 0; i < graph[node - 1].size(); i++)
        {
            if (dist[graph[node - 1][i].first - 1] > dist[node - 1] + graph[node - 1][i].second)
            {
                dist[graph[node - 1][i].first - 1] = dist[node - 1] + graph[node - 1][i].second;
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
    // for (int i = 0; i < vertices; i++)
    // {
    //     cout << "for node " << i + 1 << "\n";
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << graph[i][j].first << " " << graph[i][j].second << "\n";
    //     }
    // }
    return 0;
}