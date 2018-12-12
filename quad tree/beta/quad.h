#ifndef QUAD_H
#define QUAD_H
#include "node.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Quad{
  private:
  	Point botLeft; 
    Point topRight;
    
    Node *nn; 
    Quad *topL; 
    Quad *topR; 
    Quad *botL; 
    Quad *botR;
    int x;
    int y; 
    int matrix[9][9][3];
  public:  
    Quad(Point _botL, Point _topR){ 
        botLeft = _botL; 
        topRight = _topR;
        nn=NULL;
        //nn = new Node(Point((_botL.get_x()+_topR.get_x())/2, (_botL.get_y()+_topR.get_y())/2)
        //    , Rgb(matrix[(_botL.get_x()+_topR.get_x())/2][ (_botL.get_y()+_topR.get_y())/2][0],134,12)); 
        topL = NULL; 
        topR = NULL; 
        botL = NULL; 
        botR = NULL;

    } 
    Quad(){ 
        botLeft = Point(0, 0); 
        topRight = Point(0,0); 
        nn = NULL; 
        topL = NULL; 
        topR = NULL; 
        botL = NULL; 
        botR = NULL; 
    } 
    void getroot(){
       // cout<<nn->get_rgb().get_b()<<endl;         
    }


   Quad* get_botL(){
        return this->botL;
   }
    Quad* get_topR(){
        return this->topR;
   }
    Quad* get_topL(){
        return this->topL;
   }
    Quad* get_botR(){
        return this->botR;
   }



    Node* dividir(){
/*        cout<<"botl: "<<" X: "<<botLeft.get_x()<<" Y: "<<botLeft.get_y()<<"X: "<<((botLeft.get_x() + topRight.get_x()) / 2)<<"Y: "<<((botLeft.get_y() + topRight.get_y()) / 2)<<endl;
        cout<<"topL: "<<" X: "<<botLeft.get_x()<<" Y: "<<((botLeft.get_y() + topRight.get_y()) / 2)+1<<"X: "<<((botLeft.get_x() + topRight.get_x()) / 2)<<"Y: "<<topRight.get_y()<<endl;
        cout<<"botR: "<<" X: "<<((botLeft.get_x() + topRight.get_x()) / 2)+1<<" Y: "<<botLeft.get_y()<<"X: "<<topRight.get_x()<<"Y: "<<(botLeft.get_y() + topRight.get_y()) /2<<endl;
        cout<<"topR: "<<" X: "<<((botLeft.get_x() + topRight.get_x()) / 2)+1<<" Y: "<<((botLeft.get_y() + topRight.get_y()) / 2)+1<<"X: "<<topRight.get_x()<<"Y: "<<topRight.get_y()<<endl;
*/
        this->nn = new Node(Point((botLeft.get_x()+topRight.get_x())/2, (botLeft.get_y()+topRight.get_y())/2)
            , Rgb(matrix[(botLeft.get_x()+topRight.get_x())/2][ (botLeft.get_y()+topRight.get_y())/2][0],
                matrix[(botLeft.get_x()+topRight.get_x())/2][ (botLeft.get_y()+topRight.get_y())/2][1],
                matrix[(botLeft.get_x()+topRight.get_x())/2][ (botLeft.get_y()+topRight.get_y())/2][2]));

        this->botL = new Quad(Point(botLeft.get_x(), botLeft.get_y()), Point(((botLeft.get_x() + topRight.get_x()) / 2),((botLeft.get_y() + topRight.get_y()) / 2)));
        this->topL = new Quad( Point(botLeft.get_x(),((botLeft.get_y() + topRight.get_y()) / 2)+1)  ,Point((botLeft.get_x() + topRight.get_x()) / 2, topRight.get_y()));
        this->botR = new Quad(Point(((botLeft.get_x() + topRight.get_x()) / 2)+1 ,botLeft.get_y())  ,Point(topRight.get_x(), (botLeft.get_y() + topRight.get_y()) /2 )); 
        this->topR = new Quad( Point(((botLeft.get_x() + topRight.get_x()) / 2)+1 ,((botLeft.get_y() + topRight.get_y()) / 2)+1)   ,Point(topRight.get_x(), topRight.get_y())); 
        return nn;
    }
 
    void buscarcuadrante(Quad *cuadrante, int num_cuadrante, Node *root){

        int cont=0;
        int r,g,b;
        //cout<<root->get_x()<<root->get_y()<<endl;
        //cout<<root->get_rgb().get_r()<<endl;
        Node *aux;
        aux = new Node(Point((cuadrante->botLeft.get_x()+cuadrante->topRight.get_x())/2, (cuadrante->botLeft.get_y()+cuadrante->topRight.get_y())/2)
            ,Rgb(matrix[(cuadrante->botLeft.get_x()+cuadrante->topRight.get_x())/2][ (cuadrante->botLeft.get_y()+cuadrante->topRight.get_y())/2][0],
            matrix[(cuadrante->botLeft.get_x()+cuadrante->topRight.get_x())/2][ (cuadrante->botLeft.get_y()+cuadrante->topRight.get_y())/2][1],
            matrix[(cuadrante->botLeft.get_x()+cuadrante->topRight.get_x())/2][ (cuadrante->botLeft.get_y()+cuadrante->topRight.get_y())/2][2]));

        //cout<<aux->get_x()<<aux->get_y()<<endl;
        //cout<<aux->get_rgb().get_r()<<endl;

         int diferencia_color=0;
        /*if (abs(cuadrante->botLeft.get_x() - cuadrante->topRight.get_x()) <= 1 and
         abs(cuadrante->botLeft.get_y() - cuadrante->topRight.get_y() ) <= 1) { 
            cout<<"no se puede divir mas "<<endl;
            cout<<"X: "<<cuadrante->botLeft.get_x()<<" Y: "<<cuadrante->botLeft.get_y()<<" RGB: "<<matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][0]<<endl;
            cout<<"X: "<<cuadrante->topRight.get_x()<<" Y: "<<cuadrante->topRight.get_y()<<" RGB: "<<matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][0]<<endl;
            
            return; 
        } */
        if ((cuadrante->botLeft.get_x()==cuadrante->topRight.get_x()) and
         (cuadrante->botLeft.get_y()==cuadrante->topRight.get_y() )) { 
            //cout<<"no se puede divir mas "<<endl;
            //cout<<"X: "<<cuadrante->botLeft.get_x()<<" Y: "<<cuadrante->botLeft.get_y()<<" RGB: "<<matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][0]<<endl;
            //cout<<"X: "<<cuadrante->topRight.get_x()<<" Y: "<<cuadrante->topRight.get_y()<<" RGB: "<<matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][0]<<endl;
        r=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][0];
        g=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][1];
        b=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][2];       

        if(num_cuadrante==1){
           // cout<<"x: "<<cuadrante->botLeft.get_x()<<" y: "<<cuadrante->botLeft.get_y()<<endl;
           // cout<<"x: "<<cuadr ante->topRight.get_x()<<" y: "<<cuadrante->topRight.get_y()<<endl;
                Rgb* rgb1= new Rgb(r,g,b);
                root->child_topL_rgb=rgb1;
                cout<<"topL: "<<"R: "<<root->child_topL_rgb->get_r()<<endl;
            
            //cout<<"x: "<<aux->get_x()<<" y: "<<aux->get_y()<<" R: "<<aux->get_rgb().get_r()<<endl;
            //cout<<"child_topL"<<endl;
        }else if(num_cuadrante==2){
            
            
                Rgb* rgb2= new Rgb(r,g,b);
                root->child_topR_rgb=rgb2;
                cout<<"topR: "<<"R: "<<root->child_topR_rgb->get_r()<<endl;
            
            //cout<<"child_topR"<<endl;
        }else if(num_cuadrante==3){
            
            //cout<<"child_botL"<<endl;
            
                Rgb* rgb3= new Rgb(r,g,b);
                root->child_botL_rgb=rgb3;
                cout<<"botL: "<<"R: "<<root->child_botL_rgb->get_r()<<endl;
            
            //cout<<root->child_botL->get_y()<<endl;
        }else{
            //cout<<"child_botR"<<endl;
        
                Rgb* rgb4= new Rgb(r,g,b);
                root->child_botR_rgb=rgb4;
                cout<<"botR: "<<"R: "<<root->child_botR_rgb->get_r()<<endl;
            
        }

            return; 
        }





        r=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][0];
        g=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][1];
        b=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][2];
        /*
        cout<<"despues de dividir---------------------------------------"<<endl;
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                cout<<"y: "<<i<<" x: "<<j<<" Red: "<<matrix[i][j][0]<<endl;
            }
        }
        */

       // cout<<cuadrante->botLeft.get_x()<<cuadrante->botLeft.get_y()<<endl;


        //cout<<"r: "<<r<<" g: "<<g<<" b: "<<b<<endl;
        

        for(int i=cuadrante->botLeft.get_y();i<=cuadrante->topRight.get_y();i++){
            for(int j=cuadrante->botLeft.get_x();j<=cuadrante->topRight.get_x();j++){
               // cout<<"x: "<<i<<"y: "<<j<<endl;
                //cout<<" matrix +1:"<<matrix[i][j][0]<<endl;
                if(cuadrante->topRight.get_x()!=j){
                    
                
                //cout<<"x:"<<i<<" y:"<<j;
                //cout<<" RGB: "<<matrix[i][j][0]<<"RGB SIGUIENTE: "<<matrix[i][j+1][0]<<endl;
                    //int comp_x=
                    //int comp_y=

            

                if( (matrix[i][j][0]!= matrix[i][j+1][0]) or (matrix[i][j][1]!= matrix[i][j+1][1]) or (matrix[i][j][2]!= matrix[i][j+1][2])){
                    Quad *quad_inter=new Quad( Point(cuadrante->botLeft.get_x(),cuadrante->botLeft.get_y()) 
                     ,Point(cuadrante->topRight.get_x() , cuadrante->topRight.get_y()));          
                    diferencia_color=1;

                    //cout<<"x: "<<i<<"y: "<<j<<endl;
                  //  cout<<"x: "<<cuadrante->botLeft.get_x()<<"y: "<<cuadrante->botLeft.get_y()<<endl;
                   // cout<<"x: "<<cuadrante->topRight.get_x()<<"y: "<<cuadrante->topRight.get_y()<<endl;
                    //buscarcuadrante(quad_inter);
                    //cout<<"otro cuadrante "<<endl;
                    
           // cout<<"x: "<<cuadrante->botLeft.get_x()<<" y: "<<cuadrante->botLeft.get_y()<<endl;
           // cout<<"x: "<<cuadr ante->topRight.get_x()<<" y: "<<cuadrante->topRight.get_y()<<endl;
            
        if(num_cuadrante==1){
            root->child_topL=aux;
            //cout<<"x: "<<aux->get_x()<<" y: "<<aux->get_y()<<" R: "<<aux->get_rgb().get_r()<<endl;
            //cout<<"child_topL"<<endl;
        }else if(num_cuadrante==2){
                root->child_topR=aux;
            
            //cout<<"child_topR"<<endl;
        }else if(num_cuadrante==3){
            
            //cout<<"child_botL"<<endl;
                root->child_botL=aux;
            
            //cout<<root->child_botL->get_y()<<endl;
        }else{
            //cout<<"child_botR"<<endl;
                root->child_botR=aux;    
        }

                    quad_inter->buscar_cuadra();
                   /* quad_inter->buscarcuadrante(quad_inter->get_botR());
                    quad_inter->buscarcuadrante(quad_inter->get_topL());
                    quad_inter->buscarcuadrante(quad_inter->get_topR());
                    quad_inter->buscarcuadrante(quad_inter->get_botL());
                */

                }
            }


            }
        }

        //cout<<cuadrante->topRigh. t.get_y()<<endl;
      /* for(int i=cuadrante->botLeft.get_y();i<cuadrante->topRight.get_y();i++){
                               
            if( matrix[i][0][0]!= matrix[i+1][0][0]){
                Quad *quad_inter=new Quad( Point(cuadrante->botLeft.get_x(),cuadrante->botLeft.get_y()) 
                     ,Point(cuadrante->topRight.get_x() , cuadrante->topRight.get_y()));
                quad_inter->buscar_cuadra();
            }
                        
        }
        */

        if(num_cuadrante==1){
           // cout<<"x: "<<cuadrante->botLeft.get_x()<<" y: "<<cuadrante->botLeft.get_y()<<endl;
           // cout<<"x: "<<cuadr ante->topRight.get_x()<<" y: "<<cuadrante->topRight.get_y()<<endl;
            
            
            if(diferencia_color ==0){

                Rgb* rgb1= new Rgb(r,g,b);
                root->child_topL_rgb=rgb1;
                cout<<"topL: "<<"R: "<<root->child_topL_rgb->get_r()<<endl;
            }
            //cout<<"x: "<<aux->get_x()<<" y: "<<aux->get_y()<<" R: "<<aux->get_rgb().get_r()<<endl;
            //cout<<"child_topL"<<endl;
        }else if(num_cuadrante==2){
            
            if(diferencia_color ==0){
                Rgb* rgb2= new Rgb(r,g,b);
                root->child_topR_rgb=rgb2;
                cout<<"topR: "<<"R: "<<root->child_topR_rgb->get_r()<<endl;
            }
            //cout<<"child_topR"<<endl;
        }else if(num_cuadrante==3){
            
            //cout<<"child_botL"<<endl;
            if(diferencia_color ==0){
                Rgb* rgb3= new Rgb(r,g,b);
                root->child_botL_rgb=rgb3;
                cout<<"botL: "<<"R: "<<root->child_botL_rgb->get_r()<<endl;
            }
            //cout<<root->child_botL->get_y()<<endl;
        }else{
            //cout<<"child_botR"<<endl;
            if(diferencia_color ==0){
                Rgb* rgb4= new Rgb(r,g,b);
                root->child_botR_rgb=rgb4;
                cout<<"botR: "<<"R: "<<root->child_botR_rgb->get_r()<<endl;
            }
        }

        return;
    
    }

    void print(Node *n){
        //cout<<n->child_topL_rgb<<endl;
        
        if(n!=NULL){
            //cout<<"x: "<<n->get_x()<<" y: "<<n->get_y()<<" RED: "<<n->get_rgb().get_r()<<endl;
            if(n->child_topL!=NULL){
                //cout<<"child_topL"<<endl;
                print(n->child_topL);
            }if(n->child_topL==NULL){

                cout<<"R: "<<n->child_topL_rgb->get_r()<<" G: "<<n->child_topL_rgb->get_g()<<" B: "<<n->child_topL_rgb->get_b()<<endl;
            }
            if(n->child_topR!=NULL){
                //cout<<"child_topR"<<endl;
                print(n->child_topR);
            }if(n->child_topR==NULL){
                cout<<"R: "<<n->child_topR_rgb->get_r()<<" G: "<<n->child_topR_rgb->get_g()<<" B: "<<n->child_topR_rgb->get_b()<<endl;
            }
            if(n->child_botL!=NULL){
                //cout<<"child_botL"<<endl;
                print(n->child_botL);
            }if(n->child_botL==NULL){
                cout<<"R: "<<n->child_botL_rgb->get_r()<<" G: "<<n->child_botL_rgb->get_g()<<" B: "<<n->child_botL_rgb->get_b()<<endl;
            }

            if(n->child_botR!=NULL){
                //cout<<"child_botR"<<endl;
                print(n->child_botR);
            }if(n->child_botR==NULL){
                 cout<<"R: "<<n->child_botR_rgb->get_r()<<" G: "<<n->child_botR_rgb->get_g()<<" B: "<<n->child_botR_rgb->get_b()<<endl;       
            }
            
        }
    
    }
    void print(){
        //cout<<this->nn->get_x()<<" "<<this->nn->get_y()<<endl;
        print(this->nn);
    }








    void buscar_cuadra(){
        this->transformar_bidimensional();   
        //this->dividir();
        //cout<<topL->botLeft.get_x()<<topL->botLeft.get_y()<<endl;
        //cout<<topL->topRight.get_x()<<topL->topRight.get_y()<<endl;   
        nn=this->dividir();
        this->buscarcuadrante(this->get_botL(),3,nn); 
        //cout<<topR->botLeft.get_x()<<topR->botLeft.get_y()<<endl;
        //cout<<topR->topRight.get_x()<<topR->topRight.get_y()<<endl;
        //cout<<this->dividir()->get_x()<<" "<<this->dividir()->get_y()<<endl;
        
        //cout<<"botL"<<endl;   
        this->buscarcuadrante(this->get_topR(),2,nn);
        //cout<<"topR"<<endl;   
        this->buscarcuadrante(this->get_topL(),1,nn);
        //cout<<"topL"<<endl;   
        this->buscarcuadrante(this->get_botR(),4,nn);
        //cout<<nn->child_topL_rgb<<endl;

    }

    void transformar_bidimensional(){
    
        int **imagenn=cargar_una_imagen();
        
        int cont=0;

        //i fila j columna
        for(int i=7;i>=0;i--){
            for(int j=0;j<8;j++){
                matrix[i][j][0]=imagenn[cont][0];
                matrix[i][j][1]=imagenn[cont][1];
                matrix[i][j][2]=imagenn[cont][2];
                //cout<<"i: "<<i<<"j: "<<j<<" RGB: "<<matrix[i][j][0]<<endl;
                cont++;
            }
        }
    
    }



    int **cargar_una_imagen(){
        int **imagen;
        imagen= new int* [(8*8)+1];
        for(int i=0;i<(8*8)+1;i++){
            imagen[i]=new int[3];
        }

        string ruta = "img/prueba2.txt";
        int cont=0;
        string temp;
        ifstream infile(ruta.c_str());
        while(infile.good()){
            infile>>temp;
            int r,g,b;

            int head=0;
            int tail=temp.find(",");
            istringstream subs1(temp.substr(head,tail));
            subs1>>r;

            head=tail+1;
            tail=temp.find(",",tail+1);
            istringstream subs2(temp.substr(head,tail-head));
            subs2>>g;
            istringstream subs3(temp.substr(tail+1,temp.length()-tail));
            subs3>>b;
            //cout<<r<<" "<<g<<" "<<b<<endl;
            imagen[cont][0] = r;
            imagen[cont][1] = g;
            imagen[cont][2] = b;
            
            //cout<<"R: "<<imagen[cont][0]<<"G: "<<imagen[cont][1]<<"B: "<<imagen[cont][2]<<endl;


        
            cont++;
        }

        return imagen;
    }


};

#endif 