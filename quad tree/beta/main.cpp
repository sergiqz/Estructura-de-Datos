#include <iostream>
#include "quad.h"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

















int main(){








 
    
    Quad quad_matrix(Point(0, 0),Point(7,7));
    //matrix.buscar_cuadra();
    //quad_matrix.transformar_bidimensional();
    
    quad_matrix.buscar_cuadra();
   // quad_matrix.print();
   // matrix.dividir_cua();
    //cout<<"matrixxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    //matrix.transformar_bidimensional();
    

    //Node a(Point(3, 3), Rgb(454,134,12)); 
    //Node b(Point(9, 2), Rgb(34,135,123)); 
    //Node c(Point(7, 6), Rgb(34,134,54));
    //matrix.insert(&a);
























/*
    Node *nodess[12*6]; 
    
    for(int i=0;i<12*6;i++){ 
        nodess[i]= new Node(Point(),Rgb());  
    }
     cont=0;
    for(int i=12;i>0;i--){
        for(int j=1;j<=6;j++){
            nodess[cont]->set_x_y(i,j);
            nodess[cont]->set_r_g_b(imagen[cont][0],imagen[cont][1],imagen[cont][2]);
            cont++;
        }
    }
*/
    //for(int i=0;i<6*12;i++){ 
       // cout<<nodess[i]->get_pos().get_x()<<" "<<nodess[i]->get_pos().get_y()<<endl;  
        //cout<<"i: "<<i<<" "<<nodess[i]->get_rgb().get_r()<<endl;
    //}
/*
    for(int i=0;i<6*12;i++){ 
        if(i==(6*12)-1){
            break;
        }
        if(   (nodess[i]->get_rgb().get_r()!=nodess[i+1]->get_rgb().get_r())
        or  nodess[i]->get_rgb().get_g()!=nodess[i+1]->get_rgb().get_g()
        or  nodess[i]->get_rgb().get_b()!=nodess[i+1]->get_rgb().get_b()){
            //cout<<i+1<<endl;
            //cout<<"POS"<<nodess[i+1]->get_pos().get_y()<<endl;
           // matrix.insert(nodess[i+1]);
            //matrix.insert(nodess[i+1]);
            //red=nodess[cont]->get_rgb()->get_r();

        }
    }
    */
    //matrix.insert(&a);
    //matrix.insert(&b);
   // matrix.insert(nodess[12]);
    //  matrix.insert(nodess[14]);
    //cout<<nodess[16]->get_pos().get_x()<<endl;
    //matrix.insert(nodess[12]);
    //matrix.insert(nodess[56]);







    //matrix.insert(&a); 
    
    //matrix.insert(&b); 
    //matrix.insert(&c);
    //cout<<a.get_rgb().get_g()<<endl;

   //cout << "Node a: " << matrix.find(Point(1, 1)) <<endl;

    return 0;
}