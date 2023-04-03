#include <iostream>
#include <string>

const int CAPACITY = 100;

using namespace std;

#ifndef PQUEUE_H
#define PQUEUE_H

template<class T>
class PQueue {

    public:

    struct QueueElem{
        int priority;
        T elem;
    };

    PQueue(){
        currCapacity = 4;
        size_ = 0;
        heap = new QueueElem[currCapacity];
    }

    void insert(T obj,int pr){
        if(size()+1>currCapacity){
            //cout<<size()+1<<"<"<<currCapacity<<endl;
            resizeArray(DOUBLE_SIZE);
        }    
        QueueElem newEl = {pr, obj};
        heap[size()] = newEl;
        size_++;
        heapify(size()-1, UP);
    }

    QueueElem max(){
        if(empty())
            throw std::out_of_range ("queue is empty");
        return heap[0];    
    }   

    QueueElem extractMax(){
        if(empty())
            throw std::out_of_range ("queue is empty");
        if(size()-1<currCapacity/4){
            //cout<<size()-1<<">"<<currCapacity/2<<endl;
            resizeArray(HALVE_SIZE);
        }
        QueueElem max = heap[0];
        heap[0] = heap[size()-1];
        size_--;
        heapify(0, DOWN);
        return max;  
    }

    int size(){
        return size_;
    } 

    bool empty(){
        return size_==0;
    }

    void print(){
        for(int i=0;i<size();i++){
            cout<<i+1<<": "<<heap[i].elem<<",   "<<heap[i].priority<<endl;
        }
        cout<<endl;
    }

    enum ResizeType {DOUBLE_SIZE, HALVE_SIZE};

    void resizeArray(ResizeType type) {
        QueueElem* newHeap;

        if (type == DOUBLE_SIZE)
            currCapacity*= 2;
        else if (type == HALVE_SIZE)
            currCapacity /= 2;

        newHeap = new QueueElem[currCapacity];
        for (int i = 0; i < size(); i++)
            newHeap[i] = heap[i];
        delete[] heap;
        heap = newHeap;
        //cout<<"new capacity is:"<<currCapacity<<endl;

    }

    enum heapDir {UP, DOWN};

    void heapify(int idx, heapDir dir){
        if(dir==UP){
            if(idx == 0)
                return;
            int parent = (idx - 1) / 2;
            if (heap[idx].priority > heap[parent].priority) {
                swap(heap[idx], heap[parent]);
                heapify(parent, UP);
            }
        }
        else if(dir==DOWN){
            int leftChild = 2*idx+1;
            int rightChild = 2*idx+2;
            int largest = idx;

            if (leftChild < size_ && heap[leftChild].priority > heap[largest].priority)
                largest = leftChild;
            if (rightChild < size_ && heap[rightChild].priority > heap[largest].priority)
                largest = rightChild;
            if (largest != idx){
                swap(heap[idx], heap[largest]);
                heapify(largest, DOWN);
            }    
        }
    }

    private:
        int currCapacity;
        int size_;
        QueueElem* heap;
};    

#endif
