#include <iostream>
#include "quad.h"
using namespace std;
int main(){
	Quad matrix(Point(0, 0),Point(6,6));
   Node a(Point(1, 1), 1); 
    Node b(Point(2, 5), 2); 
    Node c(Point(7, 6), 3); 
    matrix.insert(&a); 
    cout<<"otro nodo"<<endl;
    matrix.insert(&b); 
    matrix.insert(&c);
	


    return 0;
}