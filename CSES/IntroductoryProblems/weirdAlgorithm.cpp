#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;
    while (true) {
        cout << n << " ";
        if (n == 1) break;
        if (n%2 == 0) {
            n /= 2;
        } else { 
            n = 3*n+1;
        }
    }
    cout << endl;
    return 0;
}