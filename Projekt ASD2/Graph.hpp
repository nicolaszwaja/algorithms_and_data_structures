#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <map>

const int CAPACITY = 20;

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {

    public:

    Graph(int capacity){
        size_ = capacity;
        adjMatrix = new bool*[capacity];
        for (int i=0;i<capacity;i++) {
            adjMatrix[i] = new bool[capacity];
            for(int j=0;j<capacity;j++){
                adjMatrix[i][j]=false;
            }
        }
    }

    ~Graph(){
        for (int i = 0;i<size_;i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }

    void addEdge(int i, int j){
        if(i>size_ || i<0)
            throw std::out_of_range("first vertex incorrect");
        if(j>size_ || j<0)
            throw std::out_of_range("second vertex incorrect");

        adjMatrix[i][j]=true;
    } // dodaje krawędź pomiędzy wierzchołkami i i j

    void removeEdge(int i, int j){
        if(i>size_ || i<0)
            throw std::out_of_range("first vertex incorrect");
        if(j>size_ || j<0)
            throw std::out_of_range("second vertex incorrect");
        adjMatrix[i][j]=false;
    }  // usuwa krawędź pomiędzy wierzchołkami i i j

    bool hasEdge(int i, int j){
        if(i>size_ || i<0){
            throw std::out_of_range("first vertex incorrect");
            return false;
        }
        if(j>size_ || j<0){
            throw std::out_of_range("second vertex incorrect");
            return false;
        }
        return adjMatrix[i][j];
    } // sprawdza czy krawędź pomiędzy wierzchołkami i i j istnieje

    set<int> inConnections(int i){
         if(i>size_ || i<0)
            throw std::out_of_range("vertex incorrect");
        set<int> result;
        for(int j=0;j<size_;j++){
            if(adjMatrix[j][i]){
                result.insert(j);
            }
        }
        return result;
    } // zwraca wszystkie wierzchołki od których istnieją połączenia do wierzchołka i

    set<int> outConnections(int i){
        if(i>size_ || i<0)
            throw std::out_of_range("vertex incorrect");
        set<int> result;
        for(int j=0;j<size_;j++){
            if(hasEdge(i,j)){
                result.insert(j);
            }
        }
        return result;
    } //zwraca wszystkie wierzchołki do których prowadzą krawędzie wychodzące z i

    set<int> allConnections(int i){
        if(i>size_ || i<0)
            throw std::out_of_range("vertex incorrect");
        set<int> result;
        for(int j=0;j<size_;j++){
            if(adjMatrix[i][j])
                result.insert(j);
            if(adjMatrix[j][i])
                result.insert(i);
        }
        return result;
    } //zwraca wszystkie wierzchołki które są połączone z i lub z którymi i jest połączony

    int size(){
        return size_;
    }

    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;

        set<int> connections = outConnections(v);
        for(int u:connections){
            if (!visited[u]) {
                //cout<<u<<" ";
                dfs(u, visited);
            }
        }
    }

    int findCompNum(vector<int> order) {   
        vector<bool> visited(size_, false);

        int compNum = 0;
        int curr = 0;
        for (int i=0; i<size_ ; i++) {
            curr = order.at(i);
            if (!visited[curr]) {
                dfs(curr, visited);
                compNum++;  // Inkrementuj licznik po zakończeniu przeszukiwania spójnej składowej
            }
        }
        return compNum;
    } //zwraca liczbę connected components grafu

    void topologicalSortDFS(int v, vector<bool>& visited, stack<int>& stk) {
        visited[v] = true;
        set<int> connections = outConnections(v);
        for (int u:connections) {
            if (!visited[u]) {
                topologicalSortDFS(u, visited, stk);
            }
        }
        stk.push(v);  // Dodaj wierzchołek na stos po zakończeniu przeszukiwania DFS
    }

    vector<int> topologicalSort() {
        vector<int> result;
        vector<bool> visited(size_, false);
        stack<int> stk;

        for(int i=0; i<size_; i++){
            if (!visited[i])
                topologicalSortDFS(i, visited, stk);
        }
        while(!stk.empty()){ 
            result.push_back(stk.top());
            stk.pop();
        }   //odwrócenie kolejności wierzchołków
        return result;
    }

    private:
        int size_;
        bool **adjMatrix;
};

#endif
