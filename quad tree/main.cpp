#include <iostream>
#include "quad.h"
#include <fstream>
using namespace std;
int main(){
	Quad matrix(Point(0, 0),Point(6,6));
    ofstream ficheroSalida;
    ficheroSalida.open ("kn305.ppm");
    ficheroSalida << "Texto para el fichero";
    ficheroSalida.close();

   Node a(Point(1, 1), 1); 
    Node b(Point(2, 5), 2); 
    Node c(Point(7, 6), 3); 
    matrix.insert(&a); 
    
    matrix.insert(&b); 
    matrix.insert(&c);

  // cout << "Node a: " << matrix.find(Point(1, 1)) <<endl;

    return 0;
}