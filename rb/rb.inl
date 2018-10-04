template<class K,class D>
node<K,D>::node(const K & _key, const D & _data){
    key=_key;
    data=_data;
    p_child[0]=NULL;
    p_child[1]=NULL;
    color=RED;
    
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

template<class K, class D>
node<K,D>* rb<K,D>::insert(const K & key,const D & data, node<K,D> ** n, node<K,D> ** p){
    if((*n)==NULL){
        *n = new node<K,D>(key,data);
        return *n;
    }
    if((*n)->key==key){
        return NULL;
    }
    bool child = ((*n)->key < key);
    node<K,D> *aux = insert(key,data,&(*n)->p_child[child],n); 
        if(!aux){
            return (*n);
        }
        if(!p){
            return NULL;
        }
       
        
        convertirRedblack(p,n,child,aux);
    
}




template<class K,class D>
node<K,D>* rb<K,D>::Min(node<K,D> **n)
{
    if(*n == NULL)
        return NULL;
    else if((*n)->p_child[0] == NULL)
        return *n;
    else
        return Min(&(*n)->p_child[0]);
}









template<class K, class D>
node<K,D>* rb<K,D>::remove(const K & key,const D & data, node<K,D> ** n, node<K,D> ** p){
    node<K,D>* temp;
    if(*n==NULL){
        return NULL;
    }
     if((*n)->key == key){
        if((*n)->p_child[0] && (*n)->p_child[1])
        {
            
            temp =Min(&(*n)->p_child[1]);
            (*n)->key = temp->key;
            remove((*n)->key,(*n)->data,&(*n)->p_child[1],NULL);
            
        }else{
            temp = *n;
            if((*n)->p_child[0] == NULL){
                *n = (*n)->p_child[1];
            }
            else if((*n)->p_child[1]== NULL){
                *n = (*n)->p_child[0];
            }
            delete temp;
        }
        if(*n==NULL){
            return NULL;
        }
    }


    bool child = ((*n)->key < key);
    node<K,D> *aux = remove(key,data,&(*n)->p_child[child],n); 

        if(!aux){
            return (*n);
        }
        if(!p){
            return NULL;
        }
        convertirRedblack(p,n,child,aux);
    
}



template<class K,class D>
bool rb<K,D>::remove(const K & key,const D & data){
    remove(key,data,&root,NULL);
    return true;
}


















template<class K,class D>
void rb<K,D>::rotar(node<K,D>** n, bool side){
    node<K,D>* k1; 
    k1=(*n)->p_child[side]; 
    (*n)->p_child[side]=k1->p_child[!side]; 
    k1->p_child[!side]=*n; 
    *n=k1;
    (*n)->hgt=max(altura((*n)->p_child[side]),altura((*n)->p_child[side]))+1; 
    k1->hgt=max(altura(k1->p_child[side]),altura((k1)->p_child[side]))+1;
}


template<class K,class D>
bool  rb<K,D>::balance(node<K,D> **n,bool child)
{
    node<K,D> * son  = (*n)->p_child[child];//doble puntero
    int b = altura((*n)->p_child[0])-altura((*n)->p_child[1]);
    int c= altura(son->p_child[0])-altura(son->p_child[1]);
        
    if (b == -2 or b==2)
    {
        if (b*c<=0){
            rotar(&(*n)->p_child[child],!child);
        }

        rotar(n,child);

        return false;
    }

    
    return true;
}



template<class K,class D>
int rb<K,D>::altura(node<K,D> * n){
    int Altura_dere=0;
    int Altura_izq=0;
    if(n==NULL){
        return 0;
    }else{
        Altura_dere=altura(n->p_child[1]);
        Altura_izq=altura(n->p_child[0]);
        return max(Altura_dere,Altura_izq)+1;
    }

}



template<class K,class D>
bool rb<K,D>::insert(const K & key,const D & data){
    insert(key,data,&root,NULL);
    return true;
}


template<class K,class D>
int rb<K,D>::max(int a,int b){
    if(a<b){
        return b;
    }else{
        return a;
    }
}



template<class K,class D>
void rb<K,D>::print(node<K,D> * n)
{
    if(n)
    {
        cout << n->key <<"(";
        print(n->p_child [0]);
        cout<<" , ";
        print(n->p_child [1]);
        cout<<")";
    }
}

template<class K,class D>
void rb<K,D>::print()
{
    print(root);
}



template<class K,class D>
void rb<K,D>::convertirRedblack(node<K,D> **n,node<K,D> **p,bool child,node<K,D> *aux) {
    

    if((getColor(aux)==RED) and (getColor(*p)==RED)){
        bool parent = ((*n)->p_child[1] == (*p));
        node<K,D> *tio = (*n)->p_child[!parent];
        if(getColor(tio)==RED){
            
            (*p)->color = BLACK;
            tio->color = BLACK;
            (*n)->color = RED;
            root->color = BLACK;
            return;
        }
        if(getColor(tio)==BLACK){
            if(child!=parent){
                balance(p,child);
                balance(n,parent);
                //cout<<(*p)->key<<endl;
                //cout<<(*p)->p_child[0]->key<<endl;
                
                (*n)->color = BLACK;
                (*n)->p_child[0]->color = RED;
                (*n)->p_child[1]->color = RED;

                root->color = BLACK;
                cout<<root->key<<endl;
                
            }
            else{
                balance(n,parent);
                (*n)->color = BLACK;
                (*n)->p_child[!parent]->color = RED;
                root->color = BLACK;
            }
        }  
    }
    return;     
}



template<class K,class D>
bool rb<K,D>::turnSide(node<K,D> **n, bool side)
{
    node<K,D> *mid = (*n)->p_child[side];
    (*n)->p_child[side] = mid->p_child[!side];
    mid->p_child[!mid] = (*n);
    (*n) = mid;
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





template<class K, class D>
void rb<K,D>::printCOLOR(ofstream & es,node<K,D> *ptr){
  if (ptr == NULL)
    return;
  if(ptr->color == 0){
    es<< ptr->key << "[style=filled, fillcolor=black, fontcolor=white]"<< endl;
  }
  else es<< ptr->key << "[style=filled, fillcolor=red]"<< endl;
  printCOLOR(es,ptr->p_child[0]);
  printCOLOR(es,ptr->p_child[1]);
}

template<class K, class D>
void rb<K,D>::printARBOL(){
    cout<<"digraph mentions {"<<endl;
    printARBOL(root);
    printCOLOR(root);
    cout<<"}";
}

template<class K, class D>
void rb<K,D>::printARBOL(ofstream & es,node<K,D> *n){
    if(n!=NULL){
        if(n->p_child[0]!=NULL){
            es<<n->key;
            es<<" -> ";
            es<<n->p_child[0]->key<<endl;
            printARBOL(es,n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            es<<n->key;
            es<<" -> ";
            es<<n->p_child[1]->key<<endl;
            printARBOL(es,n->p_child[1]);
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




template<class K, class D>
void rb<K,D>::dibujararbol(int num){
    string num_arch = to_string(num);
    string ext1 = ".dot";
    string num_xt1=""+ num_arch +""+ ext1 +"";
    ofstream es(num_xt1);
    ////////
    string s = to_string(num);
    string pt1="dot.lnk -Tpng  < ";
    string pt2=" > ";
    string pt3=".png";
    string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
    const char *buffer = rt.c_str();
    ////////
    es<<"digraph mentions {"<<endl;
    printARBOL(es,root);
    printCOLOR(es,root);
    es<<"}"<<endl;
    es.close();
    system(buffer);
}