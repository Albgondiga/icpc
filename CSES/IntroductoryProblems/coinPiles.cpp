#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t;
    string v[t];
    for (int i = 0; i < t; i++) {
        // a-2x-y = b-x-2y = 0
        // Despejando: x = b-2y, y = (2b-a)/3
        // o x = a-2y, y = (2a-b)/3
        ll a, b;
        cin >> a >> b;
        ll y1 = 2*a-b;
        ll y2 = 2*b-a;
        if (y1 >= 0 && y2 >= 0 && y1 % 3 == 0 && y1 % 3 == 0) {
            v[i] = "YES";
        } else {
            v[i] = "NO";
        }
    }
    for (int i = 0; i < t; i++) {
        cout << v[i] << endl;
    }
    return 0;
}