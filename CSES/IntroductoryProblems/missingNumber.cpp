#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int v[n] = {0};
    for (int i = 0; i < n-1; i++) {
        int next;
        cin >> next;
        v[next-1] = next;
    }
    for (int i = 1; i <= n; i++) {
        if (i != v[i-1]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}