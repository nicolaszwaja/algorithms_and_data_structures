#include "LinkedList.hpp"
using namespace std;

template <class K, class V>
class Dict {

	using Pair = std::pair<K, V>;

    public:
	Dict () { 
		//maxBuckets=100;
	}
	
	void clear () { // Czyści słownik
		for(int i=0; i<maxBuckets; i++){
			dictionary[i].clear();
		}
	}
	
	bool insert (const Pair& p) { // Dodaje parę klucz-wartość do słownika
		
		int bucketNumber = Hash(p.first);

        bool present = find(p.first);
		
        if(!present){
            dictionary[bucketNumber].push_back(p);
			size_++;
			return true;
        }
		else{
			erase(p.first);
            insert(p);
            return false;
		}

	}
	
	bool find (const K& k) { // Sprawdza czy słownik zawiera klucz
		
		int bucketNumber = Hash(k);
		
		for (typename List<Pair>::Iterator i = dictionary[bucketNumber].begin(); i != dictionary[bucketNumber].end(); i++) {   
			if (k == i->value.first)
				return true;
		}
		return false;
	}
	
	V& operator[] (const K& k) { // Zwraca wartość dla klucza
		
		int bucketNumber = Hash(k);
		
		for (typename List<Pair>::Iterator i = dictionary[bucketNumber].begin(); i != dictionary[bucketNumber].end(); i++) {
			if (k == i->value.first)
				return i->value.second;
		}
		
		insert (make_pair(k,""));
        for (typename List<Pair>::Iterator i = dictionary[bucketNumber].begin(); i != dictionary[bucketNumber].end(); i++) {
			if (k == i->value.first)
				return i->value.second;
		}
		
	}
	
	bool erase (const K& k) { // Usuwa parę o danym kluczu
		
		int bucketNumber = Hash(k);
		
        int idx=0;
		for (typename List<Pair>::Iterator i = dictionary[bucketNumber].begin(); i != dictionary[bucketNumber].end(); i++) {
			if (k == i->value.first) {
				dictionary[bucketNumber].erase(idx);
				size_--;
				return true;
			}
            else
                idx++;
		}
		return false;
	}
	
	int size () { // Zwraca liczbę par
		return size_;
	}
	
	bool empty () { // Sprawdza czy słownik jest pusty
		return size==0;
	}

    int shortestList(){
        int a = dictionary[0].size();
        for (int i=1; i<maxBuckets; i++) {
			if (dictionary[i].size() < min)
				min = dictionary[i].size();
		}
        return a;
    }

    int longestList(){
        int a = dictionary[0].size();
		for (int i=1; i<maxBuckets; i++) {
			if (dictionary[i].size() > max)
				max = dictionary[i].size();
		}
        return a;
    }
	
	void buckets () { // Wypisuje informację o słowniku
		
		cout<<"# "<<size()<<" "<<maxBuckets<<" "<<shortestList()<<" "<<longestList()<<endl;

	}

    private:
	int size_ = 0;
	List<Pair> dictionary[100]; //tablica stu list()=>sto możliwych wyników funkcji hash
    int maxBuckets=100;
	
	unsigned int Hash (string key) {
        
        const int size = key.size();
        int t = 1;
        unsigned int hash = 0;
        for(int i=0;i<size;i++){
            hash = hash + key[i]*t;
            t=t*size;
        }

		return hash % maxBuckets;
	}
	
};