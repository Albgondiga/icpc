#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#define debug 1
#define ifd if (debug)

#define R 0
#define B 1

const int N = 2e5+5;
// dp[i] tiene el costo minimo de pintar de i en adelante
ll dp[N];
char v1[N], v2[N];

int n;

ll f(int i) {
    if (i >= n) return 0;
    if (i == n-1) return (v1[i] != v2[i]);
    if (dp[i] == -1) {
        dp[i] = min(
            (v1[i] != v2[i]) + f(i+1),
            (v1[i] != v1[i+1]) + (v2[i] != v2[i+1]) + f(i+2)
        );
    }
    return dp[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        cin>>n;
        forn(i,n) cin>>v1[i];
        forn(i,n) cin>>v2[i];
        forn(i,n) dp[i] = -1;

        cout<<f(0)<<"\n";
    }

    return 0;
}
