#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    ll div[n] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= sqrt(x); j++) {
            if (x % j == 0) { 
                if (x/j != j) {
                    div[i] += 2;
                } else{
                    div[i] += 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << div[i] << endl;
    }
    return 0;
}
