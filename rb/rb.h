#ifndef RB_H
#define RB_H

#include <iostream>
#include <fstream>


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
        node<K,D>* insert (const K & key,const D & data, node<K,D> ** n, node<K,D> ** p);
        bool insert(const K & key,const D & data) ;
        node<K,D>* remove (const K & key,const D & data, node<K,D> ** n, node<K,D> ** p);
        bool remove(const K & key,const D & data) ;

        void convertirRedblack(node<K,D> **n,node<K,D> **p,bool child,node<K,D> *aux);
        color_t getColor(node<K,D> *&n);
        void setColor(node<K,D> *&n, color_t color);
        void preorderBST(node<K,D> *ptr);
        void preorder();
        int max(int a,int b);
        int altura(node<K,D> * n);
        int altura();
        void printARBOL(ofstream & es,node<K,D> *n);
        void printARBOL();
        void printCOLOR(ofstream & es,node<K,D> *ptr);
        void dibujararbol(int num);
        D& operator[](const K &_key);
        bool find(node<K,D> *n,int a);
        node<K,D>* sucesor(node<K,D> * n);
        void sucesorcito();
       
        bool turnSide(node<K,D> **n, bool side);
        void rotar(node<K,D>** n, bool side);
        bool balance(node<K,D> **n,bool child);
        node<K,D>* Min(node<K,D> **n);
        void print(node<K,D> * n);
        void print();


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