#include <bits/stdc++.h>

#define ll long long
#define M 1000000007

using namespace std;

int main() {
    int n;
    ll count = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        count *= 2;
        count %= M;
    }
    cout << count << endl;
    return 0;
}