#include <iostream>
#include <stdlib.h>
#include "ArrayStack.hpp"

#define ROZMIAR 1000000

using namespace std;

int main (int argc, char *argv[]) {
	
	char typ_operacji;
	int element;
	int liczba_operacji;
	
	cin >> liczba_operacji;
	
	Stack stos=Stack(ROZMIAR);
	
	for (int i=0;i<liczba_operacji;i++) {
		
		cin >> typ_operacji;//wybieramy operację, którą chcemy wykonać
		
		if (typ_operacji == 'A') { //A oznacza wrzucenie elementu na stos
			if (stos.size() < ROZMIAR) { //sprawdzay czy można jeszcze coś umieścić na stosie
				cin >> element; //pobieramy element
				stos.push(element); //wykonujemy push
			}
		} 

        else if (typ_operacji == 'D') { //D oznacza zdjęcie elementu ze stosu
			if (!stos.empty()) //sprawdzamy czy na stosie jest jakiś element
				cout << stos.pop() << endl; //wykonujemy pop
			else
				cout <<"EMPTY"<< endl;
		} 

        else if (typ_operacji == 'S') { //S iznacza wypisanie ilosci elementów na stosie
			cout << stos.size() << endl;
		}
	}
	
	
}