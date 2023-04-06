#include <iostream>
#include <string>
#include <set>
#include <map>

const int CAPACITY = 20;

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {

    public:

    Graph(int capacity){
        adjMatrix = new bool*[capacity];
        for (int i = 0; i < capacity; i++) {
            adjMatrix[i] = new bool[capacity];
            for(int j=0;j<capacity;j++){
                adjMatrix[i][j]=false;
            }
        }
        size_=capacity;
    }

    void addEdge(int i, int j){
        adjMatrix[i][j]=true;
    }     // dodaje krawędź pomiędzy wierzchołkami i i j

    void removeEdge(int i, int j){
        adjMatrix[i][j]=false;
    }  // usuwa krawędź pomiędzy wierzchołkami i i j

    bool hasEdge(int i, int j){
        return adjMatrix[i][j];
    }     // sprawdza czy krawędź pomiędzy wierzchołkami i i j istnieje

    set<int> inConnections(int i){
        set<int> result;
        for(int j=0;j<size_;j++){
            if(adjMatrix[j][i]){
                result.insert(j);
            }
        }
        return result;
    }  // zwraca wszystkie wierzchołki od których istnieją połączenia do wierzchołka i

    set<int> outConnections(int i){
        set<int> result;
        for(int j=0;j<size_;j++){
            if(adjMatrix[i][j]){
                result.insert(j);
            }
        }
        return result;
    } // zwraca wszystkie wierzchołki do których prowadzą krawędzie wychodzące z i

    set<int> allConnections(int i){
        set<int> result;
        for(int j=0;j<size_;j++){
            if(adjMatrix[i][j])
                result.insert(j);
            if(adjMatrix[j][i])
                result.insert(j);
        }
        return result;
    } // zwraca wszystkie wierzchołki które są połączone z i lub z którymi i jest połączony

    private:
        int size_;
        bool **adjMatrix;
};

void DFS(Graph g, int* d, int* f){

} // zwraca czasy rozpoczęcia i zakończenia przetwarzania wierzchołków przez referencje - tablice d i f

#endif
