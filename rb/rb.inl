template<class K,class D>
node<K,D>::node(const K & _key, const D & _data){
	key=_key;
	data=_data;
    //p_child[2]=NULL;
	p_child[0]=NULL;
    p_child[1]=NULL;
	color=RED;
	parent=NULL;
}

template<class K,class D>
node<K,D>::~node(){
}

template<class K,class D>
rb<K,D>::rb(){
	root=NULL;
}
template<class K,class D>
rb<K,D>::~rb(){
	
}

template<class K,class D>
bool rb<K,D>::insertBST(K x,node<K,D> **&tmp,node<K,D> **&padre) {
    tmp=&root;
    padre=&root;

    while(*tmp){
       
           /* if((*tmp)->key==x){
                return true;
            } 
            else if((*tmp)->key > x) {
                padre=*tmp;
                //cout<<padre->key<<endl;
                tmp=&(*tmp)->p_child[0];
                //cout<<padre->key<<endl;
                
                
            }else if ((*tmp)->key < x) {
                padre=*tmp;
               // auxxx=padre; 
                //(auxxx)->parent=padre;
                //cout<<padre->key<<endl;
                tmp=&(*tmp)->p_child[1];
               //(*tmp)->parent=(auxxx)->parent;

               // cout<<padre->key<<endl;
                
            }*/
            


            if((*tmp)->key==x){
                return true;
            }
            padre=tmp;
            tmp=&(*tmp)->p_child[((*tmp)->key<x)];
       }
    return false;
}


template<class K,class D>
bool rb<K,D>::insertValor(K  _key,D _data){
    node<K,D>**t;
    node<K,D>**papa;
     

    if(insertBST(_key,t,papa)==false){
        
        *t=new node<K,D>(_key,_data);
        cout<<(*t)->key<<endl;
        cout<<(*papa)->key<<endl;
        (*t)->parent=*papa;
        convertirRedblack(t);
        return true; 
    }  
    
}

template<class K,class D>
void rb<K,D>::convertirRedblack(node<K,D> **&ptr) {
    node<K,D> *parent = NULL;
    node<K,D> *abuelo = NULL;
    
    while (*ptr != root and getColor(*ptr) == RED and getColor((*ptr)->parent) == RED){
        cout<<(*ptr)->key<<"PTR"<<endl;
        parent = (*ptr)->parent;
        cout<<parent->key<<"parent"<<endl;
        abuelo = parent->parent;
        cout<<abuelo->key<<"abuelo"<<endl;
        if (parent == abuelo->p_child[0]) {

            node<K,D> *tio = abuelo->p_child[1];
            if (getColor(tio) == RED) {
                setColor(tio, BLACK);
                setColor(parent, BLACK);
                setColor(abuelo, RED);
                *ptr = abuelo;
            } else {
                if (*ptr == parent->p_child[1]) {
                    rotacionizq(parent);
                    *ptr = parent;
                    parent = (*ptr)->parent;
                }
                rotacionder(abuelo);
                swap(parent->color, abuelo->color);
                *ptr = parent;
            }
        } else {
            cout<<"aaaaa"<<endl;
            node<K,D> *tio = abuelo->p_child[0];
            if (getColor(tio) == RED) {
                setColor(tio, BLACK);
                setColor(parent, BLACK);
                setColor(abuelo, RED);
                cout<<(*ptr)->key<<endl;
                *ptr = abuelo;

                
            } else {
                if (*ptr == parent->p_child[0]) {
                    rotacionder(parent);
                    *ptr = parent;
                    parent = (*ptr)->parent;
                }
                rotacionizq(abuelo);
                swap(parent->color, abuelo->color);
                *ptr = parent;
            }
        }
    }
    setColor(root, BLACK);    
}


template<class K,class D>
color_t rb<K,D>::getColor(node<K,D> *&n) {
    if (n == NULL)
        return BLACK;

    return n->color;
}

template<class K,class D>
void rb<K,D>::setColor(node<K,D> *&n, color_t color) {
    if (n == NULL)
        return;

    n->color = color;
}

template<class K,class D>
void rb<K,D>::preorderBST(node<K,D> *ptr) {
    if (ptr == NULL)
        return;

    cout << ptr->key << " " << ptr->color << endl;
    preorderBST(ptr->p_child[0]);
    preorderBST(ptr->p_child[1]);
}


template<class K,class D>
void rb<K,D>::preorder() {
    preorderBST(root);
}


template<class K,class D>
void rb<K,D>::rotacionizq(node<K,D>*& ptr){
    node<K,D> *right_child = ptr->p_child[1];
    ptr->p_child[1] = right_child->p_child[0];
    if (ptr->p_child[1] != NULL){
        ptr->p_child[1]->parent = ptr;
    }

    right_child->parent = ptr->parent;

    if (ptr->parent == NULL){
        root = right_child;
    }
    else if (ptr == ptr->parent->p_child[0]){
        ptr->parent->p_child[0] = right_child;
    }
    else{
        ptr->parent->p_child[1] = right_child;
    }

    right_child->p_child[0] = ptr;
    ptr->parent = right_child; 
}
template<class K,class D>
void rb<K,D>::rotacionder(node<K,D>*& ptr){
    node<K,D> *left_child = ptr->p_child[0];
    ptr->p_child[0] = left_child->p_child[1];

    if (ptr->p_child[0] != NULL)
        ptr->p_child[0]->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = left_child;
    else if (ptr == ptr->parent->p_child[0])
        ptr->parent->p_child[0] = left_child;
    else
        ptr->parent->p_child[1] = left_child;

    left_child->p_child[1] = ptr;
    ptr->parent = left_child;


}


template<class K, class D>
void rb<K,D>::printCOLOR(node<K,D> *ptr){
  if (ptr == NULL)
    return;
  if(ptr->color == 0){
    cout << ptr->key << "[style=filled, fillcolor=black, fontcolor=white]"<< endl;
  }
  else cout << ptr->key << "[style=filled, fillcolor=red]"<< endl;
  printCOLOR(ptr->p_child[0]);
  printCOLOR(ptr->p_child[1]);
}

template<class K, class D>
void rb<K,D>::printARBOL(){
    cout<<"digraph mentions {"<<endl;
    printARBOL(root);
    printCOLOR(root);
    cout<<"}";
}

template<class K, class D>
void rb<K,D>::printARBOL(node<K,D> *n){
    if(n!=NULL){
        if(n->p_child[0]!=NULL){
            cout<<n->key;
            cout<<" -> ";
            cout<<n->p_child[0]->key<<endl;
            printARBOL(n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            cout<<n->key;
            cout<<" -> ";
            cout<<n->p_child[1]->key<<endl;
            printARBOL(n->p_child[1]);
        }
    }
}
template<class K, class D>
bool rb<K,D>::find(node<K,D> *n,int a){
    if(n==NULL){
        return false;
    }
    else if(n->key==a){
        return true;
    }
    else if(a<n->key){
        return find(n ->p_child[0],a);
    }
    else{
        return find(n->p_child[1],a);
    }
}


template<class K, class D>
D& rb<K,D>::operator[](const K &_key){
    node<K,D> *aux=root;
    D d;
    if(find(aux,_key)==false){
        node<K,D>*t=new node<K,D>(_key,d);
        root=insertBST(root,t);  
        fixInsertRBTree(t);
        return t->data;
    }
    else{
        return aux->data;
    }    
}


template<class K, class D>
node<K,D>* rb<K,D>::sucesor(node<K,D> * n){
    node<K,D>* tmp = n->p_child[1];    
    if(tmp==NULL){
        cout<<n->key<<endl;
        return n;
    }
    while (tmp->p_child[0]!=NULL){
        tmp = tmp->p_child[0];     
    }

    cout<<tmp->key<<endl;
    return tmp;
}

template<class K, class D>
void rb<K,D>::sucesorcito(){
    sucesor(root);
}