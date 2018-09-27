template<class K,class D>
Node<K,D>::Node(const K & k,const D & d){
    key=k;
    data=d;
    hgt=0;
    p_children[1]=NULL;
    p_children[0]=NULL;
}
template<class K,class D>
Node<K,D>::~Node(){

}

template<class K,class D>
avl<K,D>::avl(){
    os.open("grap.dot");
    root=NULL;
}


template<class K,class D>
avl<K,D>::~avl(){
    destructor(root);
}



template<class K,class D>
bool avl<K,D>::find(K _key){
    Node<K,D> **aux;
    if(find(_key,aux)==true){
        cout<<"elemento "<<_key<<" a sido encontrado"<<endl;
    }else{
        cout<<_key<<" Elemento no encontrado";
    }

}

template<class K,class D>
bool avl<K,D>::find(K x,Node<K,D> **&tmp){
    tmp=&root;
    while(*tmp){
       
            if((*tmp)->key==x){
                return true;
            } 
            tmp=&(*tmp)->p_children[((*tmp)->key<x)];
       }
    return false;
}

template<class K,class D>
bool avl<K,D>::insert (Node<K,D> **n,K x){
 if(*n==NULL)//Si los nodos vacío, con la información de este nodo X 
    { 
        *n=new Node<K,D>(x,1); 
        (*n)->key=x; 
        return true; 
    }

    if((*n)->key == x){
        return false;
    }

    bool child = (*n)->key < x; 
    if(insert(&(*n)->p_children[child],x))
    {
        
    
        balance(n,child);
        

    }



}


template<class K,class D> 
void avl<K,D>::insert(K x) 
{ 
    insert(&root,x); 
} 




template<class K,class D>
bool  avl<K,D>::balance(Node<K,D> **n,bool child)
{
    Node<K,D> * son  = (*n)->p_children[child];//doble puntero
    int b = altura((*n)->p_children[0])-altura((*n)->p_children[1]);
    int c= altura(son->p_children[0])-altura(son->p_children[1]);
        
    if (b == -2 or b==2)
    {
        if (b*c<=0){
            rotar(&(*n)->p_children[child],!child);
        }

        rotar(n,child);

        return false;
    }

    
    return true;
}







template<class K,class D>
void avl<K,D>::print(Node<K,D> * n)
{
    if(n)
    {
        cout << n->key <<"(";
        print(n->p_children [0]);
        cout<<" , ";
        print(n->p_children [1]);
        cout<<")";
    }
}

template<class K,class D>
void avl<K,D>::print()
{
    print(root);
}




template<class K,class D>
void avl<K,D>::printgraf(Node<K,D> * n)
{
    if(n)
    {
        if(n->p_children[0]!=NULL){
            cout<<n->key;
            cout<<"--";
            cout<<n->p_children[0]->key<<endl;
            printgraf(n->p_children[0]);
        }


        if(n->p_children[1]!=NULL){
            cout<<n->key;
            cout<<"--";
            cout<<n->p_children[1]->key<<endl;
            printgraf(n->p_children[1]);
        }
    }
}

template<class K,class D>
void avl<K,D>::printgraf()
{   
    cout<<"graph {"<<endl;
    cout<<root->key<<endl;
    printgraf(root);
    cout<<"}"<<endl;
}

template<class K,class D>
void avl<K,D>::rotar(Node<K,D>** n, bool side){
    Node<K,D>* k1; 
    k1=(*n)->p_children[side]; 
    (*n)->p_children[side]=k1->p_children[!side]; 
    k1->p_children[!side]=*n; 
    *n=k1;
    (*n)->hgt=max(altura((*n)->p_children[side]),altura((*n)->p_children[side]))+1; 
    k1->hgt=max(altura(k1->p_children[side]),altura((k1)->p_children[side]))+1;
}


template<class K,class D>
int avl<K,D>::altura(Node<K,D> * n){
    int Altura_dere=0;
    int Altura_izq=0;
    if(n==NULL){
        return 0;
    }else{
        Altura_dere=altura(n->p_children[1]);
        Altura_izq=altura(n->p_children[0]);
        return max(Altura_dere,Altura_izq)+1;
    }
}

template<class K,class D>
int avl<K,D>::max(int a,int b){
    if(a<b){
        return b;
    }else{
        return a;
    }
}
template<class K,class D>
int avl<K,D>::altura(){
    Node<K,D> *tmp=root;
    return altura(tmp);

}

template<class K,class D>
Node<K,D>* avl<K,D>::Min(Node<K,D> **n)
{
    if(*n == NULL)
        return NULL;
    else if((*n)->p_children[0] == NULL)
        return *n;
    else
        return Min(&(*n)->p_children[0]);
}



template<class K,class D>
void avl<K,D>::remove(Node<K,D>** n,K x){
  /*  Node<K,D>* temp;
    if(*n == NULL){
        return ;
    }  
    bool child = (*n)->key < x; 
    if(remove((n*)->p_children[0],x)){


    }
*/
}



template<class K,class D>
void avl<K,D>::remove(K x)
{
    Delete(&root,x);
}






template<class K,class D>
bool avl<K,D>::Delete(Node<K,D> **n, K k)
{
    Node<K,D>** temp;
    if (*n == NULL){ 
        return false;
    }
    if((*n)->key == k){
        if((*n)->p_children[0] && (*n)->p_children[1])
        {
            Node<K,D> *aux;
            //cout<<"xd";
            aux =Min(&(*n)->p_children[1]);
            
            (*n)->key = aux->key;
            Delete(&(*n)->p_children[1],(*n)->key);
            
        }else{
            temp = n;
            if((*n)->p_children[0] == NULL){
                *n = (*n)->p_children[1];
            }
            else if((*n)->p_children[1]== NULL){
                *n = (*n)->p_children[0];
            }
            delete *temp;
        }
        if(*n==NULL){
            return false;
        }
    }
    bool child = (*n)->key < k; 
    if(Delete(&(*n)->p_children[child],k)){
        balance(n,child);
    }
}









template<class K,class D>
void avl<K,D>::print_inverse_leve(){
    int a=altura();
    Node<K,D> **aux;
    aux=&root;
    Node<K,D> *padre;
    Node<K,D> *auxx;
    Node<K,D> *tmp;
    tmp=*aux;
    auxx=tmp->p_children[1];
    while(auxx->p_children[0]!=NULL){
        padre=auxx;
        auxx=auxx->p_children[0];
    }

    for(int i=1;i<=a;i++){ 
        print_inverse_leve(root,i);
    }
    
}

template<class K,class D>
void avl<K,D>::print_inverse_leve(Node<K,D> *n,int level){
    if(n==NULL){
        return;
    }
    if(level==1){
        cout<<n->key<<"-";
    }else if(level>1){
        print_inverse_leve(n->p_children[1],level-1);
        print_inverse_leve(n->p_children[0],level-1);
    }   
}


template<class K,class D>
void avl<K,D>::destructor(Node<K,D> *n){
    if(n)
    {
    destructor(n->p_children[0]);
    destructor(n->p_children[1]);
        delete(n);
    }   
}


template<class K,class D>
void avl<K,D>::print_sinrecu(Node<K,D> *n){
    
    if(n==NULL){
        return;
    }
   // cout<<"asfr"<<endl;
    while(n!=NULL){
        if(n->p_children[0]==NULL){
            cout<<n->key<<endl;
            n=n->p_children[1];
        }else{
            Node<K,D>*aux;
            aux=n->p_children[0];
        
        if(aux->p_children[1]=NULL){
            aux->p_children[1]=n;
            n=n->p_children[0];
        }else{
            aux->p_children[1]=NULL;
            cout<<n->key<<endl;
            n=n->p_children[1];
        }
        }
    }

}




template<class K,class D>
void avl<K,D>::print_sinrecu(){
    Node<K,D> *tmp=root;
    print_sinrecu(tmp);
}


template<class K, class D>
void avl<K,D>::printARBOL(){
    os<<"graph {"<<endl;
    os<<root->key<<endl;
    printARBOL(root);
    os<<"}";
    system("dot.lnk -Tpng -o < grap.dot > out2.png");
}




template<class K,class D>
void avl<K,D>::printARBOL(Node<K,D> *n){
    if(n!=NULL){
        if(n->p_children[0]!=NULL){
            os<<n->key;
            os<<"--";
            os<<n->p_children[0]->key<<endl;
            printARBOL(n->p_children[0]);
        }
        if(n->p_children[1]!=NULL){
            os<<n->key;
            os<<"--";
            os<<n->p_children[1]->key<<endl;
            printARBOL(n->p_children[1]);
        }
    }
}



