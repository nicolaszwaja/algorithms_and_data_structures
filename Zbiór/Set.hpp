#include <iostream>
#include <string>

using namespace std;

#ifndef SET_H
#define SET_H

template<class T>
class Set {
	
	public:
	
	Set(){
        currCapacity = 8;
		list = new T[currCapacity]; //lista ma być posortowana rosnąco
		size_ = 0;
	}

    ~Set(){
        delete[] list;
    }

    void print(){
        cout<<"{";
        for(int i=0;i<size();i++)
            cout<<list[i]<<" ";
        cout<<"}"<<endl;    
    }
    
	void insert(T x){ //umieszcza element w zbiorze
		if(isPresent(x))
          return;
        if(size()+1>currCapacity)    
            resizeArray(DOUBLE_SIZE);

        int idx=0;
        if(size()!=0){
            while(x>list[idx])
            idx++;
            for(int i = size(); i>idx; i--){
                list[i]=list[i-1];
            }  
        }
        list[idx]=x;  
        size_++;
        return;   
	}
	
	T pop(){ //usuwa i zwraca element z końca listy zbioru
        if(size()==0)
            throw std::out_of_range ("set is empty");
        if(size()-1<currCapacity/4)    
            resizeArray(HALVE_SIZE);    
        size_--;    
		return list[size()];
	}

    void remove(T x){//usuwa wybray element ze zbioru
        if(size()==0)
            throw std::out_of_range ("set is empty");
        if(size()-1<currCapacity/4)    
            resizeArray(HALVE_SIZE);  

        int idx = binarySearch(list, 0, size()-1, x);
        if(idx==-1)
            return;
        for(int i=idx; i<size(); i++){
                list[i]=list[i+1];
        }    
        size_--;    
    }

	int size(){ //zwraca ilość elementów w zbiorze
		return size_;
	}
	
	bool empty(){//sprawdza czy w zbiorze są jakieś elementy
		return size_==0;
	}

    int binarySearch(int arr[], int l, int r, int x){
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }
	
	
	bool isPresent(T x){ //sprawdza czy element znajduje się w liście
        int i = binarySearch(list, 0, size()-1, x);
        //cout<<"znaleziono na pozycji "<<i<<endl;
		return i!=-1;
	}

	Set intersect(Set s){//zwraca przecięcie zbiorów
        Set interSet;
        int currIdx = 0;
        for(int i=0; i<size(); i++){
            if(list[i]==s.list[i])
                    interSet.insert(list[i]); 
            while(list[i]<s.list[currIdx])
                currIdx++; 
            if(list[i]==s.list[i])
                    interSet.insert(list[i]);      
        }
        return interSet;        
    }

    Set difference(Set s){//zwraca różnicę zbiorów
        Set diffSet;
        for(int i=0; i<size();i++)
            diffSet.insert(list[i]);
        for(int i=0; i<diffSet.size(); i++)
            diffSet.remove(s.list[i]);
        return diffSet;    
    }

    Set unionn(Set s){//zwraca sumę zbiorów
        Set unionSet = Set();
        for(int i=0; i<size(); i++)
            unionSet.insert(list[i]);
        for(int i=0; i<s.size(); i++)
            unionSet.insert(s.list[i]);
        return unionSet;    
    }
	
    enum ResizeType {DOUBLE_SIZE, HALVE_SIZE};

    void resizeArray(ResizeType type) {
        T* newArr;

        if (type == DOUBLE_SIZE)
            currCapacity*= 2;
        else if (type == HALVE_SIZE)
            currCapacity /= 2;

        newArr = new T[currCapacity];
        for (int i = 0; i < size(); i++)
            newArr[i] = list[i];
        delete[] list;
        list = newArr;
        //cout<<"new capacity is:"<<currCapacity<<endl;
    }

	private:
    int currCapacity;
	T* list;
	int size_;

};    

#endif
