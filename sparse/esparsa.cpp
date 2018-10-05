#include <cstdio>
#include <iostream>
#include <stddef.h>
#include <iterator>
using namespace std;

template <class T>
struct nodes
{
	unsigned pos[2];				
	nodes<T> * p_next[2];	
	T dato;

	nodes(const int & i, const int & j, nodes<T> * r_next, nodes<T> * c_next)
	{
		pos[0] = i;
		pos[1] = j;
		p_next[0] = r_next;
		p_next[1] = c_next;
	}
};

template <class T>
class sparse_matrix
{

	private:
		nodes<T> **index[2];
		unsigned int n_rows,n_cols;
	 
	public:
		sparse_matrix(const int & m, const int & n){
			index[0] = new nodes<T> * [m];
			index[1] = new nodes<T> * [n];
			n_rows=m;
			n_cols=n;

		}
		~sparse_matrix();
		void destruct(void);

		T & operator()(const int & i, const int & j);	
		bool find(nodes<T> **& n, const int & i, const int & p, const bool & b);
		void print(const bool & b);
		friend std::ostream & operator << (ostream & os, const sparse_matrix<T> & matrix){
			for (int i = 1; i <= matrix.m; i++) {
				for (int j = 1; j <= matrix.n; j++) {
					

					
				}

				
				
			}

			
		}
	private:
		
};

template <class T>
sparse_matrix<T>::~sparse_matrix()
{
	this->destruct();
}


template <class T>
void sparse_matrix<T>::destruct(void)
{
	if (this->index[2] != NULL) {
		delete this->index[2];
		
	}

	//delete this->n_rows;
}









template <class T>
T & sparse_matrix<T>::operator()(const int & i, const int & j)	
{
	nodes<T> ** nr;
	if(!find(nr, i, j, 0))	
	{
		nodes<T> ** nc;
		find(nc, j, i, 1);	

		*nr = *nc = new nodes<T>(i, j, *nr, *nc);
	
	}

	return (*nr)->dato;
}


template <class T>
bool sparse_matrix<T>::find(nodes<T> **& n, const int & i, const int & p, const bool & b)
{

	n = &index[b][i];	
	while(*n)
	{
		if((*n)->pos[!b] == i){
			return true;
		}
		if((*n)->pos[!b] > i){ 
			return false;
		}
		n = &(*n)->p_next[b];
	}

	return false;
}




template <class T>
void sparse_matrix<T>::print(const bool & b)
{
	for (int i = 1; i <= n_rows; i++) {
		for (int j = 1; j <= n_cols; j++) {
		nodes<T> * n = index[b][i];
		
			printf("(%d %d) ", n->pos[0], n->pos[1]);
			std::cout << n->dato << " -> ";
			n = n->p_next[b];
		

		printf("\n");
		
		}
	}
		
	




	
}














int main()
{
	sparse_matrix<int> m(10,10);
//	m(1, 1) = 100;
	m(2, 5) = 2;
	m(4, 2) = 6;
	m(5, 3) = 20;
	m(3, 9) = 10;
	m.print(1);

	//cout << m << endl
	
	return 0;
}