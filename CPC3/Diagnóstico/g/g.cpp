#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int N;
    ll count = 0;
    cin >> N;
    vector<int> v(N);
    map<int, int> qty;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        qty[v[i]]++;
    }
    for (int i = 0; i < N; i++) {
        count += (N - qty[v[i]]);
    }
    count /= 2;
    cout << count << endl;
    return 0;
}
