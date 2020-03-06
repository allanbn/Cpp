#include "Heap.hpp"
#include <bits/stdc++.h>
Heap::Heap() {

}

Heap::Heap(std::deque<HeapNode*> &arr) {
    h = arr;
    buildHeap(arr);
}

Heap::~Heap(){

}

void Heap::buildHeap(std::deque<HeapNode*> nodes) {
    int i;
    for (i = nodes.size() - 1; i > -1; i--) {
        insertNode(nodes[i]);
    }
}

void Heap::insertNode(HeapNode *node) {
    h.push_back(node);
    heapifyUp(h.size()-1);
//    int i = h.size()-1;
//    while(i > 0 && h[indexParent(i-1)]->getFreq() > h[i]->getFreq()) {
//        swap(h[i], h[indexParent(i-1)]);
//        i = indexParent(i-1);
//    }
}

std::deque<HeapNode*> Heap::getHeap() {
    return h;
}

int Heap::getHeapSize() {
    return h.size();
}

void Heap::swap(HeapNode *a, HeapNode *b) {
    HeapNode tmp = *a;
    *a = *b;
    *b = tmp;

}

int Heap::indexLeft(int i) {
    return (i << 1);
}

int Heap::indexRight(int i) {
    return ((i << 1) | 1);
}

int Heap::indexParent(int i) {
    return (i >> 1);
}

void Heap::heapifyDown(int i) {
//    printf("heapifyDown\n");
    int left = indexLeft(i);
    int right = indexRight(i);
    int smallest = i;
    if (left < h.size() && h[left]->getFreq() < h[smallest]->getFreq()) {
        smallest = left;
    }
    if (right < h.size() && h[right]->getFreq() < h[smallest]->getFreq()) {
        smallest = right;
    }
    if (smallest != i) {
        swap(h[i], h[smallest]);
        heapifyDown(smallest);
    }
}

void Heap::heapifyUp(int i) {
    if (i && h[indexParent(i)]->getFreq() > h[i]->getFreq()) {
        swap(h[i], h[indexParent(i)]);
        heapifyUp(indexParent(i));
    }
}

HeapNode* Heap::getMin() {
    swap(h[0], h[h.size()-1]);
    HeapNode *tmp = h.back();
    h.pop_back();
    heapifyDown(0);
    return tmp;
    //extrai o ultimo
    //executa heapifyDown(0)
    //retorna elemento extraido
}
