#include "Huffman.hpp"
#include <bits/stdc++.h>

Huffman::Huffman() {

}

Huffman::Huffman(Heap heap) {
    H = heap;
    mergeNodes();
}

Huffman::~Huffman() {

}

HeapNode* Huffman::gethuffHeap() {
    return huffHeap;
}

Heap Huffman::getHeap() {
    return H;
}

void Huffman::mergeNodes() {
   // 0 1 2
    while (H.getHeapSize()-1) {
//        printf("%d\n", H.getHeapSize()-1);
        HeapNode *node1 = H.getMin(); //&tmp.front();
        //tmp.pop_front();
        HeapNode *node2 = H.getMin();//&/tmp.front();
        //tmp.pop_front();
        if (node1->getFreq() > node2->getFreq()) {
            H.insertNode(new HeapNode((node1->getFreq() + node2->getFreq()), node2, node1));

        }
        else {
            H.insertNode(new HeapNode((node1->getFreq() + node2->getFreq()), node1, node2));
        }
        //insertHuffNode(nNode);

    }

//    printf("%d\n", H.getHeapSize()-1);
//    HeapNode* raiz = H.getMin();
//    H.insertNode(raiz);
    huffHeap = H.getMin();
//    H.heapifyUp(H.getHeapSize()-1);
}

//void Huffman::walkTree(HeapNode* root) {
//    HeapNode* aux = root;
//    if (aux == nullptr) {
//        return;
//    }
//    else if (aux->getValue() == -1) {
//        printf("%d %d\n", aux->getValue(), aux->getFreq());
//        walkTree(aux->getLeft());
//        walkTree(aux->getRight());Huffman::
//    }
//    else {
//        printf("%d %d\n", aux->getValue(), aux->getFreq());
//        walkTree(aux->getLeft());
//        walkTree(aux->getRight());
//    }
//}

void Huffman::createCode(std::unordered_map<int, std::string> *dict, HeapNode *root,  std::string str) {
    HeapNode *aux = root;
    if (aux->getLeft() == nullptr && aux->getLeft() == nullptr) {
        dict->insert(std::pair<int, std::string>(aux->getValue(), str));
    }
    else {
        createCode(dict, aux->getLeft(), str + "0");
        createCode(dict, aux->getRight(), str + "1");
    }
}

int Huffman::bin2dec(unsigned char *arr) {
    unsigned char *n = arr;
    int decimal = 0, base = 1, i;

    for (i = 7; i > -1; i--) {
        if (n[i] == '1') decimal += base;
        base = base * 2;
    }
    return decimal;
}
// 000000 != 8
// 000001
// 00000000
// 0001 + ?
void Huffman::saveComp(cv::Mat *img, std::unordered_map<int, std::string> *dict) {
    int i, j, rows, cols;
    rows = img->rows;
    cols = img->cols;
    std::string bitstream;
    std::ofstream file("Compact.huff", std::ios::out | std::ios::binary);
    // file << dict << '\t'; // isso não salva o objeto
    // file << huffHeap << '\t'; // isso não salva o objeto
    // file << rows << '\t';
    // file << cols << '\t';
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
//            bitcount = 0;
            bitstream += dict->at((int)img->at<uchar>(i, j));
//            while (bitcount++ != 7) {
//                arr[bitcount] = (char) code[bitcount];
//            }
        }
    }
    // printf("Fez a string de bits\n");
    // while (bitstream.size() % 8 != 0) {
    //     bitstream += "0";
    // }
    // printf("Fez o padding\n");
    int len = bitstream.size();
    unsigned char arr[(len/8)+1]; // buffer
    memset(arr, 0, (len/8)+1);
    // printf("Array limpo\n");
    int index = 0, bitcount = 0;
    // printf("STRING SIZE: %d\n", bitstream.size());
    for (i = 0; i < len; i++) {
//        printf("indice da string: %d\n", i);
//        printf("indice buffer: %d\n", index);
        arr[index] = (arr[index] << 1) | ((int)(bitstream[i]-'0'));
        bitcount++;
        if (bitcount == 8) {
            bitcount = 0;
            index++;
        }
        //printf("%d\n", res);
    }
    // printf("Fez o bit a bit\n");
    // for (i = 0; i < index; i++) {
    //     for (j = 7; j > -1; j--) {
    //         file << (int)((arr[i] >> j) & 1);
    //     }
    // }
    for (i = 0; i < index; i++) {
        file << (arr[i]);
    }
    // printf("top de vdd\n");
    file.close();
}

void Huffman::decompress(std::string ext) {
	std::ifstream in_file("Compact.huff", std::ios::in | std::ios::binary);
    std::vector<int> values;
	HeapNode *node = huffHeap;
    char inchar;
    unsigned char unchar, sign;
    int i;
    std::string nome = "imagemrestaurada."; 
    nome += ext;
    std::ofstream out_file(nome, std::ios::out);
    while (in_file.get(inchar)) {
        unchar = (unsigned char) inchar;
        sign = 0x80;
        for (i = 0; i < 8; i++) {
            if (unchar & sign) {
                node = node->getRight();
            }
            else {
                node = node->getLeft();
            }
            if (node->getLeft() == nullptr && node->getRight() == nullptr) {
                out_file << node->getValue();
                node = huffHeap;
            }
            sign = sign >> 1;
        }
    }
    // for (i = 0; i < values.size(); i ++) {
    //     std::cout << values.at(i) << '\n';
    // }
    in_file.close();
    out_file.close();
}
