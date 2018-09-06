#include <iostream>
#include "linked_list.h"
#include <ctime>
#include <cstdio>
using namespace std;




int main(){

	linked_list<int> list;

	list.insert_front(5);
	list.insert_front(2);
	list.insert_front(3);
	list.insert_front(8);
	list.insert_front(9);
	
	list.remove_back();
	list.insert_front(1556);

	linked_list<int> list2;



	list.print();

	
}