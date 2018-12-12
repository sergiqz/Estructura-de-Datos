#include "quad.h"  
    Quad::Quad(Point _botL, Point _topR){ 
        botLeft = _botL; 
        topRight = _topR;
        nn=NULL;
        topL = NULL; 
        topR = NULL; 
        botL = NULL; 
        botR = NULL;

    } 
    Quad::Quad(){ 
        botLeft = Point(0, 0); 
        topRight = Point(0,0); 
        nn = NULL; 
        topL = NULL; 
        topR = NULL; 
        botL = NULL; 
        botR = NULL; 
    } 
   Quad* Quad::get_botL(){
        return this->botL;
   }
    Quad* Quad::get_topR(){
        return this->topR;
   }
    Quad* Quad::get_topL(){
        return this->topL;
   }
    Quad* Quad::get_botR(){
        return this->botR;
   }    



    Node* Quad::dividir(){
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
 
    void Quad::buscarcuadrante(Quad *cuadrante, int num_cuadrante, Node *root){

        int cont=0;
        int r,g,b;
        Node *aux;
        aux = new Node(Point((cuadrante->botLeft.get_x()+cuadrante->topRight.get_x())/2, (cuadrante->botLeft.get_y()+cuadrante->topRight.get_y())/2)
            ,Rgb(matrix[(cuadrante->botLeft.get_x()+cuadrante->topRight.get_x())/2][ (cuadrante->botLeft.get_y()+cuadrante->topRight.get_y())/2][0],
            matrix[(cuadrante->botLeft.get_x()+cuadrante->topRight.get_x())/2][ (cuadrante->botLeft.get_y()+cuadrante->topRight.get_y())/2][1],
            matrix[(cuadrante->botLeft.get_x()+cuadrante->topRight.get_x())/2][ (cuadrante->botLeft.get_y()+cuadrante->topRight.get_y())/2][2]));

    
        int diferencia_color=0;

        if ((cuadrante->botLeft.get_x()==cuadrante->topRight.get_x()) and
         (cuadrante->botLeft.get_y()==cuadrante->topRight.get_y() )) { 
            
            r=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][0];
            g=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][1];
            b=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][2];       

            if(num_cuadrante==1){
                Rgb* rgb1= new Rgb(r,g,b);
                root->child_topL_rgb=rgb1;
                cout<<"topL: "<<"R: "<<root->child_topL_rgb->get_r()<<endl;

            }else if(num_cuadrante==2){
                Rgb* rgb2= new Rgb(r,g,b);
                root->child_topR_rgb=rgb2;
                cout<<"topR: "<<"R: "<<root->child_topR_rgb->get_r()<<endl;

            }else if(num_cuadrante==3){

                Rgb* rgb3= new Rgb(r,g,b);
                root->child_botL_rgb=rgb3;
                cout<<"botL: "<<"R: "<<root->child_botL_rgb->get_r()<<endl;
            }else{
                Rgb* rgb4= new Rgb(r,g,b);
                root->child_botR_rgb=rgb4;
                cout<<"botR: "<<"R: "<<root->child_botR_rgb->get_r()<<endl;
            }

            return; 
        }





        r=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][0];
        g=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][1];
        b=matrix[cuadrante->botLeft.get_y()][cuadrante->botLeft.get_x()][2];

        

        for(int i=cuadrante->botLeft.get_y();i<=cuadrante->topRight.get_y();i++){
            for(int j=cuadrante->botLeft.get_x();j<=cuadrante->topRight.get_x();j++){
                if(cuadrante->topRight.get_x()!=j){

                    if((matrix[i][j][0]!= matrix[i][j+1][0]) or (matrix[i][j][1]!= matrix[i][j+1][1]) or (matrix[i][j][2]!= matrix[i][j+1][2])){
                        
                        Quad *quad_inter=new Quad( Point(cuadrante->botLeft.get_x(),cuadrante->botLeft.get_y()) 
                        ,Point(cuadrante->topRight.get_x() , cuadrante->topRight.get_y()));          
                        diferencia_color=1;

                
                        if(num_cuadrante==1){
                            root->child_topL=aux;
                        }else if(num_cuadrante==2){
                            root->child_topR=aux;
                        }else if(num_cuadrante==3){
                            root->child_botL=aux;
                        }else{
                            root->child_botR=aux;    
                        }
                        quad_inter->buscar_cuadra();
                    }
                }
            }
        }




        if(num_cuadrante==1){
            if(diferencia_color ==0){
                Rgb* rgb1= new Rgb(r,g,b);
                root->child_topL_rgb=rgb1;
                cout<<"topL: "<<"R: "<<root->child_topL_rgb->get_r()<<endl;
            }
    
        }else if(num_cuadrante==2){
            if(diferencia_color ==0){
                Rgb* rgb2= new Rgb(r,g,b);
                root->child_topR_rgb=rgb2;
                cout<<"topR: "<<"R: "<<root->child_topR_rgb->get_r()<<endl;
            }
        }else if(num_cuadrante==3){
            if(diferencia_color ==0){
                Rgb* rgb3= new Rgb(r,g,b);
                root->child_botL_rgb=rgb3;
                cout<<"botL: "<<"R: "<<root->child_botL_rgb->get_r()<<endl;
            }
        }else{
        
            if(diferencia_color ==0){
                Rgb* rgb4= new Rgb(r,g,b);
                root->child_botR_rgb=rgb4;
                cout<<"botR: "<<"R: "<<root->child_botR_rgb->get_r()<<endl;
            }
        }

        return;
    
    }

    void Quad::print(Node *n){
        if(n!=NULL){
            if(n->child_topL!=NULL){
                print(n->child_topL);
            }if(n->child_topL==NULL){
                cout<<"R: "<<n->child_topL_rgb->get_r()<<" G: "<<n->child_topL_rgb->get_g()<<" B: "<<n->child_topL_rgb->get_b()<<endl;
            }
            if(n->child_topR!=NULL){
                print(n->child_topR);
            }if(n->child_topR==NULL){
                cout<<"R: "<<n->child_topR_rgb->get_r()<<" G: "<<n->child_topR_rgb->get_g()<<" B: "<<n->child_topR_rgb->get_b()<<endl;
            }
            if(n->child_botL!=NULL){
                print(n->child_botL);
            }if(n->child_botL==NULL){
                cout<<"R: "<<n->child_botL_rgb->get_r()<<" G: "<<n->child_botL_rgb->get_g()<<" B: "<<n->child_botL_rgb->get_b()<<endl;
            }

            if(n->child_botR!=NULL){
                print(n->child_botR);
            }if(n->child_botR==NULL){
                 cout<<"R: "<<n->child_botR_rgb->get_r()<<" G: "<<n->child_botR_rgb->get_g()<<" B: "<<n->child_botR_rgb->get_b()<<endl;       
            }
            
        }
    
    }
    void Quad::print(){
        print(this->nn);
    }

    void Quad::buscar_cuadra(){
        this->transformar_bidimensional();      
        nn=this->dividir();
        this->buscarcuadrante(this->get_botL(),3,nn); 
        this->buscarcuadrante(this->get_topR(),2,nn);
        this->buscarcuadrante(this->get_topL(),1,nn);
        this->buscarcuadrante(this->get_botR(),4,nn);

    }

    void Quad::transformar_bidimensional(){    
        int **imagenn=cargar_una_imagen();
        int cont=0;
        for(int i=7;i>=0;i--){
            for(int j=0;j<8;j++){
                matrix[i][j][0]=imagenn[cont][0];
                matrix[i][j][1]=imagenn[cont][1];
                matrix[i][j][2]=imagenn[cont][2];
                cont++;
            }
        }
    
    }

    int **Quad::cargar_una_imagen(){
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
            imagen[cont][0] = r;
            imagen[cont][1] = g;
            imagen[cont][2] = b;
            cont++;
        }

        return imagen;
    }