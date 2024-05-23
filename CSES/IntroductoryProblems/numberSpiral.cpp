#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    ll v[n];
    for (int i = 0; i < n; i++) {
        // identificar esquina, calcular valor de la esquina
        // y trasladarse
        ll x, y;
        cin >> x >> y;
        if (x >= y) {
            ll corner = (x*x)-(x-1);
            if (x%2 == 0) {
                v[i] = corner + x-y;
            } else {
                v[i] = corner - (x-y);
            }
        } else {
            ll corner = (y*y)-(y-1);
            if (y%2 == 0) {
                v[i] = corner - (y-x);
            } else {
                v[i] = corner + y-x;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
    return 0;
}