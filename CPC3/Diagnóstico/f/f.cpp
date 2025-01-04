#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q;
    cin >> N;

    int v[N];
    for (int k = 0; k < N; k++) {
        cin >> v[k];
    }

    cin >> Q;
    int i, j;
    for (int k = 0; k < Q; k++) {
        cin >> i >> j;
        int sum = 0;
        for (int l = i; l <= j; l++) {
            sum += v[l];
        }
        cout << sum << "\n";
    }
    return 0;
}
