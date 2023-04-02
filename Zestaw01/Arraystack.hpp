#include <iostream>
#include <string>

using namespace std;

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

class Stack {
	public:
	
	Stack (int n) {			//konstruktor tworzący obiekt klasy Stack
		stos = new int[n];	//tablica przechowująca max n elementów
        max_rozmiar=n;		//maksymalny rozmiar naszej tablicy
	}
	
	~Stack () {
		delete [] stos;		//usuwanie tablicy
	}
	
	void push(int element) {	//wstawianie elementu na stos
		if (dlugosc == max_rozmiar) { //sprawdzam czy stos jest pełny
			throw std::out_of_range ("stos jest pełny");
		}
		stos[dlugosc++] = element;
	}
	
	int pop() { // usuwanie ostatniego elementu ze stosu i zwracanie jego wartosci
		if (empty()) { // sprawszam czy stos jest pusty
			throw std::out_of_range ("stos jest pusty");
		}
		return stos[--dlugosc];//jesli zmniejsze dlugosc tablicy to automatycznie pozbywam sie ostatniego elementu
	}

	
	int size() {	//sprawdzenie ile elementów jest aktualnie w tablicy
		return dlugosc;
	}
	
	bool empty() { 	//sprawdzenie czy w tablicy są jakieś elementy
		return dlugosc==0;
	}
	
	private:
	int* stos;
	int dlugosc = 0;	//ile elementów jest w danym momencie na stosie
    int max_rozmiar=0;	//ile elementów może pomiścić nasz stos
};

#endif
