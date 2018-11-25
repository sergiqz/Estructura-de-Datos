#ifndef QUAD_H
#define QUAD_H
#include "node.h"
using namespace std;

class Quad{
  private:
  	Point point; 
    
    Node *n; 
  
    Quad *topL; 
    Quad *topR; 
    Quad *botL; 
    Quad *botR; 
  public:  
    Quad(){ 
        point = Point(0, 0); 
        n = NULL; 
        topL = NULL; 
        topR = NULL; 
        botL = NULL; 
        botR = NULL; 
    } 

    void insert(Node *n){ 
    
    if(node == NULL){ 
        return; 
  	}
    }

};

#endif 