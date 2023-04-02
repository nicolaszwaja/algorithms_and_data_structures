#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>

using namespace std;

template <class T> void sort(vector<T>& v){
    int key;
    int n = v.size();
    for (int i = 1; i < n; i++){
        key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
};

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

	//for(int i : dane)
	//   cout << i <<endl;

    return 0;
}