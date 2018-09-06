#include "bst.h"

#include <iostream>

using namespace std;

void insert_binary(int  low, int   high, BST<int, int> & tree)
{
//	cout<<low<< " "<<high<<endl;
	if(low == high) return;
	int m = (low + high) / 2;
	tree.insert(m,m);
	insert_binary(low, m, tree);
	insert_binary(m+1, high, tree);
}

void remove_binary(int  low, int   high, BST<int, int> & tree)
{
//	cout<<low<< " "<<high<<endl;
	if(low == high) return;
	int m = (low + high) / 2;
	cout<<endl<<"Removing... "<<m<<endl;
	tree.remove(m);
	tree.print();
	remove_binary(low, m, tree);
	remove_binary(m+1, high, tree);
}

int main()
{
	BST<int, int> tree;
	insert_binary(1,10, tree);
	tree.print();
	remove_binary(1,9,tree);
	/*
	bst<int, float> tree;
	tree.insert(41, .43);
	tree.insert(20, .5454);
	tree.insert(65, .23);
	tree.insert(50, .4542);
	tree.insert(91, 43.5454);
	tree.insert(72, 3.23);
	tree.insert(99, 321.32);
	tree.print();

	cout << tree.remove(65) << endl;
	tree.print();
	cout << tree.insert(65,89) << endl;
	tree.print();
	*/
	return 0;
}