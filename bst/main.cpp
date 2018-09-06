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

	/*insert_binary(1,10, tree);
	tree.print();
	remove_binary(1,9,tree);
	*/
	BST<int, int> tree;
	tree.insert(10, 4);
	tree.insert(15, 4);
	tree.insert(13, 4);
	tree.insert(16, 4);
	tree.insert(5, 4);
	tree.insert(3, 4);
	tree.insert(6, 4);
	tree.insert(2, 4);
	//tree.insert(4, 4);
	//tree.insert(1, 4);
	

	//tree.printgraf();
	tree.remove(5);
	tree.print();



	/*cout << tree.remove(65) << endl;
	tree.print();
	cout << tree.insert(65,89) << endl;
	tree.print();
	*/
	return 0;
}