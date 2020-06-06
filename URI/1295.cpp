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

int cmpY (const void *a, const void *b) {
    point *pa = (point*) a;
    point *pb = (point*) b;
    return (pa->y - pb->y);
}

int cmpX (const void *a, const void *b) {
    point *pa = (point*) a;
    point *pb = (point*) b;
    return (pa->x - pb->x);
}

double closest_pair_bf (point* arr, int i, int f) {
    double true_min = DBL_MAX, min_aux;
    register int j, k;
    for (j = i; j < f; j++) {
        for (k = j+1; k < f; k++) {
            min_aux = dist(arr[j], arr[k]);
            if (min_aux < true_min) true_min = min_aux;
        }
    }
    return true_min;
}

double closest_pair(point *arrX, int i, int f) {
    if ((f-i-1) <= 2) {
        return closest_pair_bf(arrX, i, f);
    }
    int m =  (i+f) >> 1;
    double d1 = closest_pair(arrX, i, m+1);
    double d2 = closest_pair(arrX, m+1, f);
    double dmin = min(d1, d2);
    point arrY[10001];
    int ysize = 0;
    int j;
    for (j = i; j < f; j++) {
        if (abs(arrX[j].x - arrX[m].x) < dmin) {
            arrY[ysize++] = arrX[j];
        }
    }
    qsort(&arrY, ysize, sizeof(point), cmpY);
    int k;
    for (j = 0; j < ysize; j++) {
        for (k = j + 1; k < ysize; k++) {
            if (abs(arrY[j].y - arrY[k].y) > dmin) break;
            double v = dist(arrY[j], arrY[k]);
            if (v < dmin) dmin = v;
        }
    }
    return dmin;
}

int main() {
    int in;
    point pX[10001];
    point xy;
    cin >> in;
    while (in != 0) {
        for (register int i = 0; i < in; i++) {
            cin >> xy.x >> xy.y;
            pX[i] = xy;
        }
        qsort(&pX, in, sizeof(point), cmpX);
        double mindist = closest_pair(pX, 0, in);
        if (mindist < 10000.0000) {
            printf("%.4lf\n", mindist);
        }
        else cout << "INFINITY" << endl;
        cin >> in;
    }
    return 0;
}