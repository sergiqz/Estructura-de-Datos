
#include "avl.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	
    avl<int,int> avl;


    for(int i=1;i<21;i++){
        avl.insert(i);   
    }
    avl.print();
    cout<<"--------------------------"<<endl;
    avl.remove(1);

    avl.print();
	


	return 0;
}
