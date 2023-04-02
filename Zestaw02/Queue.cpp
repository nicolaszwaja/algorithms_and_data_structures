#include <iostream>
#include <stdlib.h>
#include "LinkedQueue.hpp"

#define ROZMIAR 1000000

using namespace std;

int main (int argc, char *argv[]) {
	
	char typ_operacji;
	int element;
	int liczba_operacji;
	
	cin >> liczba_operacji;
	
	Queue kolejka=Queue();
	
	for (int i=0;i<liczba_operacji;i++) {
		
		cin >> typ_operacji;//wybieramy operację, którą chcemy wykonać
		
		if (typ_operacji == 'A') { //A oznacza wrzucenie elementu na stos
			if (kolejka.size() < ROZMIAR) { //sprawdzay czy można jeszcze coś umieścić na stosie
				cin >> element; //pobieramy element
				kolejka.push(element); //wykonujemy push
			}
		} 

        else if (typ_operacji == 'D') { //D oznacza zdjęcie elementu ze stosu
			if (!kolejka.empty()) //sprawdzamy czy na stosie jest jakiś element
				cout << kolejka.pop() << endl; //wykonujemy pop
			else
				cout <<"EMPTY"<< endl;
		} 

        else if (typ_operacji == 'S') { //S iznacza wypisanie ilosci elementów na stosie
			cout << kolejka.size() << endl;
		}
	}
	
	
}