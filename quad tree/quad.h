#ifndef QUAD_H
#define QUAD_H
#include "node.h"
using namespace std;

class Quad{
  private:
  	Point botLeft; 
    Point topRight;
    
    Node *n; 
  
    Quad *topL; 
    Quad *topR; 
    Quad *botL; 
    Quad *botR; 
  public:  
    Quad(Point _botL, Point _topR){ 
        botLeft = _botL; 
        topRight = _topR; 
        n = NULL; 
        topL = NULL; 
        topR = NULL; 
        botL = NULL; 
        botR = NULL; 
    } 
    Quad(){ 
        botLeft = Point(0, 0); 
        topRight = Point(0,0); 
        n = NULL; 
        topL = NULL; 
        topR = NULL; 
        botL = NULL; 
        botR = NULL; 
    } 

    void insert(Node *n){ 
  
        if(n == NULL){ 
            return;
        }
        cout<<topRight.get_x()<<endl;
        cout<<topRight.get_y()<<endl;
        if ((botLeft.get_x() + topRight.get_x()) / 2 ){
            if ((botLeft.get_y() + topRight.get_y()) / 2 >= n->get_y()){
                if(botL == NULL){ 
                    botL = new Quad(Point(botLeft.get_x(), botLeft.get_y()), Point((botLeft.get_x() + topRight.get_x()) / 2,(botLeft.get_y() + topRight.get_y()) / 2));
                    botL->insert(n); 
                }
           }else{
                if (botR == NULL){ 
                    botR = new Quad( Point((botLeft.get_x() + topRight.get_x())/ 2,(botLeft.get_y())),Point(topRight.get_x(),(botLeft.get_y() + topRight.get_y()) / 2 )); 
                    botR->insert(n);
                } 
            }
 
        /*}else{
            if(){

            }*/
        }


    }

};

#endif 