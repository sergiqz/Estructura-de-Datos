#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Edge {
public:
    int a, b;
};
Edge edge;
int const inf = 100000000;
bool visitado[20000];
int distancia[20000];
vector<Edge> G[20000];


void SPFA(int st, int ed) {
    queue<int> q;
    q.push(st);
    distancia[st] = 0;
    int u;
    while(!q.empty()) {
        u = q.front();
        q.pop();
        visitado[u] = 0;
        for(auto g:G[u]) {
            if(!visitado[g.a]) {
                if(distancia[u] + g.b<distancia[g.a]) {
                    distancia[g.a] = distancia[u] + g.b;
                    q.push(g.a);
                }
            }
        }
    }
    if(distancia[ed] == inf){
        cout<<"unreachable"<<endl;
    }
    else{       
        cout<<distancia[ed];
        cout<<endl;
    }
}



int main() {
    int N;
    int x, y, w, n, m, S, T;
    cin>>N;
    int Case = 0;
    while(N--) {
        cin>>n>>m>>S>>T;
        for(int i = 0; i < n; i++) {
            G[i].clear();
        }
        while(m--) {

            cin>>x>>y>>edge.b;
            edge.a = y;
            G[x].push_back(edge);
            edge.a = x;
            G[y].push_back(edge);

        }
        
        printf("Case #%d: ", ++Case);
        for(int i = 0; i < n; i++){
            distancia[i] = inf;
        }
        SPFA(S, T);
        memset(visitado, 0, sizeof(visitado));
        
    }
    return 0;
}