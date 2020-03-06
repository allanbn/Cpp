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
    double minimun = DBL_MAX, min1;
    register int j, k;
    for (j = i; j < f; j++) {
        for (k = j+1; k < f; k++) {
            min1 = dist(arr[j], arr[k]);
            if (min1 < minimun) minimun = min1;
        }
    }
    return minimun;
}

double closest_pair(point *arrX, point *arrY, int i, int f) {
    if ((f-i-1) <= 2) {
        return closest_pair_bf(arrX, i, f);
    }
    int m = (i+f) >> 1;
    int im = (f-i) >> 1;
    point arrYL[im+1];
    point arrYR[im+1];
    int L = 0, R = 0;
    int j;
    for (j = 0; j < (f-i); j++) {
        if (arrY[j].x <= arrX[m].x) arrYL[L++] = arrY[j];
        else arrYR[R++] = arrY[j];
    }
    double d1 = closest_pair(arrX, arrYL, i, m+1);
    double d2 = closest_pair(arrX, arrYR, m+1, f);
    double dmin = min(d1, d2);
    point nghbrs[f-i+1];
    int nsize = 0;
    for (j = 0; j < (f-i); j++) {
        if (abs(arrY[j].x - arrX[m].x) < dmin) {
            nghbrs[nsize++] = arrY[j];
        }
    }
    int k;
    for (j = 0; j < nsize; j++) {
        for (k = j + 1; k < nsize; k++) {
            if (abs(nghbrs[k].y - nghbrs[j].y) > dmin) break;
            double min_aux = dist(nghbrs[j], nghbrs[k]);
            if (min_aux < dmin) dmin = min_aux;
        }
    }
    return dmin;
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
    clock_t ti, tf;
    point pX[10001];
    point pY[10001];
    point xy;
    cin >> in;
    while (in != 0) {
        int i;
        for (i = 0; i < in; i++) {
            cin >> xy.x >> xy.y;
            pX[i] = xy;
            pY[i] = xy;
        }
        qsort(&pX, in, sizeof(point), cmpX);
        qsort(&pY, in, sizeof(point), cmpY);
        double mindist;
        int k;
        for (k = 0; k < 100; k++){
            ti = clock();
            mindist = closest_pair(pX, pY, 0, in);
            tf = clock();
            double t1 = (double)(tf-ti) / CLOCKS_PER_SEC;
            if (mindist < 10000.0000) {
                printf("%.4lf\n", mindist);
            }
            else cout << "INFINITY" << endl;
            ti = clock();
            mindist = closest_pair(pX, 0, in);
            tf = clock();
            double t2 = (double)(tf-ti) / CLOCKS_PER_SEC;
            if (mindist < 10000.0000) {
                printf("%.4lf\n", mindist);
            }
            else cout << "INFINITY" << endl;
            cout << "NLGN: "<<t1 << "s\n" "NLG^2N: " << t2 << "s\n";

        }
        cin >> in;
    }
    return 0;
}