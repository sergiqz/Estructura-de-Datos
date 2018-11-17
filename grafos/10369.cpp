#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Puntos
{
public:
	int x, y;
	Puntos(int _x, int _y){
		x=_x;
		y=_y;
	}
};


class Edge 
{
public:
	int x, y;
	double peso;
	Edge(int _x, int _y,double _peso){
		x=_x;
		y=_y;
		peso=_peso;
	}
};


vector<Puntos> puntos;
vector<Edge> edge;
int Set[501];

bool sort_s(Edge edg_1, Edge edg_2){

    return edg_1.peso < edg_2.peso;

}

int find(int x)
{
    if (Set[x] == x)
        return x;
    return Set[x] = find(Set[x]);
}


bool join(const Edge &E, vector<double> &pesoedge)
{
    int a = find(E.x);
    int b = find(E.y);
    if (a == b) {
        return false;
    }
    Set[a] = b;
    pesoedge.push_back(E.peso);
    return true;
}







int main(){
	
	int casos, s, p,x,y;
	cin>>casos;
	while(casos--){
		cin>>s>>p;

		for(int i=0;i<p;i++){
			cin>>x>>y;
			puntos.push_back(Puntos(x, y));
			Set[i] = i;
		}
		
        for (int i = 0; i < p; ++i) {
            for (int j = i + 1; j < p; ++j) {
                double L = sqrt(pow(puntos[i].x - puntos[j].x, 2) + pow(puntos[i].y - puntos[j].y, 2));
                edge.push_back(Edge(i, j, L));

            }
        }		
  		sort (edge.begin(), edge.end(), sort_s);

  		



        vector<double> pesoedge;

        for (int i = 0, nedges = 0; nedges != p - 1; ++i) {
            if (join(edge[i], pesoedge)) ++nedges;
        }

        printf("%.2f\n", pesoedge[p-s-1]);
        edge.clear();
        puntos.clear();
	}

	return 0;
}