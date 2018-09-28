
#include "avl.h"
#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int main(){
	
    avl<int,int> avl;

    int iSecret, jSecret;
    srand (time(NULL));


    for(int i=1;i<30;i++){
        iSecret = rand() % 30 + 1;
        if(avl.insert(iSecret)==true){
            cout<<"Se inserto "<<iSecret<<endl;
            avl.dibujararbol(i);
        }else{
            
        }
       
    }

    avl.print();
    cout<<""<<endl;
    cout<<"******************************************"<<endl;
    
    for(int j=31;j<50;j++){
        jSecret = rand() % 30 + 1;
    
        if(avl.remove(jSecret)!=true){
            cout<<"Se elimino "<<jSecret<<endl;
            avl.dibujararbol(j);
        }else{
            
        }
    } 

    avl.print();

	return 0;
}
