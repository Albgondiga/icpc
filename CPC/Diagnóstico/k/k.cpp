#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    vector<pair<int,int>> d;
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        d.push_back(make_pair(xi,yi));
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < n; i++) {
        if (s > d[i].first) {
            s += d[i].second;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}