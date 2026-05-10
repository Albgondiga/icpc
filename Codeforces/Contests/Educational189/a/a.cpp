#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        ll x, y; cin>>x>>y;

        ll k = y/x;
        ll z = (k-1)*x;
        if (z > x and z < y) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
