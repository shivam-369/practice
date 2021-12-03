#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int find_parent(vector<pair<int, int>> parent_list, int index)
{
    if (parent_list[index].first != index)
    {
        parent_list[index].first = find_parent(parent_list, parent_list[index].first);
    }
    return parent_list[index].first;
}

int main(int argc, char **argv)
{
    int edge_count, length, source, destination, vertice_count, index = 0;
    cin >> vertice_count;
    cin >> edge_count;

    vector<pair<int, pair<int, int>>> edges(edge_count);
    vector<pair<int, pair<int, int>>> MST;
    vector<pair<int, int>> parent_list(vertice_count);

    for (int i = 0; i < vertice_count; i++)
    {
        parent_list[i].first = i;
        parent_list[i].second = 0;
    }

    for (int i = 0; i < edge_count; i++)
    {
        cin >> length >> source >> destination;
        edges[i].first = length;
        edges[i].second.first = source;
        edges[i].second.second = destination;
    }

    sort(edges.begin(), edges.end());

    while (MST.size() != vertice_count - 1)
    {
        for (auto edge : edges)
        {
            int xroot = find_parent(parent_list, edge.second.first);
            int yroot = find_parent(parent_list, edge.second.second);

            if (xroot != yroot)
            {
                MST.push_back(edge);
                parent_list[xroot].first = yroot;
                parent_list[yroot].second++;
            }
        }
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