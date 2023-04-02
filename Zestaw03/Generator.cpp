#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main () {
	
	srand(time(NULL)); //dzięki tej lini za każdym razem wylosujemy inny wynik
	
	int n = rand() % 1000; // losujemy ilość operacji, gdzie ich max wartosc to 1000
	cout << n << endl; 
	int opcja;
	for (int i = 0; i < n; i++) {

        opcja=rand()%5;

            if(opcja==0){
				cout <<"F"<<" "<<rand()%(1000)<< endl; //tutaj rand losuje wartość elementu, który wrzucimy na stos(max to 1000000)
            }
             if(opcja==1){
				cout <<"B"<<" "<<rand()%(1000)<< endl; //tutaj rand losuje wartość elementu, który wrzucimy na stos(max to 1000000)
            }
            if(opcja==2){
				cout << "f" << endl;
            } 
            if(opcja==3){
				cout << "b" << endl;
            }    
			if(opcja==4){
				cout << "S" << endl;
            }
	}
}
	