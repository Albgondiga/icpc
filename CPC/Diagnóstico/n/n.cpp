#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define debug 0
#define ifd if (debug)

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> constraints(n+1,0);
    constraints[0]=-1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        constraints[a]++; constraints[b]++;
    }
    // m < n/2 => 2m < n => hay al menos una ciudad 
    // sin restricciones
    int center;
    for (int i = 1; i <= n; i++) {
        if (constraints[i] == 0) {
            center = i;
            break;
        }
    }
    ifd cout << "center = " << center << endl;
    cout << n-1 << "\n";
    for (int i = 1; i <= n; i++) {
        if (i != center)
            cout << center << " " << i << "\n";
    }
    return 0;
}
