#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>

using namespace std;

template <class T> void sort(vector<T>& v){
    int temp, min;
    int n = v.size();
    for (int i = 0; i < n-1; i++){
        min = i;
        for (int j = i+1; j < n; j++){
            if (v[j] < v[min]){
                min= j;
            }
        }        
        if(min!=i){
            temp=v[i];
            v[i]=v[min];
            v[min]=temp;
        }
    }
}

int main(int argc, char *argv[]){

    int wejscie_int;
	vector<int> dane;

	int licznik=0;
	while (cin >> wejscie_int) { // czytaj aż skończy się wejście
		dane.push_back (wejscie_int);
        licznik++;
	}
	
    auto start = std::chrono::high_resolution_clock::now();
	sort<int> (dane);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr <<"rozmiar danych: "<<licznik<< ", czas wykonania w sekundach = " << elapsed.count() << endl;

	// for(int i : dane)
	//     cout << i <<endl;

    return 0;
}