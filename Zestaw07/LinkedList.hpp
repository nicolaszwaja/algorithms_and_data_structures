#include <iostream>
#include <iterator>
#include <cstddef>

using namespace std;

template<class T>
class List {
	
	public:
	
	struct Node {
		T value;
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
			pop_back();
		delete guard;
	}

	void push_front (T x) { // wstawia element na początek listy
		
		Node* temp = new Node();
		temp->value = x;
		temp->next = guard->next;
		temp->prev = guard;
		guard->next->prev = temp;
		guard->next = temp;
		size_++;
		
	}
	
	T pop_front () { // Usuwa i zwraca element z początku listy
		
		T x = guard->next->value;
		Node* temp = guard->next;
		guard->next = temp->next;
		temp->next->prev = guard;
		delete temp;
		size_--;
		return x;
	
	}
	
	void push_back(T x) { // Dołącza element na koniec listy
		
		Node* temp = new Node();
		temp->value = x;
		temp->prev = guard->prev;
		temp->next = guard;
		guard->prev->next = temp;
		guard->prev = temp;
		size_++;
	
	}
	
	T pop_back() { // Usuwa i zwraca element z końca listy
		
		T x = guard->prev->value;
		Node* temp = guard->prev;
		guard->prev = temp->prev;
		temp->prev->next = guard;
		delete temp;
		size_--;
		return x;
		
	}
	
	int size() { // Zwraca liczbę elementów w liście
		return size_;
	}
	
	bool empty () { // Zwraca true gdy lista jest pusta
		return size_==0;
	}
	
	void clear() { // Czyści listę
		while (!empty())
			pop_front();
		
	}

	int find(T x) { // Zwraca pozycję pierwszego elementu o wartości x
		
		Node* search = guard;
		
		for (int i = 0; i < size(); i++) {
			search = search->next;
			if (search->value == x) {
				return i;
			}
		}
		return -1; //zwracam -1 jeśli nie ma w liście el. x
	}
	
	T erase(int i) { // Usuwa i zwraca element na pozycji i
		
		Node* temp = guard->next;

		if(i>size_){
			throw std::out_of_range ("w liście nie ma elementu o indeksie i");
		}
		
		for (int j=0; j<i; j++) {
			temp = temp->next;
		}
		
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		T x = temp->value;
		size_--;
		delete temp;
		return x;
		
	}
	
	void insert(int i, T x) { // wstawia element x przed pozycję i

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
	
	int remove(T x) { // usuwa wystąpienia x i zwraca ich liczbę
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
	
	struct Iterator {
		
		Iterator(Node* ptr) : curNode(ptr) {}

		Node& operator*() const {
			return *curNode;
		}
		
		Node* operator->() {
			return curNode;
		}
		
		Iterator operator++(int) {
			curNode = curNode->next;
			return *this;
		}

		friend bool operator== (const Iterator& a, const Iterator& b){
			return a.curNode == b.curNode;
		};

		friend bool operator!= (const Iterator& a, const Iterator& b){
			return !(a==b); 
		};
		
	private:
		Node* curNode;
	};

	Iterator begin() {
		return Iterator(guard->next);
	}
	
	Iterator end() {
		return Iterator(guard);
	}
	
	private:
	
	Node* guard;
	int size_;
	
};