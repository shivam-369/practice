#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
using namespace std;

struct edge
{

    int length;
    int source;
    int destination;
};

int main(int argc, char **argv)
{
    int edge_count, vertice_count, length, source, destination;

    cin >> vertice_count >> edge_count;

    vector<vector<pair<int, int>>> graph(vertice_count);
    vector<pair<pair<int, int>, int>> MST;
    set<int> visited;
    for (int i = 0; i < edge_count; i++)
    {
        cin >> length >> source >> destination;
        graph[source].push_back(make_pair(destination, length));
        graph[destination].push_back(make_pair(source, length));
    }

    cin >> source;

    visited.insert(source);

    pair<pair<int, int>, int> min_edge;
    while (MST.size() != vertice_count - 1 && visited.size() != vertice_count)
    {
        min_edge.second = INT32_MAX;
        for (int node : visited)
        {
            for (int i = 0; i < graph[node].size(); i++)
            {
                if (graph[node][i].second < min_edge.second && find(visited.begin(), visited.end(), graph[node][i].first) == visited.end())
                {
                    min_edge.first.first = node;
                    min_edge.first.second = graph[node][i].first;
                    min_edge.second = graph[node][i].second;
                }
            }
        }
        visited.insert(min_edge.first.first);
        visited.insert(min_edge.first.second);
        MST.push_back(min_edge);
    }

    int MST_length = 0;

    cout << "MST edges:\n";
    for (auto edge : MST)
    {
        cout << edge.first.first << "-> " << edge.first.second << "\n";
        MST_length += edge.second;
    }

    cout << "MST Lenght:\n";
    cout << MST_length << "\n";

    return 0;
}