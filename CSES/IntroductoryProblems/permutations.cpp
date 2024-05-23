#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        // pares impares
        int v[n];
        int next = 0, m = 2;
        while (next < n && m <= n) {
            v[next++] = m;
            m += 2;
        }
        m = 1;
        while (next < n && m <= n) {
            v[next++] = m;
            m += 2;
        }
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
