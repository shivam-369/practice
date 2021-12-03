#include <iostream>
#include <queue>
#include <vector>

using namespace std;


void kahn(vector < vector < int > > graph, vector < int > &indegree, queue < int > &order, vector < int > &visited)
{
    // cout << "calling kahn\n";
    int temp = order.front();

    order.pop();

    visited[temp - 1] = 1;
    cout << temp << " ";

    for(int i = 0; i < graph[temp -1].size(); i++)
    {
            indegree[graph[temp - 1][i] - 1] -= 1;
    }

    for(int i = 0; i < indegree.size(); i++)
    {
        if(indegree[i] == 0 && visited[i] == 0)
        {
            order.push(i + 1);
            visited[i] = 1;
        }
    }

}



int main(int argc, char** argv)
{
    int vertices, edges, source, destination;

    cin >> vertices;

    vector < vector < int > > graph(vertices);

    cin >> edges;

    vector < int > indegree(vertices, 0);
    vector < int > visited(vertices, 0);

    queue < int > order;

    for(int i = 0; i < edges; i++)
    {
        cin >> source >> destination;

        graph[source - 1].push_back(destination);

    }

    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            indegree[graph[i][j] - 1] += 1;
        }
    }

    for(int i = 0; i < indegree.size(); i++)
    {
        if(indegree[i] == 0)
        {
            order.push(i + 1);
            visited[i] = 1;
        }
    }


    while(!order.empty())
    {
        kahn(graph, indegree, order, visited);
    }

    cout << "\n";
    return 0;
}