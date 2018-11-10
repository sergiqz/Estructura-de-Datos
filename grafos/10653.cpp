#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;
int G[1000][1000];

int visitado[1000][1000];
int cost[1000][1000];
int X[] = {-1,0,0,1};
int Y[] = {0,-1,1,0};
int n,m,sx,sy,ex,ey;


void bfs(int x,int y)
{
    queue<int> q;
    memset(visitado,0,sizeof (visitado));
    memset(cost,0,sizeof (cost));
    int vx,vy,f;
    q.push(x);
    q.push(y);
    visitado[x][y]=1;
    cost[x][y]=0;
    while(!q.empty()){
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        f=0;
        for(int i=0; i<4; i++)
        {
            vx=x+X[i];
            vy=y+Y[i];
            if(vx>=0 and vx<n and vy>=0 and vy<m and G[vx][vy]!=1)
            {
                if(visitado[vx][vy]==0)
                {
                    q.push(vx);
                    q.push(vy);
                    visitado[vx][vy]=1;
                    cost[vx][vy]=cost[x][y]+1;
                }
            }
            if(vx==ex and vy==ey){
                cout<<cost[vx][vy]<<endl;

                f=1;
                return;
            }
        }
        
    }

}
int main()
{
    int t,a,b,x;
    while(cin>>n>>m)
    {
        if(n==0 and m==0){
            break;
        }
        cin>>t;
        memset(G,0,sizeof(G));
        for(int i=0; i<t; i++){
            cin>>a>>x;
            for(int j=0; j<x; j++){
                cin>>b;
                G[a][b]=1;
            }
        }
        cin>>sx>>sy>>ex>>ey;
        bfs(sx,sy);
    }
    return 0;
}