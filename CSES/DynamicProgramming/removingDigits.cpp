#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll mxX = 1e6+5;
ll value[mxX]; 

// Iterativo
void solve(ll n) {
    value[0] = 0;
    for (ll x = 1; x <= n; x++) {
        value[x] = INF;
        ll number = x;
        while (number) {
            ll d = number % 10;
            value[x] = min(value[x], value[x-d]+1);
            number /= 10;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    solve(n);
    cout<<value[n]<<"\n";
}
