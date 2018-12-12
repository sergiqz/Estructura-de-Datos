#ifndef QUAD_H
#define QUAD_H
#include "node.cpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Quad{
  private:
  	Point botLeft; 
    Point topRight;
    
    Node *nn; 
    Quad *topL; 
    Quad *topR; 
    Quad *botL; 
    Quad *botR;
    int x;
    int y; 
    int matrix[9][9][3];
  public:  
    Quad(Point _botL, Point _topR);
    Quad();
    Quad* get_botL();
    Quad* get_topR();
    Quad* get_topL();
    Quad* get_botR();
    Node* dividir();
    void buscarcuadrante(Quad *cuadrante, int num_cuadrante, Node *root);
    void print(Node *n);
    void print();
    void buscar_cuadra();
    void transformar_bidimensional();
    int **cargar_una_imagen();
};

#endif 