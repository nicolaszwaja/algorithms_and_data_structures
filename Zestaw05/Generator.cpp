#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){

    int n, max;
    cin>>n;
    cin>>max;

    int a;
    for(int i=0; i<n; i++){
        a = rand() % max;
        cout<<a<<endl;
    }
    
    return 0;
}