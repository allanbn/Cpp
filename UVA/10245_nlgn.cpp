#include <bits/stdc++.h>

using namespace std;

typedef struct {
    double x;
    double y;
}point;

double dist(point a, point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) +
                (a.y - b.y)*(a.y - b.y));
}

int cmpY(const void *a, const void *b) {
    point *pa = (point*) a;
    point *pb = (point*) b;
    return (pa->y - pb->y);
}

int cmpX(const void *a, const void *b) {
    point *pa = (point*) a;
    point *pb = (point*) b;
    return (pa->x - pb->x);
}

double closest_pair_bf(point *arr, int i, int f) {
    double true_min = DBL_MAX;
    int j, k;
    for (j = i; j < f; j++) {
        for (k = j+1; k < f; k++) {
            double min_aux = dist(arr[k], arr[j]);
            if (min_aux < true_min) true_min = min_aux;
        }
    }
    return true_min;
}

double closest_pair(point *arrX, point *arrY, int i, int f) {
    int n = (f-i);
    if ((n-1) <= 2) return closest_pair_bf(arrX, i, f);
    int m = (i+f) >> 1;
    int im = n >> 1;
    point arrYL[im+1];
    point arrYR[im+1];
    int L = 0, R = 0;
    int j;
    for (j = 0; j < n; j++) {
        if (arrY[j].x <= arrX[m].x) arrYL[L++] = arrY[j];
        else arrYR[R++] = arrY[j];
    }
    double d1 = closest_pair(arrX, arrYL, i, m+1);
    double d2 = closest_pair(arrX, arrYR, m+1, f);
    double dmin = min(d1, d2);
    point arrY_aux[n+1];
    int nsize = 0;
    for (j = 0; j < n; j++) {
        if (abs(arrY[j].x - arrX[m].x) < dmin) {
            arrY_aux[nsize++] = arrY[j];
        }
    }
    int k;
    for (j = 0; j < nsize; j++) {
        for (k = j + 1; k < nsize; k++) {
            if (abs(arrY_aux[k].y - arrY_aux[j].y) > dmin) break;
            double min_aux = dist(arrY_aux[k], arrY_aux[j]);
            if (min_aux < dmin) dmin = min_aux;
        }
    }
    return dmin;
}

int main() {
    int in;
    point pX[10001];
    point pY[10001];
    cin >> in;
    while (in != 0) {
        int i;
        for (i = 0; i < in; i++) {
            cin >> pX[i].x >> pX[i].y;
        }
        memcpy(&pY, &pX, sizeof(pX));
        qsort(&pX, in, sizeof(point), cmpX);
        qsort(&pY, in, sizeof(point), cmpY);
        double mindist = closest_pair(pX, pY, 0, in);
        if (mindist < 10000.0000) {
            cout << fixed << setprecision(4) << mindist << "\n";
        }
        else cout << "INFINITY" << "\n";
        cin >> in;
    }
    return 0;
}