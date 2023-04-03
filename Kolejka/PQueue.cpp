#include <iostream>
#include <string>
#include "PQueue.hpp"

int main(int argc, char const *argv[]){
    
	int liczba_operacji;
	cin >> liczba_operacji;
	
	PQueue<string> pq = PQueue<string>();
	
    char typ_operacji;
	for (int i=0;i<liczba_operacji;i++) {
		cin >> typ_operacji;
		
		if (typ_operacji == 'i') {
			string el;
            int priority;
            cin>>el>>priority;
            pq.insert(el,priority);
		} 

        else if (typ_operacji == 'm') {
            try{
			    cout<<"max: "<< pq.max().elem <<endl;
            }catch (const std::out_of_range& ex) {
                std::cerr << "queue is empty"<<endl;
            }    
		} 

        else if (typ_operacji == 'e') {
			try{
			    cout<<"extracted max: "<< pq.extractMax().elem <<endl;
            }catch (const std::out_of_range& ex) {
                std::cerr << "queue is empty"<<endl;
            }
		}

        else if (typ_operacji == 'p') { 
			pq.print();
		}
	}

}
