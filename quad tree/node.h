#ifndef NODE_H
#define NODE_H
#include "point.h"
using namespace std;

class Node{
  private:
    Point pos; 
    int data; 
  public:  
    Node(Point _pos, int _data=0){
        pos = _pos; 
        data = _data;
    }

};

#endif 