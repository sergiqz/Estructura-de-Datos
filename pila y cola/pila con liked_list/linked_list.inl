		template<class T>
		linked_list<T>::linked_list(){
			p_head=NULL;
			p_last=NULL;
		}


		template<class T>
		void linked_list<T>::insert_front(const T & d){
			
				aux=new node<T>(d);
				aux->dato=d;//guarda num
				if(p_head==NULL){//lista vacia
					p_head=aux;
					aux->p_next=NULL;
				}else{
					aux->p_next=p_head;
					p_head=aux;
				}
			

		}




		template<class T>
		void linked_list<T>:: insert_back(const T & d){
	
				
				aux=new node<T>(d);//asignar memoria
				aux->dato=d;//guarda num
				if(p_head==NULL){
					p_head = aux;

				}else{
					p_last->p_next=aux;
				}
				p_last=aux;
			
		}
		template<class T>
		void linked_list<T>::remove_front(){
			
			aux=new node<T>();
			if(p_head==p_last){
				p_head=NULL;
				p_last=NULL;
			}else{
			aux=p_head; // alamaceno el primer nodo en aux
			p_head=p_head->p_next; // cambio que la cabeza apunte al siguiente nodo (desaparece si lo compilo pero no se elimino)
			delete aux;// elimino el primer nodo ya q antes iguale aux= con el primer nodo que queria eliminar..
			}
		}

		template<class T>
		void linked_list<T>::remove_back(){
			aux=new node<T>();
			aux=p_head;
			if(aux->p_next!=NULL){// si solo ay un elemento el while no funciona, asi q le puse un if para q si ay 2 a mas elemente ejecute
				while((aux->p_next)->p_next!=NULL){// con este while llego al penultimo elemento
					aux=aux->p_next;
				}
				delete(aux->p_next);// despues de llegar al penultimo elemento apunto al siguiente q serio el ultimo y lo borro
				aux->p_next=NULL;
			}else{
				p_head= NULL; // si ay un elemento q sea eliminado el primero
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





	

