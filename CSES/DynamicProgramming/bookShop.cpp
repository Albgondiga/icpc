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

const ll mxX = 1e6+5;
const ll INF = 1e9+5;
const ll MINUS_INF = -1*INF;
ll value[mxX];  // Maximo numero de paginas para cada precio
ll ready[mxX];
vector<ll> prices;
vector<ll> pages;
ll N, X;

// Knapsack
void solve(ll n) {
    value[0] = 0;
    for (int b = 0; b < N; b++) {
        for(ll x = n; x >= 0; x--) {
            if (x - prices[b] >= 0) {
                // if (possible[x]) possible[x+w[k]]
                value[x] = max(value[x], value[x-prices[b]]+pages[b]);
            }   
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    memset(ready, 0, sizeof(ready));
    
    cin>>N>>X;
    prices.resize(N);
    pages.resize(N);
    forn(i,N) cin>>prices[i];
    forn(i,N) cin>>pages[i];

    solve(X);
    cout<<value[X]<<"\n";

    return 0;
}