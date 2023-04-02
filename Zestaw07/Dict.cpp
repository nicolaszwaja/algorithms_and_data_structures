#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Dict.hpp"

using namespace std;

int main(int argc, char *argv[]){

    Dict<string, string> slownik;

    string klucz;
    string wartosc;

    ifstream plik;
	plik.open (argv[1], fstream::in);
	
    /*Program Dict.x powinien wczytać do słownika Dict<std::string, std::string> pary słów z pliku
    o nazwie podanej jako argument linii komend (argv[1]).*/
	while (plik >> klucz) {
		plik >> wartosc;
        slownik.insert (make_pair(klucz,wartosc));
	}
	
    /*Następnie wczytać słowa (klucze) ze standardowego wejścia. Jeżeli para o danym kluczu istnieje w
    słowniku należy wypisać odpowiadającą mu wartość, a w przeciwnym wypadku wypisać -.*/
	while (cin >> klucz) {
		if (slownik.find (klucz)==true){
            cout << slownik[klucz] << endl;
        }	
		else{
            cout << "-" << endl;
        }
	}
    
	plik.close();

}
