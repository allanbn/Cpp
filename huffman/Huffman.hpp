#ifndef HUFFMAN_HUFFMAN_HPP
#define HUFFMAN_HUFFMAN_HPP
#include "Heap.hpp"
#include <opencv2/opencv.hpp>
#include <unordered_map>
#include <string>
#include <fstream>


class Huffman {
private:
    Heap H;
    HeapNode *huffHeap;
public:
    Huffman();
    Huffman(Heap heap);
    ~Huffman();
    HeapNode* gethuffHeap();
    Heap getHeap();
    void mergeNodes();
    void createCode(std::unordered_map<int, std::string> *dict, HeapNode *root,  std::string str = "");
    void saveComp(cv::Mat *img, std::unordered_map<int, std::string> *dict);
    void decompress(std::string ext);
    int bin2dec(unsigned char *arr);
};


#endif
