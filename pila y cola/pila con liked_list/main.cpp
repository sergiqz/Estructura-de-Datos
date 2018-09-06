#include <iostream>
#include "pila.h"
using namespace std;


int main(){

	Pila<int> pila;
	pila.insertarpila(5);
	pila.insertarpila(7);
	pila.insertarpila(3);
	pila.remove_back();
	pila.print_pila();
/*
	linked_list<int> list;

	for(int i=0;i<10;i++){
		list.insert_back(i);
	}
	list.print();
	cout<<"--------------------------------------"<<endl;
	
	list.remove(2);
	list.print();

/*
	for(int i=0;i<98;i++){
		list.remove_back();
	}
	list.print();
*/
/*
	list.insert_back(5);
	list.insert_back(3);
	list.insert_back(2);
	list.print();
	list.remove_front();
	list.print();
*/
}