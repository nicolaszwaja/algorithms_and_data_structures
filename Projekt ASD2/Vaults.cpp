#include <iostream>
#include <string>
#include "Graph.hpp"

int getVaultsNum(Graph graph){
    vector<int> order = graph.topologicalSort();
    int result = graph.findCompNum(order);
    return result-1;
}

int main(int argc, char const *argv[]) {
    
	int liczba_sejfow = 0;
	cin >> liczba_sejfow;
	
	Graph g = Graph(liczba_sejfow+1);

    int klucz;
    for(int i=1; i<=liczba_sejfow; i++){
        cin >> klucz;
        g.addEdge(klucz,i);
        //cout<< "dodano do grafu" <<endl;
    }

    cout<< "minimalna liczb rozbitych sejfow:";
	cout<< getVaultsNum(g)<<endl;


}
