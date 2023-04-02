#include <iostream>
#include <string>

using namespace std;

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

class Stack {
	public:
	
	struct Node {		//węzeł
		int wartosc;	//wartość elementu przechwywanego w węźle
		Node* wskaznik; //wskażnik na węzeł
	};
	
	Stack (int n) {
		max_rozmiar=n; 	//tworząc stos ustalamy ile maksymalnie elementów pomieści
	}
	
	~Stack () {
		while (!empty()) {
			pop();		//usuwamy elementy aż na stosie nie zostanie żaden
		}
	}
	
	void push(int element) { 
		
		if (size() == max_rozmiar) {
			throw std::out_of_range ("stos jest pełny");
		}
		
		Node* temp = new Node;		//tworzymy nowy węzeł tymczasowy
		temp->wartosc = element;	//nowy węzeł przechowuje wstawiany element
		temp->wskaznik = stos;		
		stos = temp;
		dlugosc++;		//po dodaniu elementu zwiększa się rozmiar stosu
		
	} 
	
	int pop() { 
		
		if (empty()) { 
			throw std::out_of_range ("stos jest pusty");
		}
		
		int element = stos->wartosc; //zwracamy wartość węzła ze szczytu stosu
		Node* poprzedni = stos->wskaznik; //tworzymy wskaźnik na el wskakujący na szczyt
		delete stos;
		stos = poprzedni; //zmienił się el na szczycie więc przepinamy wskaźnik na niego
		dlugosc--;
		return element;

	}
	
	
	int size() { 
		return dlugosc;
	}
	
	bool empty() {
		if (dlugosc == 0) {
			return true;
		} 
		else {
			return false;
		}
	}
	
	private:
	Node* stos; //węzeł będący pod szczytem stosu
	int dlugosc = 0;
	int max_rozmiar;
};

#endif