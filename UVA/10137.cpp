#include <bits/stdc++.h>

using namespace std;

double stu[1001];

int main() {
    
    int n;
    while (scanf("%d", &n) && n > 0) {
        int i;
        double som = 0, ansPos = 0, ansNeg = 0;
        for (i = 0; i < n; i++) {
            scanf("%lf", &stu[i]);
            som += stu[i];
        }
        double med = som/n;
        for (i = 0; i < n; i++) {
            double sub = (double) (long)((stu[i]-med) * 100.0) / 100.0;
            if (sub > 0)  ansPos += sub;
            else ansNeg += sub;
        }
        double ans;
        if ((-1*ansNeg) > ansPos) ans = (-1*ansNeg);
        else ans = ansPos;
        printf("$%.2lf\n", ans);
    }
    return 0;
}