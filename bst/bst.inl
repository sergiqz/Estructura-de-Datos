template<class K,class D>
Node<K,D>::Node(const K & k,const D & d){
	key=k;
	data=d;
	p_children[1]=NULL;
    p_children[0]=NULL;
}
template<class K,class D>
Node<K,D>::~Node(){

}

template<class K,class D>
BST<K,D>::BST(){
	root=NULL;
}


template<class K,class D>
BST<K,D>::~BST(){
    destructor(root);
}



template<class K,class D>
bool BST<K,D>::find(K _key){
    Node<K,D> **aux;
    if(find(_key,aux)==true){
        cout<<"elemento "<<_key<<" a sido encontrado"<<endl;
    }else{
        cout<<_key<<" Elemento no encontrado";
    }

}

template<class K,class D>
bool BST<K,D>::find(K x,Node<K,D> **&tmp){
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
bool BST<K,D>::insert(K nombre,D datos){
    Node<K,D> **aux;
	if(find(nombre,aux)==false){
		(*aux)=new Node<K,D>(nombre,datos);
        return true; 
	}
    return false;
}

template<class K,class D>
void BST<K,D>::print(Node<K,D> * n)
{
    if(n)
    {
        cout << n->key <<"(";
        print(n->p_children[0]);
        cout<<" , ";
        print(n->p_children[1]);
        cout<<")";
    }
}

template<class K,class D>
void BST<K,D>::print()
{
    print(root);
}




template<class K,class D>
void BST<K,D>::printgraf(Node<K,D> * n)
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
void BST<K,D>::printgraf()
{   
    cout<<"graph {"<<endl;
    cout<<root->key<<endl;
    printgraf(root);
    cout<<"}"<<endl;
}






























template<class K,class D>
int BST<K,D>::altura(Node<K,D> * n){
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
int BST<K,D>::max(int a,int b){
    if(a<b){
        return b;
    }else{
        return a;
    }
}
template<class K,class D>
int BST<K,D>::altura(){
    Node<K,D> *tmp=root;
    return altura(tmp);

}

template<class K,class D>
bool BST<K,D>::remove(K _key){
    Node<K,D> **aux;
    aux=&root;
    Node<K,D> *tmp;
    Node<K,D> *tmp2;


    if(find(_key,aux)==true){
        tmp=*aux;
        if(tmp->p_children[0]==NULL and tmp->p_children[1]==NULL){
            *aux=NULL;
            delete tmp;
        }
        else if(tmp->p_children[0]!=NULL and tmp->p_children[1]==NULL){
            *aux=(*aux)->p_children[0];
            tmp->p_children[0]=NULL;
            delete tmp;
        }
        else if(tmp->p_children[0]==NULL and tmp->p_children[1]!=NULL){
            *aux=(*aux)->p_children[1];
            tmp->p_children[1]=NULL;
            delete tmp;
        }
        else{
            Node<K,D> *padre;
            Node<K,D> *auxx;
            tmp=*aux;
            auxx=tmp->p_children[0];
            padre=root;
            if(auxx -> p_children[1]==NULL){
                tmp->key=auxx->key;
                tmp->p_children[0]=auxx->p_children[0];
                delete auxx;
            }else{
                while((auxx->p_children[1]!=NULL)){
                    padre=auxx;
                    auxx=auxx->p_children[1];
                }

                tmp->key=auxx->key;
                padre->p_children[1]=NULL;
                
            delete auxx;
            }
        }

    }
}
template<class K,class D>
void BST<K,D>::print_inverse_leve(){
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

    for(int i=1;i<=a;a--){
        print_inverse_leve(root,a);
    }
    
}

template<class K,class D>
void BST<K,D>::print_inverse_leve(Node<K,D> *n,int level){
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
void BST<K,D>::destructor(Node<K,D> *n){
    if(n)
    {
    destructor(n->p_children[0]);
    destructor(n->p_children[1]);
        delete(n);
    }   
}