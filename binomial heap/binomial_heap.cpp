#include <cstring>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

template <class T, int N=64>
class binomial_heap;

template <class T>
class binomial_tree
{
private:
	T dato;
	vector<binomial_tree<T>*> p_children;
public:
	binomial_tree(const T & d){
		dato=d;
	}
	~binomial_tree(){}
	void print(ostream & os){
		os<<"p"<<this<<" [label=\""<<dato<<"\"]"<<endl;
		for(binomial_tree<T>*p:p_children){
			p->print(os);
			os<<"p"<<this<<" -> p"<<p<<endl;
		}
	}
	void imprimir(){

		cout<<"dato: "<<dato<<endl;
		cout<<p_children.size()<<endl;

		for(binomial_tree<T>*p:p_children){
			p->imprimir();
			
		}
	}
	int convert(int array[],int i){			
		array[i]=dato;
		cout<<i<<endl;
		i++;
		for(binomial_tree<T>*p:p_children){
			p->convert(array,i);
			i++;	
		}
		
	}
	friend class binomial_heap<T>;
};

template <class T, int N>
class binomial_heap
{
private:
	binomial_tree<T> * head[N];
	int size;
public:
	binomial_heap(){
		memset(head,0,sizeof(head));
		size=0;
	}
	~binomial_heap(){}
	void insert(const T & d){
		insert(new binomial_tree<T>(d));
	}
	void insert(binomial_tree<T> * b){
		int i = b->p_children.size();
		
		if(!head[i]){
			head[i]=b;
			size++;
			return;
		}
		insert(merge(head[i],b));
		head[i]=NULL;
	}
	binomial_tree<T> * merge(binomial_tree<T> * a, binomial_tree<T> * b){
		if(a->dato < b->dato){
			a->p_children.push_back(b);
			
			return a;
		}
		b->p_children.push_back(a);
		return b;
	}	



	int remove_min(){
		int min = head[1];
	  	//remove(min);
	  	return min;
	}



	binomial_tree<T> * find(){ 

	}	 

	void print(){
		ofstream os("binh.dot");
		os<<"digraph bh{ "<<endl;
		for(int i=0; i<N; i++){
			if(head[i]) head[i]->print(os);
		}
		os<<"}"<<endl;
		os.close();
	}


	void imprimir(){
		
		
		binomial_tree<T>*p;
		for(int i=0; i<N; i++){
			if(head[i]){
				head[i]->imprimir();
				
			}
		}
		
	}
	int convert(int array[]){
		int min;
		int j=0;
		for(int i=0; i<N; i++){
			if(head[i]){
				head[i]->convert(array,j-1);
				j++;
			}
			j++;
		}
		return min;
		
	}


	void bubbleDown(int idx) { 
		int childIdx = child(idx);
		  if (childIdx == -1) return; 
		  int minIdx = getMinIdx(idx, childIdx, childIdx + 1);
		  
		  if (minIdx != idx) {
		    swap(head[minIdx], head[idx]);
		    bubbleDown(minIdx);
		  	}
	}
	void bubbleUp(int idx) { 
		int parentIdx = parent(idx);
		if (parentIdx == -1) return; 

		if (head[parentIdx] > head[idx]) {
			swap(head[parentIdx], head[idx]);
		    bubbleUp(parentIdx);
		} 
	}
	int parent(unsigned int idx) const {
  		if (size <= 1) return -1; 
  		return ((int) idx / 2); 
	}






	int child(unsigned int idx) const {
		  if (size <= 1 || 2 * idx > size ) return -1; 
		  return (2 * idx);
		}



	int getMinIdx(int aIdx, int bIdx, int cIdx) {
		  bool isLeftSmaller = (head[aIdx] < head[bIdx]);

		  if (cIdx > (int) size) { 
		    return isLeftSmaller ? aIdx : bIdx;
		  } else if (isLeftSmaller) {
		    return (head[aIdx] < head[cIdx]) ? aIdx : cIdx;
		  } else {
		    return (head[bIdx] < head[cIdx]) ? bIdx : cIdx;
		  }
	}
	int find(unsigned int idx, int val) const { //O(log n)
	 /* if (idx > size) return -1; //base case: idx out of bounds
	  if (val < head[idx]) return -1;   //base case: val not in min-heap
	  if (head[idx] == val) return idx; //Found the val, return its index
*/
	  int childIdx = child(idx), i = -1;
	  cout<<head[idx]->dato<<endl;
	  if (childIdx != -1) { //find in left and right children
	    i = max(find(childIdx, val), find(childIdx + 1, val));
	  }

	  return i;
	}



	/*void remove(int val) { //O(2 * log n)
	  int idx = find(1, val);
	  if (idx == -1) return;

	  head[idx] = head[size--]; // swap current with last item
	 
	  bubbleDown(idx);
	  bubbleUp(idx);
	}
*/



};

int main(){
	binomial_heap<int> bh;
	int array[6];
	bh.insert(2);
	bh.insert(44);
	bh.insert(55);
	bh.insert(12);
	bh.insert(1);
	bh.insert(100);
	//bh.insert(39);
	//bh.insert(0);
	//bh.insert(85);
	/*
	for(int i=1;i<1024;i++){
		bh.insert(i);
	}*/
	cout<<bh.find(1,1)<<endl;
	//bh.convert(array);

	/*for(int i=0;i<6;i++){
		cout<<array[i]<<endl;
	}
	*/

	//bh.find(1,2);
	bh.imprimir();
	return 0;
}
