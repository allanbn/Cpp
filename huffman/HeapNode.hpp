#ifndef HEAP_NODE_HPP
#define HEAP_NODE_HPP

class HeapNode {
private:
    int value;
    int freq;
    HeapNode *l; // left
    HeapNode *r; // right
    friend class Heap;
public:
    HeapNode();
    HeapNode(int v, int f);
    HeapNode(int f, HeapNode *left, HeapNode *right);
    HeapNode(const HeapNode& H);
    ~HeapNode();
    int getValue();
    int getFreq();
    HeapNode* getLeft();
    HeapNode* getRight();
    HeapNode* getParent();
    void setValue(int v);
    void setFreq(int v);
    void setLeft(HeapNode *left);
    void setRight(HeapNode *right);
};
#endif