#include <stdio.h>
#include <map>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int grados[101];

    string tragos_nom[101];
    vector<int> G[101];
    bool visitado[101];
    int n;

queue<int> toposort(){
    queue<int> resultado;
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (!grados[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        resultado.push(v);
        visitado[v] = 1;
        for(auto o:G[v]){
            grados[o]--;
        }
        if(q.empty()){
            for(int i=0;i<n;i++){
                if((grados[i]==0) and (!visitado[i])){
                    q.push(i);
                    break;
                }
            }
        }
    }
    return resultado;
}
















int main() {
    int  m;
    int cases=1;

    while(cin>>n) {
        map<string, int> tragos;
        for(int i = 0; i < n; i++) {
            string nombre_del_trago;
            cin >> nombre_del_trago;
            tragos.insert(pair<string,int>(nombre_del_trago,i));
            tragos_nom[i]=nombre_del_trago;
        }
        cin >> m;

        while(m--) {
            string trago_empi;
            string trago_termi;
            cin >> trago_empi >> trago_termi;
            int x = tragos[trago_empi];
            int y = tragos[trago_termi];
            G[x].push_back(y);
            grados[y]++;
        }


        for(int i=0;i<n;i++){
            sort(G[i].begin(),G[i].end());
        }
        queue<int> resultado = toposort();


        printf("Case #%d: Dilbert should drink beverages in this order:",cases);
    

        while(!resultado.empty()){
            printf(" %s",tragos_nom[resultado.front()].data());
            resultado.pop();
        }
        printf(".\n\n");
        cases++;

        for(int i=0;i<n;i++){
            G[i].clear();
        }
        memset(grados, 0, sizeof(grados));
        memset(visitado, 0, sizeof(visitado));

        
    
    }
    return 0;
}