#ifndef NODE_H
#define NODE_H
#include "point.h"
#include "rgb.h"
using namespace std;

class Node{
  private:
    Point pos; 
    Rgb rgb;
    int data; 

  public:  
    Node(Point _pos, Rgb _rgb){
        pos = _pos; 
        rgb=_rgb;
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
    Rgb get_rgb(){
        return rgb;   
    }
    Point get_pos(){
        return pos;
    }

};

#endif 