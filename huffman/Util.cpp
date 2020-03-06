#include "Util.h"

std::deque<HeapNode*> mkNodes(cv::Mat *img) {
    int countArr[256];
    memset(countArr, 0, 256*sizeof(int));
    std::deque<HeapNode*> nodes;
    int i, j, rows, cols;
    rows = img->rows;
    cols = img->cols;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            countArr[(int)img->at<uchar>(i, j)]++;
        }
    }
    for (i = 0; i < 256; i++) {
        if (countArr[i] > 0) nodes.push_back(new HeapNode(i, countArr[i]));
    }
    return nodes;
} 