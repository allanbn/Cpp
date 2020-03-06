#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;
// using namespace listaEncC;

typedef struct {
    double x;
    double y;
}ponto;

/* Tentativa frustrada de fazer tudo na mão.
* Maldita conversão de ponteiro. */
// typedef ponto* Pponto;

// typedef struct list {
//     int pos= -1;
//     ponto stPonto;
//     struct list* proxPonto;
// }listaEnc;
// typedef list* Plist;

// class listaEncC {
//     int tam;
//     Plist a;
//     Plist aUltima;
//     public:
//     listaEncC() {
//         tam = 0;
//         a = NULL;
//         aUltima = a;
//     }
//     void append(ponto *p) {
//         tam++;
//         Plist aux = (Plist)malloc(sizeof(Plist));
//         if (a == NULL) {
//             aux->stPonto = (*p);
//             aux->proxPonto = NULL;
//             aux->pos++;
//             a = aux;
//             aUltima = a;
//         }
//         else {
//             aux->stPonto = (*p);
//             aux->proxPonto = NULL;
//             aux->pos++;
//             aUltima->proxPonto = aux;
//             aUltima = aUltima->proxPonto;
//         }
//     }
//     void printList() {
//         Plist aux = a;
//         cout << "A lista tem os seguintes pontos:" << endl;
//         while (aux != NULL) {
//             cout << "X: " << aux->stPonto.x;
//             cout << " ";
//             cout << "Y: " << aux->stPonto.y << endl;
//             aux = aux->proxPonto;
//         }
//     }
//     ponto get(int i) {
//         Plist aux = a;
//         while (aux != NULL || aux->pos != i) {
//             aux = aux->proxPonto;
//         }
//         ponto p = aux->stPonto;
//         return p;
//     }
//     void clear() {
//         Plist aux;
//         tam = 0;
//         while (aux != NULL) {
//             aux = a;
//             a = a->proxPonto;
//             free(aux);
//         }
//         a = NULL;
//     }
//     Plist getList(){
//         return a;
//     }
// };

double dist(ponto a, ponto b) {
    return sqrt((a.x - b.x)*(a.x - b.x) +
                (a.y - b.y)*(a.y - b.y));
}

int cmpY (const void *a, const void *b) {
    ponto *pa = (ponto*) a;
    ponto *pb = (ponto*) b;
    return (pa->y - pb->y);
}

int cmpX (const void *a, const void *b) {
    ponto *pa = (ponto*) a;
    ponto *pb = (ponto*) b;
    return (pa->x - pb->x);
}

double closest_pair_bf (ponto* arr, int i, int f) {
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

double closest_pair(ponto* arrX, int i, int f) {
    register int k, j;
    if ((f-i) <= 2) {
        return closest_pair_bf(arrX, i, f);
    }
    int m =  (i+f)/2;
    double d1 = closest_pair(arrX, i, m + 1);
    double d2 = closest_pair(arrX, m + 1, f);
    double dmin = min(d1, d2);
    //vector<ponto> arrY(20001);
    ponto arrY[10001];
    int ayi = 0;
    for (k = i; k < f; k++) {
        if (abs(arrX[k].x - arrX[m].x) < dmin) {
         //   arrY.push_back(arrX[k]);
            arrY[ayi++] = arrX[k];
        }
    }
    int size = ayi;//arrY.size();
    qsort(&arrY, size, sizeof(ponto), cmpY);
    for (k = 0; k < size; k++) {
        for (j = k + 1; j < size; j++) {
            if (abs(arrY[k].y - arrY[j].y) > dmin) {
                break;
            }
            double v = dist(arrY[k], arrY[j]);
            if (v < dmin) dmin = v;
        }
    }
    return dmin;
}

int main() {
    int in;
    ponto pX[10001];
    ponto xy;
    cin >> in;
    while (in != 0) {
       //         cout << pX.size() << " - " << pX.capacity() << endl;
        for (register int i = 0; i < in; i++) {
            cin >> xy.x >> xy.y;
            pX[i] = xy;
        }
        qsort(&pX, in, sizeof(ponto), cmpX);
        double mindist = closest_pair(pX, 0, in);
        if (mindist < 10000.0000) {
            printf("%.4lf\n", mindist);
        }
        else cout << "INFINITY" << endl;
        cin >> in;
     //   cout << pX.size() << "  " << pX.capacity() << endl;
    }
    return 0;
}
