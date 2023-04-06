#include <iostream>
#include <string>
#include "Graph.hpp"

 using namespace std;

int main(){
    Graph graf = Graph(20);
    graf.addEdge(1,2);
    graf.addEdge(1,3);
    graf.addEdge(2,4);
    graf.addEdge(2,1);

    for(int v:graf.outConnections(2))
        cout<<v<<endl;
}
