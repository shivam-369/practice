#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
    int edge_count, length, source, destination, vertice_count, index = 0;
    cin >> vertice_count;
    cin >> edge_count;

    vector<pair<int, pair<int, int>>> edges(edge_count);
    vector<pair<int, pair<int, int>>> MST;
    set<int> visited;
    for (int i = 0; i < edge_count; i++)
    {
        cin >> length >> source >> destination;
        edges[i].first = length;
        edges[i].second.first = source;
        edges[i].second.second = destination;
    }
    sort(edges.begin(), edges.end());
    /*for (int i = 0; i < edge_count; i++)
    {
        cout << edges[i].first << " " << edges[i].second.first << " " << edges[i].second.second << endl;
    }*/
    while (MST.size() != vertice_count - 1)
    {
        if (visited.find(edges[index].second.first) == visited.end() || visited.find(edges[index].second.second) == visited.end())
        {
            MST.push_back(make_pair(edges[index].first, make_pair(edges[index].second.first, edges[index].second.second)));
            visited.insert(edges[index].second.first);
            visited.insert(edges[index].second.second);
        }
        index++;
    }
    int MST_length = 0;
    for (auto edge : MST)
    {
        MST_length += edge.first;
    }

    cout << "MST_ of Minimum spanning tree is: " << MST_length << endl;
    cout << "Edges of Minimum Spanning tree are: \n";
    for (auto edge : MST)
    {
        cout << edge.second.first << "->" << edge.second.second << "\n";
    }
    return 0;
}