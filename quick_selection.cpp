#include <iostream>

using namespace std;

void printArr(int* arr){
    int i;
    cout << "[";
    for (i = 0; i < 7; i++){
        cout << arr[i];
        if (i < 6) {
            cout << ", ";
        }
    }
    cout << "]";
    cout << endl;
}

//int particiona_mediana(int *v, int n) {
//    int p, e = 1, d = n-1;
//
//    if((v[0] <= v[n-1] && v[0] >= v[n/2]) || (v[0] >= v[n-1] && v[0] <= v[n/2])) {
//        p = 0;
//    }
//    else if ((v[n/2] <= v[n-1] && v[n/2] >= v[0]) || (v[n/2] >= v[n-1] && v[n/2] <= v[0])) {
//        p = n/2;
//    }
//    else {
//        p = n-1;
//    }
//    // printf("Pivo: %d\n",p);
//    int aux = v[p];
//    v[p] = v[0];
//    v[0] = aux;
//    p = 0;
//    while(e <= d) {
//        while(e < n && v[e] <= v[p]) {
//            e++;
//        }
//        while(d >= 0 && v[d] > v[p]) {
//            d--;
//        }
//        if(e < d) {
//            aux = v[e];
//            v[e] = v[d];
//            v[d] = aux;
//            e++;
//            d--;
//        }
//    }
//    aux = v[d];
//    v[d] = v[p];
//    v[p] = aux;
//    return v[d];
//}


void swap(int* arr, int i, int j) {
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

int quickSelection(int* arr, int i, int f, int k) {
    int d = i - 1;
    int p = arr[f]; // particiona_mediana(arr, f);
    int j;
    for (j = 1; j < f - 1; j++) {
        if (arr[j] <= p) {
            d++;
            swap(arr, j, d);
        }
    }
    d++;
    swap(arr, f, d);
    printArr(arr);
    if (d == k) {
        return d;
    }
    else if (k < d) {
        return quickSelection(arr, i, d-1, k);
    }
    else {
        return quickSelection(arr, d+1, f, k-d-1);
    }
}

int main() {
    int arr[50];
    int n, i, k;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    cout << arr[quickSelection(arr, 0, n-1, k)] << endl;
    return 0;
}