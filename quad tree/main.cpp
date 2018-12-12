#include <iostream>
#include "quad.cpp"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
int main(){
    Quad quad_matrix(Point(0, 0),Point(7,7));
    quad_matrix.buscar_cuadra();
   // quad_matrix.print();
    return 0;
}