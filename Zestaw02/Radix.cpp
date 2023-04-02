#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "ArrayQueue.hpp"
#include <cmath>

using namespace std;

void radix(vector<int>& v){                 //na wejściu dostaję wektor liczb do posortowania

    Queue kolejki[10]; //tablica dziesięciu kolejek

    /*sortowanie pozycyjne*/
    int reszta=0;
    int x=0;

    for(int i=0;i<10;i++){

        for(const auto& a : v){
            int temp=(a/pow(10,i));
            reszta= temp%10 ;
            kolejki[reszta].push(a);
        }

        v.clear();
        
        for(int n=0;n<10;n++) {             //przeglądam każdą z kolejek po kolei
		    while(!kolejki[n].empty()) {    //wyciągam z niej elementy dopóki kolejka nie będzie pusta
                x=kolejki[n].pop();
			    v.push_back(x);             //elementy z kolejek umieszczam w wektorze
		    }
    	}

    }
}
    


int main (int argc, char *argv[]) {

    vector<int> vector;

    int x;
    while(cin>>x)
    vector.push_back(x);

    radix(vector);

    for(const auto& i : vector)
    cout << i << endl;


}