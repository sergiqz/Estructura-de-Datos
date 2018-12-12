#include "point.h"
    Point::Point(int _x=0, int _y=0){
        x=_x;
        y=_y;
    }
    void Point::set_x(int _x){
    	x=_x;
    }
    void Point::set_y(int _y){
    	y=_y;
    }
    void Point::set_x_y(int _x,int _y){
    	x=_x;
    	y=_y;
    }
    int Point::get_x(){
    	return x;
    }
    int Point::get_y(){
    	return y;
    }
