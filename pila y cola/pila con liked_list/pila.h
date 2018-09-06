#include <iostream>
#include "linked_list.h"
using namespace std;


template <class T>

class Pila: public linked_list<T>{

	private:
		node<T> * temp;
	public:
		Pila();
		void insertarpila(const T & d);
		void remove_pila();
		void print_pila();
		
		
};
#include "pila.inl"
//#endif


