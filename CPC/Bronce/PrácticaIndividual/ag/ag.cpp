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

#define debug 0
#define ifd if (debug)

const int MAX = 1e6 + 5;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, m; cin>>n>>m;
    vector<vector<ll>> ady(MAX);
    set<ll> nodes;
    forn(i,n) {
        ll x; cin >> x;
        ady[x].push_back(i+1);
    }
    ifd {
        forn(i,MAX) {
            cout<<i<<": ";
            forn(j,ady[i].size()) {
                cout<<ady[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    forn(i,m) {
        ll k, v; cin>>k>>v;
        if (ady[v].size() >= k) {
            cout<<ady[v][k-1]<<"\n";
        } else {
            cout<<0<<"\n";
        }
    }
}