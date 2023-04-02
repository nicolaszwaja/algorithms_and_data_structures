#include <iostream>
#include <string>

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class List {
	
	public:
	
	struct Node {
		int value;
		Node* next;
		Node* prev;
	};
	
	List () {
		guard = new Node();
		guard->next = guard;
		guard->prev = guard;
		size_ = 0;
	}
	
	~List () {
		while (!empty())
			pop_front();
		delete guard;
	}
	
	void push_front (int x) { // wstawia element na początek listy
		
		Node* temp = new Node();
		temp->value = x;
		temp->next = guard->next;
		temp->prev = guard;
		guard->next->prev = temp;
		guard->next = temp;
		size_++;
		
	}
	
	int pop_front () { // usuwa i zwraca element z początku listy
		
		int x = guard->next->value;
		Node* temp = guard->next;
		guard->next = temp->next;
		temp->next->prev = guard;
		delete temp;
		size_--;
		return x;
		
	}
	
	void push_back(int x) { // wstawia element na koniec listy
		
		Node* temp = new Node();
		temp->value = x;
		temp->prev = guard->prev;
		temp->next = guard;
		guard->prev->next = temp;
		guard->prev = temp;
		size_++;
		
	}
	
	int pop_back() { // usuwa i zwraca element z końca listy
		
		int x = guard->prev->value;
		Node* temp = guard->prev;
		guard->prev = temp->prev;
		temp->prev->next = guard;
		delete temp;
		size_--;
		return x;
		
	}
	
	int size() { 
		return size_;
	}
	
	bool empty () {
		return size_==0;
	}
	
	void clear() { 
		while (!empty()) {
			pop_front();
		}
	}
	
	int find(int x) { // Zwraca pozycję pierwszego elementu o wartości x
		
		Node* search = guard;
		
		for (int i = 0; i < size(); i++) {
			search = search->next;
			if (search->value == x) {
				return i;
			}
		}
		return -1; //zwracam -1 jeśli nie ma w liście el. x
	}
	
	int erase(int i) { // Usuwa i zwraca element na pozycji i
		
		Node* temp = guard->next;

		if(i>size_){
			throw std::out_of_range ("w liście nie ma elementu o indeksie i");
		}
		
		for (int j=0; j<i; j++) {
			temp = temp->next;
		}
		
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		int x = temp->value;
		size_--;
		delete temp;
		return x;
		
	}
	
	void insert(int i, int x) { // wstawia element x przed pozycję i

		if(i>size_){
			throw std::out_of_range ("w liście nie ma elementu o indeksie i");
		}
		
		Node* temp = new Node();
		temp->value = x;
		
		Node* insert = guard;
		for (int n = 0; n < i; n++) {
			insert = insert->next;
		}
		
		temp->next = insert->next;
		temp->prev = insert;
		insert->next->prev = temp;
		insert->next = temp;
		size_++;
		
	}
	
	int remove(int x) { // usuwa wystąpienia x i zwraca ich liczbę
		
		int licznik = 0;
		int i = -1;
		do{					//powtarzam instrukcje aż el. x nie będzie na liście
			i = find (x); 	//szukam w liście elementu x
			erase(i);		//usuwam go
			licznik++;
		}while (i != -1); 
		if(licznik==0){
			throw std::out_of_range ("w liście nie występuje element x");
		}
		return licznik;
	}
	
	
	private:
	Node* guard;
	int size_;

};    

#endif
