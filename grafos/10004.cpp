#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
 
vector<vector<int> > G;
vector<int> color;
 
bool recolor(int u) {
    for(auto v:G[u]) {
        if(color[v] != 0 and color[v] == color[u]) {
            return false;
        }
        if(color[v] == 0) {
            if(color[u] == 1){
                color[v]=2;
            }else{
                color[v]=1;
            }
            recolor(v);
        }
    }
    return true;
}
 
int main() {
int n, l, a, b;

    while(cin>>n) {
        if(n == 0){ 
            break;
        }
        cin>>l;
        G.clear();
        G.resize(n);
        color.assign(n, 0); 
        for(int i = 0; i < l; i++) {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
 
        color[0] = 1;
        if(recolor(0)){
            cout<<"BICOLORABLE."<<endl;
        }else{
            cout<<"NOT BICOLORABLE."<<endl;
        }
    }
}