#ifndef RB_H
#define RB_H

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

enum color_t: bool {BLACK = 0, RED = 1};

template <class K, class D>
class rb;

template <class K, class D>
class node
{
    private:
        K key;
        D data;
        node<K,D> *p_child[2];
        color_t color;
        node<K,D> *parent;
        int hgt;
    
    public:
        node();
        ~node();
        node(const K & _key, const D & _data);
    friend class rb<K,D>;
};



template <class K, class D>
class rb
{
    private:
        node<K,D> * root;
    public:
        rb();
        ~rb();
        bool insertBST(K x,node<K,D> **&tmp,node<K,D> **&padre);
        bool insertValor(K _key,D _data);
        void convertirRedblack(node<K,D> **&ptr);
        color_t getColor(node<K,D> *&n);
        void setColor(node<K,D> *&n, color_t color);
        void preorderBST(node<K,D> *ptr);
        void preorder();
        void rotacionizq(node<K,D>*& ptr);
        void rotacionder(node<K,D>*& ptr);
        int max(int a,int b);
        int altura(node<K,D> * n);
        int altura();
        void printARBOL(node<K,D> *n);
        void printARBOL();
        void printCOLOR(node<K,D> *n);
        D& operator[](const K &_key);
        bool find(node<K,D> *n,int a);
        node<K,D>* sucesor(node<K,D> * n);
        void sucesorcito();

    private:
        bool draw(node<K,D> *n, ofstream & os);
};


template <class K, class D>
class iterator
    {
        private:
        node<K,D> * p_current;
        
        public:
        iterator(node<K,D> * p_c)
        {
            p_current = p_c;
        }
        
        iterator & operator++() // next
        {
            p_current = sucesor(p_current);
        }
        
        bool operator != (const iterator & it) // end
        {
            return p_current != it.p_current;
        }
        
        K & operator*() // content
        {
            return p_current->dato;
        }
    };

#include "rb.inl"
#endif
