#include "node.h"
    Node::Node(Point _pos, Rgb _rgb){
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
    Node::Node(){
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
    void Node::set_x(int _x){
    	pos.set_x(_x);
    }
    void Node::set_y(int _y){
    	pos.set_y(_y);
    }
    void Node::set_x_y(int _x,int _y){
		pos.set_x_y(_x,_y);
    }
    int Node::get_x(){
    	return pos.get_x();
    }
    int Node::get_y(){
    	return pos.get_y();
    }
    void Node::set_r_g_b(int _r,int _g, int _b){
        rgb.set_r_g_b(_r,_g,_b);
    }
    Rgb Node::get_rgb(){
        return rgb;   
    }
    Point Node::get_pos(){
        return pos;
    }