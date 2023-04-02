#include <iostream>
#include <string>

using namespace std;

#define ROZMIAR 1000000

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

class Queue {
	public:
	
	struct Node {		//węzeł
		int wartosc;	//wartość elementu przechwywanego w węźle
		Node* wskaznik; //wskażnik na nastepny węzeł
	};
	
	Queue () {}
	
	~Queue () {
		while (!empty()) {
			pop();      //usuwamy elementy aż na stosie nie zostanie żaden
		}
	}
	
	void push(int element) { // Wstawia element do kolejki 

		if (dlugosc==ROZMIAR) {
			throw std::out_of_range ("kolejka jest pełna");
		}
		
		Node* temp = new Node; //tworzę nowy węzeł tymczasowy
		temp->wartosc=element; //wartość węzła to przekazany element
		temp->wskaznik=NULL;	//wskazuje on na NULL
		if(pierwszy==NULL && ostatni==NULL){
			pierwszy=ostatni=temp;//jeśli to pierwszy element to oba wskaźniki będą wskazywać ten sam (właśnie dodany) element
			dlugosc++; 
			return;
		}
		ostatni->wskaznik=temp; //jeśli był już jakiś dodany to niech wskazuje on na element, który dodajemy teraz
		ostatni=temp; //teraz ostatni w kolejce jest ten właśnie dodany
		
		dlugosc++;
		
	} 
	
	int pop() { 
		
		if (empty()) {
			throw std::out_of_range ("kolejka jest pusta");
		}
		int wynik;
		Node* temp = pierwszy;
		if(pierwszy==ostatni){
			wynik = pierwszy->wartosc;
			pierwszy=ostatni=NULL;
		}
		else{
			wynik = pierwszy->wartosc;
			pierwszy=pierwszy->wskaznik;
		}
		delete temp;
		dlugosc--;
		return wynik;
		
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
	Node* pierwszy=NULL; //zachowuje adres elementu, który pierwszy opusci kolejke(wskaźnik)
	Node* ostatni=NULL;	//zachowuje adres elementu, który jako ostatni został umieszczony w kolejce(wskaźnik)
	int dlugosc = 0;
};

#endif