#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

class BFSTree
{
    int a[20][20], visited[20], n;

public:
    void bfs(int);
    void get();
};

void BFSTree::get()
{
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
        visited[i] = 0;

    cout << "Enter the Adjacency Matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    bfs(0);
}

void BFSTree::bfs(int startNode)
{
    queue<int> q;
    visited[startNode] = 1;
    cout << "\t" << startNode + 1;

    q.push(startNode);

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        for (int i = 0; i < n; ++i)
        {
            if (a[currentNode][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                cout << "\t" << i + 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    BFSTree b;
    b.get();
    system("pause");
    return 0;
}

