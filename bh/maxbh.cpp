// Example program
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class T, size_t cap = 100>
class BH
{
    private:
        T * elems;
        size_t size;
        ofstream os;

    public:
        BH(): elems(new T[cap]), size(0),os("grap.dot"){};
        ~BH()
        {
            delete [] elems;
        }
        
        void push(T x)
        {
            if(size == cap){
                return;
            } 
            elems[size] = x;  
            up(size);
            size++;
        }
        
        // delete min 
        void pop()
        {
            if(size==0){
                return;
            }
            
            elems[0]=elems[size-1];
            down(0);
            size--;
        }
        
        // min 
        T top()
        {
            return elems[0];
        }

        void Heapily(int i){
		    int node = i; 
		    if (childlef(i)<size and elems[childlef(i)] > elems[i]){
		        node = childlef(i); 
		    }
		      if (childrig(i)<size and elems[childrig(i)] > elems[node]){ 
		          node = childrig(i); 
		      }
		      if (node != i) 
		      { 
		          swap(elems[i],elems[node]); 
		          Heapily(node); 
		      } 
        }
        void printArray()
		{
   			for (int i=0; i<size; ++i){
	    			cout << elems[i] <<endl;
	   		}
	   	}
	   void convertir_heap(int array[],int _size){
	      size=0;
	      int f;
	      if (size<_size)
	        f=_size;
	      else 
	        f=size;
	      for(int i=0;i<f;i++){
	        elems[i]=array[i];
	        size++;
	      }
	    }

	   	void Heap_sort(){
		    int temp=size;
		    for (int i = size/2; i >= 0; i--){
		        Heapily(i);
		    }
		    
		    for (int i=size-1; i>=0; i--){ 
		          size=i;
		          swap(elems[0], elems[i]);  
		          Heapily(0); 
		      }
		     size=temp;
		       
        }


        void draw(){
            os<<"graph {"<<endl;
            os<<elems[0]<<endl;
            print();
            os<<"}"<<endl;
        }

        void print(){
            int c=0;
            while(c<size){
                int l=childlef(c);
                int r=childrig(c);
                if(l<size){
                    os<<elems[c]<<"--"<<elems[l]<<endl;
                }
                if(r<size){
                    os<<elems[c]<<"--"<<elems[r]<<endl;
                }
                c++;
            }
        }
    
    private:
        void up(int i)
        {
            while (i != 0 and elems[father(i)] < elems[i])
            {  
                swap(elems [i], elems[father(i)]);
                i = father(i);
            }
        }

        
        void down(int i)
        {
            while (i<size){ 
            	if(max(i)){
                	swap(elems[i],elems[childrig(i)]);
                	i=childrig(i);
            	}
            	else if(max(i)==false){
                	swap(elems[i],elems[childlef(i)]);
                	i=childlef(i);
            	}else{       
                	return;
            	}
         	}	 
            
        }
        int father(int i){
            return (i-1)/2;
        }
        int childlef(int i){
            return i*2+1; 
        } 
        int childrig(int i){
            return i*2+2;
        }
        bool max (T i){
            if(elems[childrig(i)]>elems[childlef(i)]){
                return true;
            }else{
                return false;
            }

        }



};

int main()
{
    BH<int> h;
    
   /* for(int i = 19; i > 9; i--){
        h.push(i);
    }
    */
    int array[10]={20,1,45,5,76,43,12,200,54,23};

    h.convertir_heap(array,10);
    h.printArray();
    h.Heap_sort();
    cout<<"-------------------"<<endl;
    h.printArray();

    //cout << h.top() << endl;

    return 0;
}