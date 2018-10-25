// Example program
#include <iostream>
#include <string>

using namespace std;

template <class T, size_t cap = 100>
class BH
{
    private:
        T * elems;
        size_t size;
        int capacidad=0;
        
    public:
        BH(): elems(new T[cap]), size(0){};
        ~BH()
        {
            delete [] elems;
        }
        
        void push(T x)
        {
            if(capacidad == cap){
                return;
            } 
            elems[capacidad] = x;  
            up(capacidad);
            capacidad++;
        }
        
        // delete min 
        void pop()
        {
            if(capacidad==0){
                return;
            }
            
            elems[0]=elems[capacidad-1];
            down(0);
            capacidad--;
        }
        
        // min 
        T top()
        {
            return elems[0];
        }
    
    private:
        void up(int i)
        {
            while (i != 0 and elems[father(i)] > elems[i]) // i != 0 xq no puede subir la raiz y su padre tiene q ser mayor
            {  
                swap(elems [i], elems[father(i)]);
                i = father(i);
            }
        }

        
        void down(int i)
        {
            while (i<capacidad){ 
            if(min(i)){
                swap(elems[i],elems[childrig(i)]);
                i=childrig(i);
            }
            else if(min(i)==false){
                swap(elems[i],elems[childlef(i)]);
                i=childlef(i);
            }
            else{
                break;
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
        bool min (T i){
            if(elems[childrig(i)]<elems[childlef(i)]){
                return true;
            }else{
                return false;
            }

        }


};

int main()
{
    BH<int> h;
    
    for(int i = 19; i > 9; i--){
        h.push(i);
    }
    int array[10];

    

    cout << h.top() << endl;
    h.pop();
    h.pop();
    cout << h.top() << endl;
    return 0;
}