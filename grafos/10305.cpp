#include <bits/stdc++.h>
using namespace std;

int n, m;
int grados[101];
int matrix[101][101];

vector<int> tsort;

void toposort(vector<int>& ts)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!grados[i]){
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u;
        u = q.front();
        q.pop();
        ts.push_back(u);
        for (int i = 1; i <= n; i++)
        {
            if (matrix[u][i])
            {
                if (--grados[i] == 0) q.push(i);
            }
        }
    }
}
int main()
{
    while (cin>>n>>m)
    {
        memset(grados, 0, sizeof(grados));
        memset(matrix, 0, sizeof(matrix));
        for (int i = 0; i < m; i++){
            int u, v;
            cin>>u>>v;
            matrix[u][v] = 1;
            grados[v]++;
        }
        tsort.clear();
        toposort(tsort);
        for (int i = 0; i < tsort.size(); i++){
            cout<<tsort[i];
        }
        if(n==0 and m==0){
            break;
        }
    }
    return 0;
}
