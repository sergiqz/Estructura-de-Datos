#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;


vector <int> G[10000];
bool visitado[10000];
int total;


void dfs(int u)
{		
	if(visitado[u]){
		return;
	}
	total++;
	visitado[u]=true;
	for(auto v:G[u]){
		dfs(v);
	}
}


int main(){
	int casos, n, m, l, x, y, z;
	cin>>casos;
	while(casos--)
	{
		cin>>n>>m>>l;

		 for(int i=0;i<m;i++){
            cin>>x>>y;
            G[x].push_back(y);
        }
        for(int j=0;j<l;j++){
            cin>>z;
            if(visitado[z]==0)
            dfs(z);
        }
		cout<<total;
		total = 0;
		memset(visitado, 0, sizeof(visitado));
		for(int i = 0; i < n+1; i++){
			G[i].clear();
		}
		cout<<endl;
		
	}
	return 0;
}