
#include <iostream>
#include <stdlib.h>
#include "BinaryTree.hpp"

using namespace std;

int main(int argc, char *argv[]){

    int liczba_liczb = 5;
    int liczba;

    BinaryTree BST;

    cin >> liczba_liczb;

    for(int i=0;i<liczba_liczb;i++){
        cin >> liczba; 
        BST.insert(liczba); 
        //cout<<"ok"<<endl;  
    }

    cout<<endl;
    cout<<BST.size()<<" "<<BST.depth()<<" "<<BST.minimum()<<" "<<BST.maximum()<<endl;

    /*wartości w kolejności preorder*/
    BST.preorder(BST.root());
    cout<<endl;

    /*search dla wartości 1-9*/
    for(int j=1; j<10; j++){
        if(BST.searchRecursive(j)==nullptr)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;    
    }
}