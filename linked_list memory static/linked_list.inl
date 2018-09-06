		template<class T>
		linked_list<T>::linked_list(){
			sn=new node<T>[6];
			p_head=NULL;
			p_last=NULL;
			idxfree=0;
			free=NULL;
			freeme=1;
		}

		template<class T>
		linked_list<T>::linked_list(const linked_list<T>& copy){

			const node<T> *Headcopy = copy.p_head;
	    	node<T> *tmp = NULL;

	    	if(Headcopy != NULL){
	        	p_head = new node<T>(Headcopy -> dato);
	        	tmp = p_head;

	        	Headcopy = Headcopy -> p_next;
	        }
	        while (Headcopy != NULL) {
	        	node<T> *newnode = new node<T>(Headcopy -> dato);
	        	tmp -> p_next = newnode;
	        	tmp = tmp -> p_next;
	        	Headcopy = Headcopy -> p_next;
	    	}
	    	

    	}



		template<class T>
		linked_list<T>& linked_list<T>:: operator =(const linked_list<T>& copia) 
		{	
	    	linked_list<T> copy(copia);
	    	std::swap(copy.p_head, p_head);
	    	return *this;
		}
		template<class T>
		void linked_list<T>::insert_front(const T & d){
			
				if(p_head==NULL){//lista vacia
					aux=&sn[idxfree];
					aux->dato=d;
					p_head=aux;
					p_last = aux;
					aux->p_next=NULL;
					idxfree++;
					
				}else if(free!=NULL){
					free->dato=d;
					free->p_next=p_head;
					p_head=free;


				}else{
					aux=&sn[idxfree];
					aux->dato=d;
					aux->p_next=p_head;
					p_head=aux;
					idxfree++;
				}
			

		}




		template<class T>
		void linked_list<T>:: insert_back(const T & d){
	
				
				if(p_head==NULL){
					aux=&sn[idxfree];
					aux->dato=d;
					p_head = aux;
					p_last = aux;
					p_head->p_next=NULL;
					//free=&sn[freeme++];
					//cout<<idxfree<<endl;
					p_last=aux;
					idxfree++;


				}else if(free!=NULL){
					free->dato=d;
					p_last->p_next=free;
					p_last=free;



				}else{
					aux=&sn[idxfree];
					aux->dato=d;
					p_last->p_next=aux;
					//cout<<freeme<<endl;
					p_last=aux;
					idxfree++;
				}
				
				p_last->p_next=NULL;

				cout<<idxfree<<endl;
			
		}
		template<class T>
		void linked_list<T>::remove_front(){
			
			if(p_head==p_last){
				p_head=NULL;
				p_last=NULL;
			}else{
			free=p_head; 
			
			p_head=p_head->p_next; 
			free->p_next=free;
			cout<<"dato eliminado: "<<freeme<<endl;
			}
		}

		template<class T>
		void linked_list<T>::remove_back(){
			aux=p_head;
			if(aux->p_next!=NULL){// si solo ay un elemento el while no funciona, asi q le puse un if para q si ay 2 a mas elemente ejecute
				while((aux->p_next)->p_next!=NULL){// con este while llego al penultimo elemento
					aux=aux->p_next;
				}
				free=aux->p_next;// despues de llegar al penultimo elemento apunto al siguiente q serio el ultimo y lo borro
				aux->p_next=NULL;
			}else{
				free= NULL; // si ay un elemento q sea eliminado el primero
			}




		}
		template<class T>
		void linked_list<T>::reverse(){
			node<T> *next = NULL;//    newfin=p   auxx=c n=next
			node<T>*auxx=p_head;//		p  c  
			node<T>*newfin= NULL;//		N  1->2->3->4->N
			while(auxx){//				p  c  n
				next=auxx->p_next;// 	N  1->2->3->4->N
				auxx->p_next=newfin;//  N<-1->2->3->4->N
				newfin=auxx;
				auxx=next;		//	N<-1 2->3->4->N
			}						//	   p n
			p_head=p_last;			//       c
		}

		template<class T>
		void linked_list<T>::print(){
			
			cout<<endl;
			cout<<"Datos dentro de la lista: "<<endl;
			aux=p_head;
			while(aux!=NULL){
				cout<<aux->dato<<" , ";
				aux=aux->p_next;
			}
		}

		template<class T>
		void linked_list<T>::remove(const T & d){
			aux=new node<T>(d);
			node<T> * tmp;
			node<T> *tmp2;
			tmp=p_head;
			while(aux->dato!=tmp->dato){
				if(tmp->p_next!=NULL){
					tmp2=tmp;
					tmp=tmp->p_next;
							
				}else{
					cout<<"no encontro"<<endl;
					delete aux;
					return;
				}

			}	
				tmp2->p_next=tmp->p_next;
				delete tmp;
		}





	

