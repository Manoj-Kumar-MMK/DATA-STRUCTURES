#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    list<int> *adj;
    vector<bool> vis;
    Graph(int v)
    {
        this->v=v;
        adj=new list<int> [v];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS()
    {
        vis.assign(v,false);
        for (int i = 0; i < v; i++)
            if (!vis[i])
                bfs(i);
    }
    void bfs(int u)
    {
        queue<int> q;
        q.push(u);
        vis[u] = true;
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            cout << u << "->";

            for (auto it = adj[u].begin(); it != adj[u].end(); it++)
            {
                if (!vis[*it])
                {
                    q.push(*it);
                    vis[*it] = true;
                }
            }
        }
    }

    void DFS()
    {
        vis.assign(v,false);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
                dfs(i);
        }
    }

    void dfs(int u)
    {
        vis[u] = true;
        cout << u << "->";

        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            if (!vis[*it])
                dfs(*it);
        }
    }
};

int main()
{
    char yn;
    int u, v, e, choice;
    cout << "Enter the number of vertices and edges of the graph:";
    cin >> v>>e;
    Graph g(v);
    for (int i = 0; i < e; i++)
    {
        cout << "Enter veretex 1 and vertex 2 for the edge:";
        cin >> u >> v;
        g.addEdge(u, v);
    }
    do
    {
        cout<<"OPERATIONS:\n1.BFS\n2.DFS\n3.No of paths\n4.print different paths\n";
        cout<<"Enter your choice:";        
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.BFS();
            break;
        case 2:
            g.DFS();
            break;
        case 3:
            cout << "Enter source and destination vertex";
            cin >> u >> v;
            break;
        case 4:
            cout << "Enter source and destination vertex";
            cin >> u >> v;
            break;
        default:
            cout << "Invalid response";
            break;
        }
        cout << "\nDo you want to try again:";
        cin >> yn;
    } while (yn == 'y');
    return 0;
}
