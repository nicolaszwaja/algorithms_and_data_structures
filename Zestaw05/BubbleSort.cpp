#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>

using namespace std;

template <class T> int sort(std::vector<T>& v){
    T temp;
    int n = v.size();
    int licznik_operacji=0;

    for (int i=0; i<n-1; i++){
        bool swapped = false;
        for (int j=0; j<n-i-1; j++){
            licznik_operacji++;
            if (v[j] > v[j + 1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
                swapped = true;

                licznik_operacji++;
            }   
        }
        if(swapped==false)
          break;    
    }       
    return licznik_operacji;               
}

int main(int argc, char *argv[]){

    int wejscie_int;
	vector<int> dane;
    int operacje = 0;

	int licznik=0;
	while (cin >> wejscie_int) { // czytaj aż skończy się wejście
		dane.push_back (wejscie_int);
        licznik++;
	}
	
    //auto start = std::chrono::high_resolution_clock::now();
	operacje = sort<int> (dane);
    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> elapsed = end - start;
    //std::cerr <<"rozmiar danych: "<<licznik<< ", czas wykonania w sekundach = " << elapsed.count() << endl;

    //cout<<"liczba operacji: "<<operacje<<endl;

	//for(int i : dane)
	//    cout << i <<endl;

    return 0;
}