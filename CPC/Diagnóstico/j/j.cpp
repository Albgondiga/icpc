#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        ll x;
        cin >> x;
        // -x es x en complemento a 2
        ll firstBit = (x & -x);
        if (x == firstBit) {
            // x es potencia de 2
            if (x == 1) {
                cout << 3 << "\n";
            } else { // primer 1 mas el ultimo bit
                cout << firstBit+1 << "\n";
            }
        } else {
            cout << firstBit << "\n";
        }
    }
    return 0;
}