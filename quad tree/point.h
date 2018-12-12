#ifndef POINT_H
#define POINT_H
using namespace std;
class Point{
  private:
    int x; 
    int y; 
  public:  
    Point(int _x, int _y);
    void set_x(int _x);
    void set_y(int _y);
    void set_x_y(int _x,int _y);
    int get_x();
    int get_y();
};

#endif 