#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        v.push_back(make_pair(a,d));
    }
    sort(v.begin(), v.end());
    ll time = 0;
    ll reward = 0;
    for (auto i:v) {
        time += i.first;
        reward += (i.second - time);
    }
    cout << reward << endl;
    return 0;
}
