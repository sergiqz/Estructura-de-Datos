#ifndef NODE_H
#define NODE_H
#include "point.cpp"
#include "rgb.cpp"
using namespace std;
class Node{
  private:
    Point pos; 
    Rgb rgb;
    Node *child_topL; 
    Node *child_topR; 
    Node *child_botL; 
    Node *child_botR;
    Rgb *child_topL_rgb;
    Rgb *child_topR_rgb;
    Rgb *child_botL_rgb;
    Rgb *child_botR_rgb;
    int data; 

  public:  
    Node(Point _pos, Rgb _rgb);
    Node();
    void set_x(int _x);
    void set_y(int _y);
    void set_x_y(int _x,int _y);
    int get_x();
    int get_y();
    void set_r_g_b(int _r,int _g, int _b);
    Rgb get_rgb();
    Point get_pos();
    friend class Quad;
};

#endif 