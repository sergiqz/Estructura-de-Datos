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
        cout<<"insert"<<endl;


        if(n == NULL){ 
            return;
        }
        //si esta en el quad
        if (!(n->get_x() >= botLeft.get_x() and n->get_x() <= topRight.get_x() and n->get_y() >= botLeft.get_y() and n->get_y() <= topRight.get_y())){
            cout<<"no esta en el quad"<<endl;
            return; 
         }
        //nose puede divir mas
        if (abs(botLeft.get_x() - topRight.get_x()) <= 1 and abs(botLeft.get_y() - topRight.get_y() ) <= 1) { 
            cout<<"nose puede dividir mas"<<endl;
            return; 
        } 
        cout<<(botLeft.get_x() + topRight.get_x()) / 2<<endl;
        cout<<(botLeft.get_y() + topRight.get_y()) / 2<<endl;
   
        if ((botLeft.get_x() + topRight.get_x()) / 2  >= n->get_x()){
            if ((botLeft.get_y() + topRight.get_y()) / 2 >= n->get_y()){
                if(botL == NULL){
                    botL = new Quad(Point(botLeft.get_x(), botLeft.get_y()), Point((botLeft.get_x() + topRight.get_x()) / 2,(botLeft.get_y() + topRight.get_y()) / 2));
                    botL->insert(n); 
                }
           }else{
                if (topL == NULL){ 
                
                    topL = new Quad( Point(botLeft.get_x(),(botLeft.get_y() + topRight.get_y()) / 2)  ,Point((botLeft.get_x() + topRight.get_x()) / 2, topRight.get_y())); 
            
                    topL->insert(n);
                } 
            }
 
        }else{
            if((botLeft.get_y() + topRight.get_y()) / 2 >= n->get_y()){
                if (botR == NULL){
                    botR = new Quad( Point((botLeft.get_x() + topRight.get_x()) / 2 ,botLeft.get_y())  ,Point(topRight.get_x(), (botLeft.get_y() + topRight.get_y()) /2 )); 
                    botR->insert(n);
                }
            }else{
                if (topR == NULL){
                    topR = new Quad( Point((botLeft.get_x() + topRight.get_x()) / 2 ,(botLeft.get_y() + topRight.get_y()) / 2)   ,Point(topRight.get_x(), topRight.get_y())); 
                    topR->insert(n);
                }
            }
        }


}


};

#endif 