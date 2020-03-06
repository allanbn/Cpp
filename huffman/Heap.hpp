#ifndef HEAP_HPP
#define HEAP_HPP
#include "HeapNode.hpp"
#include <deque>

class HeapNode;
class Heap {
private:
    std::deque<HeapNode*> h;
public:
    Heap();
    Heap(std::deque<HeapNode*> &arr);
    ~Heap();
    void buildHeap(std::deque<HeapNode*> nodes);
    void swap(HeapNode *a, HeapNode *b);
    int indexLeft(int i);
    int indexRight(int i);
    int indexParent(int i);
    HeapNode* getMin();
    void insertNode(HeapNode *node);
    std::deque<HeapNode*> getHeap();
    int getHeapSize();
    void heapifyDown(int i);
    void heapifyUp(int i);
};
#endif