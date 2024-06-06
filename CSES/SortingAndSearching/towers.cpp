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

bool compare(pll p1, pll p2) {
    return p1.first > p2.first;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    vector<ll> c(n);
    forn(i,n) cin >> c[i];

    multiset<ll> bases;
    ll count = 0;
    forn (i, n) {
        auto ub = bases.upper_bound(c[i]);
        if (ub == bases.end()) {
            count++;
        } else {
            bases.erase(ub);
        }
        bases.insert(c[i]);
    }
    cout<<count<<"\n";
    return 0;
}