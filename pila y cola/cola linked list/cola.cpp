#include <iostream>
#include "linked_list.cpp"
using namespace std;



template <class T>

class cola: public linked_list<T>{

	private:
		node<T> * temp;
	public:
		cola(){

		}
		void insertarcola(const T & d){
			this->insert_back(d);
		}	
		void remove_cola(){
			this->remove_front();
		}
		void print_cola(){
			this->print();
		}
		
		
};


int main(){

	cola<int> cola;
	cola.insertarcola(5);
	cola.insertarcola(7);
	cola.insertarcola(3);
	cola.print_cola();

	cola.remove_cola();
	cola.print_cola();


/*	linked_list<int> list;

	for(int i=0;i<1000;i++){
		list.insert_back(i);
	}
	list.print();
	cout<<"--------------------------------------"<<endl;
	list.reverse();
	list.print();
*/
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