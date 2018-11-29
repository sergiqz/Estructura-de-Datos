#ifndef POINT_H
#define POINT_H

using namespace std;

class Point{
  private:
    int x; 
    int y; 
  public:  
    Point(int _x=0, int _y=0){
        x=_x;
        y=_y;
    }
    void set_x(int _x){
    	x=_x;
    }
    void set_y(int _y){
    	y=_y;
    }
    void set_x_y(int _x,int _y){
    	x=_x;
    	y=_y;
    }
    int get_x(){
    	return x;
    }
    int get_y(){
    	return y;
    }

};

#endif 