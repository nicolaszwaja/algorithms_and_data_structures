#include <iostream>
#include <string>

#define ROZMIAR 1000000

using namespace std;

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class ArrayList {

    public:

    ArrayList(){
		lista = new int[ROZMIAR];
        size_= 0;
        max_rozmiar= ROZMIAR;	
	}
	
	~ArrayList(){
		size_= 0;
	}

    void push_front(int x){
        if (size_==max_rozmiar) {
			throw std::out_of_range ("lista jest pełna");
		}
        int n = size_;
        for(;n>0;n--){
            lista[n]=lista[n-1];
        }
        lista[0] = x;
        size_++;
    }
    int pop_front(){
        if (empty()) {
			throw std::out_of_range ("lista jest pusta");
		}
        int x=lista[0];
        for(int i=0;i<(size_-1);i++){
            lista[i]=lista[i+1];
        }
        size_--;
        return x;
    }
    void push_back(int x){
        if (size_==max_rozmiar) {
			throw std::out_of_range ("lista jest pełna");
		}
        lista[size_] = x;
        size_++;
    }
    int pop_back(){
        if (empty()) {
			throw std::out_of_range ("lista jest pusta");
		}
        size_--;
        return lista[size_];
    }
    int size(){
        return size_;
    }
    bool empty(){
        return size_==0;
    }
    void clear(){
        while(!empty()){
            pop_back();
        }
    }
    int find(int x){
        for(int i=0;i<size_;i++){
            if(lista[i]==x){
                return i;
            }
        }
        return -1;
    }
    int erase(int i){
        int x=lista[i];
        for(;i<size_;i++){
            lista[i]=lista[i+1];
        }
        size_--;
        return x;
    }
    void insert(int i, int x){
        for(int j=size_;j>i;j--){
            lista[j]=lista[j-1];
        }
        lista[i]=x;
        size_++;
    }
    int remove(int x){
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
	int* lista;
    int max_rozmiar;
    int size_=0;

};

#endif