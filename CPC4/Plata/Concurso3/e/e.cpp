#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

// https://codeforces.com/problemset/problem/808/D
// (Lo cambiaron en media competencia)

const int N = 1e5;
int n; 
vector<ll> v(N), s(N,0), diff(N);

bool valid(int i) {
    ll a = v[i];

    // Moverlo hacia la derecha
    int l = i+1, r = n;
    while (l <= r) {
        int m = (l+r)/2;
        if (a == diff[m]) {
            return true;
        }
        if (a > diff[m]) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    // Moverlo hacia la izquierda
    l = 1, r = i-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (a == -diff[m]) {
            return true;
        }
        if (a > -diff[m]) {
            r = m-1;
        } else {
            l = m+1;
        }
    }

    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>v[i];
        s[i] = s[i-1]+v[i];
    }

    if (s[n] % 2) {
        cout<<"NO\n";
        return 0;
    }

    ll T = s[n];
    for (int i = 1; i <= n; i++) {
        diff[i] = s[i]-T/2;
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == T-s[i] or valid(i)) {
            cout<<"YES\n";
            return 0;
        }
    }

    cout<<"NO\n";

    return 0;
}
