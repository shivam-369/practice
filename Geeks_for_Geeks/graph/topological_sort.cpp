#include <iostream>
#include <stack>
#include <vector>

using namespace std;


void topological_sort(int root, vector < vector < int > > graph, vector < int > &visited, stack < int > &order)
{
    if(visited[root - 1] == 0)
    {
        visited[root - 1] = 1;

        for(int i = 0; i < graph[root - 1].size(); i++)
        {
            topological_sort(graph[root - 1][i], graph, visited, order);
        }

        order.push(root);
    }

}

int main(int argc, char ** argv)
{
    int vertices, edges, source, destination;

    cin >> vertices;

    vector < vector < int > > graph(vertices);

    cin >> edges;

    stack < int > order;
    vector < int > visited(vertices, 0);

    int root; 

    for(int i = 0; i < edges; i++)
    {
        cin >> source >> destination;

        graph[source - 1].push_back(destination);

    }

    for(int i = 0; i < vertices; i++)
    {
        if(visited[i] == 0)
        {
            topological_sort(i + 1, graph, visited, order);
        }
    }
   

   while(!order.empty())
   {
       cout << order.top() << " ";
       order.pop();
   }

   cout << "\n";

    return 0;
}