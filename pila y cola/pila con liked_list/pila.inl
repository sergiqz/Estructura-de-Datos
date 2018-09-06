	template<class T>
	Pila<T>::Pila(){

	}
	template<class T>
	void Pila<T>::insertarpila(const T & d){
		this->insert_back(d);
	}	
	template<class T>
	void Pila<T>::remove_pila(){
		this->remove_back();
	}
	template<class T>
	void Pila<T>::print_pila(){
		this->print();
	}
		
		


