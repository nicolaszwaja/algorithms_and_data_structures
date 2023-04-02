#include <stdio.h>
#include <string>
#include <iostream>
#include "ArrayStack.hpp"

using namespace std;

int main (int argc, char *argv[]) {

	string wejscie;
	string wyjscie="";
    int mode=0;
    int znak=0;
    Stack stos_znaki=Stack(20);

    getline(cin, wejscie);

     for (char n : wejscie){

        if(n=='1'||n=='2'||n=='3'||n=='4'||n=='5'||n=='6'||n=='7'||n=='8'||n=='9'||n=='0'){

            wyjscie=wyjscie+n;
            mode=1;
        }

        if(n=='+'){
            stos_znaki.push(11);
        }

        if(n=='-'){
            stos_znaki.push(22);
        }

        if(n=='*'){
            stos_znaki.push(33);
        }

        if(n=='/'){
            stos_znaki.push(44);
        }

         if(n==')'){

            int znak=stos_znaki.pop();

            if(znak==11){
                wyjscie=wyjscie+"+";
            }
            else if(znak==22){
                wyjscie=wyjscie+"-";
            }
             else if(znak==33){
                 wyjscie=wyjscie+"*";
            }
             else if(znak==44){
                wyjscie=wyjscie+"/";
            }

      	 wyjscie=wyjscie+" ";
        }
        if(n!='1'&&n!='2'&&n!='3'&&n!='4'&&n!='5'&&n!='6'&&n!='7'&&n!='8'&&n!='9'&&n!='0'&&mode==1){
            wyjscie=wyjscie+" ";
            mode=0;
        }

    } 

    wyjscie.erase(wyjscie.size()-1,1);
    cout <<wyjscie<< endl;

}   
