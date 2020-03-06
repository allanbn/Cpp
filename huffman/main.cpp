#include "Heap.hpp"
#include "HeapNode.hpp"
#include "Huffman.hpp"
#include "Util.h"
#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>


int main() {
    cv::Mat img;
    std::string nome = "/home/allan/Documents/Prog/Cpp/huffman/img1.tif"; // inserir aqui o caminho para imagem com o nome dela.
    std::size_t dot = nome.find_last_of(".");
    std::string ext = nome.substr(dot+1, nome.size());
    img = cv::imread(nome, cv::IMREAD_GRAYSCALE);
    std::deque<HeapNode*> nodes = mkNodes(&img); // Calcula as frequencias e cria os nodes
    int i;
    Heap H; // classe Heap
    H.buildHeap(nodes); // Criação do Heap
    nodes = H.getHeap();
    Huffman huff(H);
    std::unordered_map<int, std::string> *bitMap = new std::unordered_map<int, std::string>();
    huff.createCode(bitMap, huff.gethuffHeap());
    std::unordered_map<int, std::string>::iterator it;
    for (it = bitMap->begin(); it != bitMap->end(); it++) {
        std::cout << it->first << ':' << it->second << '\n';
    }
    huff.saveComp(&img, bitMap);
    char n;
    std::cout << "Digite alguma coisa e dê enter para seguir para descompactação.";
    std::cin >> n;
    huff.decompress(ext);
    return 0;
}
