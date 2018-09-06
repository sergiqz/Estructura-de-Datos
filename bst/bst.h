#ifndef BTS_H_
#define BTS_H_

#include <iostream>
using namespace std;

template <class K,class D>
class BST;

template <class K,class D>
class Node
{
	private:
		K key;
		D data;
		Node<K,D> * p_children[2];
	public:
		 Node(const K & k,const D & d);
		 virtual ~Node();

		 

	friend class BST<K,D>;
};

template <class K,class D>
class BST
{
	private:
		Node<K,D> * root;

	public:
		BST(); //root null
		virtual ~BST(){

		}
		bool find(K _key);
		bool insert(K _key,D _data);
		bool remove(K _key);
		void print(Node<K,D> * n);
		void print();
		int altura(Node<K,D> * n);
		int altura();
		int max(int a,int b);
		void print_inverse_leve();
		void print_inverse_leve(Node<K,D> *n,int level);

	private:
		bool find(K _key,Node<K,D> **&tmp);


};
#include "bst.inl"
#endif
