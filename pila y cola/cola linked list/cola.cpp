#include <iostream>
#include "linked_list.cpp"
#include <ctime>
#include <cstdio>
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


	const int N=1000000000;
	int *aint;
	for (int n = 10; n <= N; n*=10)
	{
		float ta=clock();
		aint=new int[n];
		for(int i=0; i<n; i++){
			aint[i]=i*i;
		}
		delete []aint;
		ta=clock()-ta;
		float tl = clock();
		linked_list<int> * lint=new linked_list<int>;
		for(int i=0; i<n; i++){
			lint->insert_front(i*i);
		}
		delete lint;
		tl=clock()-tl;
		printf("%d %.3f %.3f \n", n, ta / CLOCKS_PER_SEC, tl / CLOCKS_PER_SEC);
	}










/*

	cola<int> cola;
	cola.insertarcola(5);
	cola.insertarcola(7);
	cola.insertarcola(3);
	cola.print_cola();

	cola.remove_cola();
	cola.print_cola();
*/

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