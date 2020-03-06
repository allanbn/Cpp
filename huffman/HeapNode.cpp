#include "HeapNode.hpp"

HeapNode::HeapNode() {
    value = -1;
    freq = -1;
    l = nullptr;
    r = nullptr;
//    p = nullptr;
}

HeapNode::HeapNode(int v, int f) {
    value = v;
    freq = f;
    l = nullptr;
    r = nullptr;
//    p = nullptr;
}

HeapNode::HeapNode(int f, HeapNode *left, HeapNode *right) {
    value = -1;
    freq = f;
    l = left;
    r = right;
}

HeapNode::HeapNode(const HeapNode& H) {
    value = H.value;
    freq = H.freq;
    l = H.l;
    r = H.r;
}

HeapNode::~HeapNode() {
    value = -1;
    l = nullptr;
    r = nullptr;
//    p = nullptr;
}

int HeapNode::getValue() {
    return value;
}

int HeapNode::getFreq() {
    return freq;
}

HeapNode* HeapNode::getLeft() {
    return l;
}

HeapNode* HeapNode::getRight() {
    return r;
}

//HeapNode* HeapNode::getParent() {
//    return p;
//}

void HeapNode::setValue(int v) {
    value = v;
}

void HeapNode::setFreq(int v) {
    freq = v;
}

void HeapNode::setLeft(HeapNode *left) {
    l = left;
}

void HeapNode::setRight(HeapNode *right) {
    r = right;
}