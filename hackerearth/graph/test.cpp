#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char ** argv)
{
    int n, m, start, end, queries;
    cin >> n >> m;
    vector < vector < int > > graph (n + 1, vector<int >(n + 1, 0));
    for(int i = 0; i < m; i++)
    {
        cin >> start >> end;
        graph[start][end] = 1;
        graph[end][start] = 1; 
    }
    cin >> queries;
    int * a = new int[queries];
    int * b = new int[queries];
    for(int i = 0; i < queries; i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < queries; i++)
    {
        if(graph[a[i]][b[i]] == 1 || graph[b[i]][a[i]])
        {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}