#include <iostream>
#include <string>
#include "Set.hpp"

using namespace std;

int main (int argc, char *argv[]) {

    
	int liczba_operacji;
	char typ_operacji;
	int element;

	cin >> liczba_operacji;
	
	Set<int> set = Set<int>();
	
	for (int i=0;i<liczba_operacji;i++) {

		set.insert(2);
		set.insert(8);
		set.insert(6);
		set.insert(12);
		
		cin >> typ_operacji;//wybieramy operację, którą chcemy wykonać
		
		/*wstawianie elementów*/
		if(typ_operacji == 'i') {
			cin >> element; 
			set.insert(element);
		}
        /*usuwanie elementów*/
        else if(typ_operacji == 'p') { 
			if(!set.empty()) 
				cout << set.pop() << endl;
			else
				cout <<"EMPTY"<< endl;
		} 
        else if(typ_operacji == 'r') {
			if(!set.empty()){
                cin >> element; 
                set.remove(element);
            }
			else
				cout <<"EMPTY"<< endl;
		}
		/*rozmiar*/
        else if(typ_operacji == 's') { 
			cout << set.size() << endl;
		}
        /*wypisanie zbioru*/
        else if(typ_operacji == 'P') { 
			set.print();
		}
		/*operacje na zbiorach*/
		else if(typ_operacji=='I'){
            Set<int> genericSet = Set<int>();
            genericSet.insert(1);
            genericSet.insert(5);
            genericSet.insert(3);
            cout << "przeciecie ze zbiorem";
            genericSet.print();
			set.intersect(genericSet).print();
		}
        else if(typ_operacji=='U'){
            Set<int> genericSet = Set<int>();
            genericSet.insert(1);
            genericSet.insert(5);
            genericSet.insert(3);
            cout << "suma ze zbiorem";
            genericSet.print();
			set.unionn(genericSet).print();
		}
        else if(typ_operacji=='D'){
            Set<int> genericSet = Set<int>();
            genericSet.insert(1);
            genericSet.insert(5);
            genericSet.insert(3);
            cout << "roznica ze zbiorem";
            genericSet.print();
			set.difference(genericSet).print();
		}
	}	
}