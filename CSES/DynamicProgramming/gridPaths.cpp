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
const ll MAX = 1e3+5;
ll value[MAX][MAX]; 
bool blocked[MAX][MAX]; 
 
void solve(ll n) {
    // for (ll i = 1; i <= n; i++) {
    //     value[0][i] = 1;
    //     value[i][0] = 1;
    // }
    value[1][1] = 1;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (!blocked[i][j]) {
                value[i][j] += value[i][j-1];
                value[i][j] += value[i-1][j];
                value[i][j] %= MOD;
            }
        }
    }
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    ll n; cin>>n;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            char c; cin>>c;
            if (c == '*')
                blocked[i][j] = 1;
            else
                blocked[i][j] = 0;
        }
    }

    if (blocked[1][1]) {
        cout<<0<<"\n";
    } else {
        solve(n);
        cout<<value[n][n]<<"\n";
    }

    return 0;
}