#include <iostream>
#include "quad.h"
using namespace std;
int main(){
	Quad matrix(Point(0, 0),Point(5,5));
	Node a(Point(1, 3), 1); 
	

	matrix.insert(&a);

    return 0;
}