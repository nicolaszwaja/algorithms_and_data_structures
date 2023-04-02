#include <iostream>
#include <string>

#define ROZMIAR 1000000

using namespace std;

#ifndef CURSORLIST_H
#define CURSORLIST_H

class CursorList {

	public:
	struct Node {
		int value; 
		int next; 
	};

	CursorList () {
        lista = new Node[ROZMIAR];
		for (int i=0;i<(ROZMIAR-1);i++) {
			lista[i].next = i + 1;
		}
        lista[ROZMIAR-1].next=-1;

        spare = 0;
		head = 0;
		tail = 0;
		size_ = 0;
	}

	~CursorList () {}

    // void wypisz(){
    //     int temp=head;
    //     for(int i=0;i<size();i++){
    //         cout<<i<<": "<<lista[temp].value<<endl;
    //         temp=lista[temp].next;
    //     }
    // }
	
	void push_front(int x) {
		if (size() == ROZMIAR){
			throw std::out_of_range("lista jest pełna");
        }
		int temp = head;
		head = spare;
		lista[head].value = x;
		spare = lista[spare].next;
		lista[head].next = temp;

		size_++;
	}

	int pop_front() { 
		if (empty()){
			throw std::out_of_range("lista jest pusta");
        }
        int x = lista[head].value;
		int temp = head;
		head = lista[head].next;
		lista[temp].next = spare;
		spare = temp;

		size_--;
		if (size() == 0)
			head = spare;
		return x;

	}
	void push_back(int x) { 
		if (size() == ROZMIAR){
			throw std::out_of_range("lista jest pełna");
        }
		int temp = tail;
		tail = spare;
		lista[tail].value = x;
		spare = lista[spare].next;
		lista[temp].next = tail;
	
		size_++;
	}

	int pop_back() { 
		if (empty()){
			throw std::out_of_range("lista jest pusta");
        }
		int temp = head;
		for (int i = 0; i < size() - 2; i++) {
			temp = lista[temp].next;
		}
		lista[tail].next = spare;
		spare = tail;
		tail = temp;
	
		size_--;
		return lista[spare].value;
	}

	int size() {
		return size_;
	}

	bool empty() {
		return size()==0;
	}

	void clear() { // Czyści listę
		while (!empty()){
			pop_back();
		}	
        return;    
	}

	int find(int x) { // Zwraca pozycję pierwszego elementu o wartości x
		
		int temp = head;
		for (int i = 0; i <= size(); i++) {
			if (lista[temp].value == x)
				return temp;
			temp = lista[temp].next;
		}
		return -1;
	}

    void replace(int i, int y){
        lista[i].value = y;
        return;
    }

	int erase(int i){ // Usuwa i zwraca element na pozycji i
        if (i>size()){
			throw std::out_of_range("za krótka lista");
        }
        
		int temp=head;
		for (int j=0; j<i; j++) {
			temp = lista[temp].next;
		}
		int x = lista[temp].value;
        for (int j=0; j<size(); j++) {
			if(lista[j].next==temp){
                lista[j].next=lista[temp].next;
            }
		}
		size_--;
		return x;
    }

	void insert(int i, int x){ // Wstawia element x przed pozycję i
        if (size() == ROZMIAR){
			throw std::out_of_range("lista jest pełna");
        }
        int temp = spare;
        lista[spare].value = x;
        lista[i].next=spare;
        spare = lista[temp].next;
        
        size_++;

    }

	int remove(int x) { // Usuwa wystąpienia x i zwraca ich liczbę
		int licznik = 0;
		int i = -1;
		while (i != -1) {	//powtarzam instrukcje aż el. x nie będzie na liście
			i = find (x); 	//szukam w liście elementu x
			erase(i);		//usuwam go
			licznik++;
		}
		if(licznik==0){
			throw std::out_of_range ("w liście nie występuje element x");
		}
		return licznik;
	}

	private:

	Node* lista; // Tablica węzłów
	int head; // Indeks pierwszego węzła
	int tail; // Indeks ostatniego węzła
	int size_; // Rozmiar listy
	int spare; // Indeks pierwszego nieużytego elementu tablicy
};



 #endif