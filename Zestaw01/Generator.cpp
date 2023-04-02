#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ArrayStack.hpp"

using namespace std;

int main () {
	
	srand(time(NULL)); //dzięki tej lini za każdym razem wylosujemy inny wynik
	
	int n = rand() % 1000; // losujemy ilość operacji, gdzie ich max wartosc to 1000
	cout << n << endl; 
	
	for (int i = 0; i < n; i++) {

        int opcja=rand()%3;

            if(opcja==0){
				cout <<"A"<<" "<<rand()%(10^6)<< endl; //tutaj rand losuje wartość elementu, który wrzucimy na stos(max to 1000000)
				break;
            }
            if(opcja==1){
				cout << "D" << endl;
				break;
            }    
			if(opcja==2){
				cout << "S" << endl;
				break;
            }
	}
}
	
