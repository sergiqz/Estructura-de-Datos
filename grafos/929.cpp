#include <iostream>
#include <cstdio>
#include <queue>



using namespace std;

int G[1000][1000];
bool visitado[1000][1000];
int distancia[1000][1000];
int const inf = 100000000;


class Edge {
public:
    int a, b;
    int peso;
    Edge(int nodo_a=0,int nodo_b=0,int pesoso=0){
        a=nodo_a;
        b=nodo_b;
        peso=pesoso;
    }
};




int dijkstra(int n, int m)
{
    const int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    queue<Edge> q;

    distancia[1][1] = G[1][1];
    q.push(Edge(1, 1, distancia[1][1]));

    for (int i = 0; i < n*m; i++)
    {
        while (!q.empty())
        {
            Edge edge = q.front();
            q.pop();

            visitado[edge.a][edge.b] = 0;
            for (int j = 0; j < 4; j++)
            {
                int x = edge.a + dir[j][0];
                int y = edge.b + dir[j][1];

                if ((x)!=0 and (x)<=(n) and (y)!=0 and (y)<=(m)){
                    if(distancia[edge.a][edge.b] + G[x][y] < distancia[x][y]){
                        
                        distancia[x][y] = distancia[edge.a][edge.b] + G[x][y];
                        
                        q.push(Edge(x, y, distancia[x][y]));
                    }
                }
            }
        }
    }

    return distancia[n][m];


}







int main()
{
    int Case;
    cin>>Case;
    while (Case--)
    {
        for (int i = 0; i < 1000; i++){
            for (int j = 0; j < 1000; j++){
               distancia[i][j] = inf;
                visitado[i][j] = false;
            }
        }
        int n, m;
        cin>>n>>m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin>>G[i][j];
            }
        }
        cout<<dijkstra(n, m)<<endl;
    }

    return 0;
}