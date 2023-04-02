#include <iostream>
#include <string>

using namespace std;

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

int capacity=1000000;

class Queue {
	public:
	
	Queue () {			                //konstruktor tworzący obiekt klasy Queue
		kolejka = new int[capacity];	//tablica przechowująca max n elementów
		max_rozmiar=capacity;
	}

    Queue (int n) {			    //konstruktor tworzący obiekt klasy Queue
		kolejka = new int[n];	//tablica przechowująca max n elementów
        max_rozmiar=n;
	}
	
	~Queue () {
		delete [] kolejka;		//usuwanie tablicy
	}
	
	void push(int element) {	//wstawianie elementu na stos
		if (dlugosc == max_rozmiar) { //sprawdzam czy kolejka jest pełna
			throw std::out_of_range ("kolejka jest pełna");
		}
		kolejka[buforFront] = element;
        buforFront=(buforFront+1)%max_rozmiar;
		dlugosc++;
	}
	
	int pop() { // usuwanie ostatniego elementu ze stosu i zwracanie jego wartosci
		if (empty()) { // sprawszam czy stos jest pusty
			throw std::out_of_range ("kolejka jest pusta");
		}
        buforRear=(buforRear+1)%max_rozmiar;
        dlugosc--; //jesli zmniejsze dlugosc tablicy to automatycznie pozbywam sie ostatniego elementu
		return kolejka[buforRear];
	}

	
	int size() {	//sprawdzenie ile elementów jest aktualnie w tablicy
		return dlugosc;
	}
	
	bool empty() { 	//sprawdzenie czy w tablicy są jakieś elementy
		if (dlugosc == 0) {
			return true;
		} 
        else {
			return false;
		}
	}
	
	private:
	int* kolejka;
	int dlugosc = 0;	//ile elementów jest w danym momencie na stosie
    int max_rozmiar;
    int buforFront = 0;
	int buforRear = -1;
};

#endif
