#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n = 0;
    ll count = 0;
    cin >> n;
    ll v[n-1];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++) {
        ll diff = v[i-1]-v[i];
        if (diff > 0) {
            count += diff;
            v[i] += diff;
        }
    } 
    cout << endl;
    cout << count << endl;
    return 0;
}