#include <iostream>
#include <stdlib.h>
#include "CursorList.hpp"

using namespace std;

int main (int argc, char *argv[]) {
	
	int liczba_operacji;
	char typ_operacji;
	int element;

	cin >> liczba_operacji;
	
	CursorList lista = CursorList();
	
	for (int i=0;i<liczba_operacji;i++) {
		
		cin >> typ_operacji;//wybieramy operację, którą chcemy wykonać
		
		/*wstawianie elementów*/
		if(typ_operacji == 'F') { 
			if (lista.size() < ROZMIAR) { 
				cin >> element; 
				lista.push_front(element); 
			}
		}
        else if(typ_operacji == 'B') { 
			if(lista.size() < ROZMIAR) {
				cin >> element; 
				lista.push_back(element); 
			}
		} 
		/*usuwanie elementów*/ 
        else if(typ_operacji == 'f') {
			if(!lista.empty()) 
				cout << lista.pop_front() << endl;
			else
				cout <<"EMPTY"<< endl;
		}
        else if(typ_operacji == 'b') {
			if(!lista.empty()) 
				cout << lista.pop_back() << endl;
			else
				cout <<"EMPTY"<< endl;
		} 
		/*rozmiar*/
        else if(typ_operacji == 'S') { 
			cout << lista.size() << endl;
		}
		/*zamiana elementu na inny*/
		else if(typ_operacji=='R'){
			int x,y;
			cin >> x >> y ; 
			int i = lista.find(x);
			if (i == -1){		//nie znaleziono x na liście
					cout << "FALSE" << endl;
			}
			else{				
				//lista.erase(i);
				//lista.insert(i,y);
				lista.replace(i,y);
				cout <<"TRUE"<< endl;
			}
		}	
		lista.wypisz();
	}	
}