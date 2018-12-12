#ifndef NODE_H
#define NODE_H
#include "point.h"
#include "rgb.h"
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
    Node(Point _pos, Rgb _rgb){
        pos = _pos; 
        rgb=_rgb;
        child_topL=NULL; 
        child_topR=NULL; 
        child_botL=NULL; 
        child_botR=NULL;
        child_topL_rgb=NULL;
        child_topR_rgb=NULL;
        child_botL_rgb=NULL;
        child_botR_rgb=NULL;

    }
    Node(){
        pos = Point(0,0); 
        rgb=Rgb(0,0,0);
        child_topL=NULL; 
        child_topR=NULL; 
        child_botL=NULL; 
        child_botR=NULL;
        child_topL_rgb=NULL;
        child_topR_rgb=NULL;
        child_botL_rgb=NULL;
        child_botR_rgb=NULL;
    }



    void set_x(int _x){
    	pos.set_x(_x);
    }
    void set_y(int _y){
    	pos.set_y(_y);
    }
    void set_x_y(int _x,int _y){
		pos.set_x_y(_x,_y);
    }
    int get_x(){
    	return pos.get_x();
    }
    int get_y(){
    	return pos.get_y();
    }
    void set_r_g_b(int _r,int _g, int _b){
        rgb.set_r_g_b(_r,_g,_b);
    }


    Rgb get_rgb(){
        return rgb;   
    }
    Point get_pos(){
        return pos;
    }
    friend class Quad;
};

#endif 