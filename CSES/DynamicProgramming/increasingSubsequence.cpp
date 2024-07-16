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
ll value[mxX];
vector<ll> v;

void solve(ll n) {
    for (ll i = 0; i < n; i++) {
        value[i] = 1;

        ll l = 0, r = i-1, pos = -1;
        while (l <= r) {
            ll m = (l + r) / 2;
            if (value[m] <) {
                l = m + 1; pos = m;
            } else {
                r = m - 1;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    v.resize(n);
    forn(i,n) cin>>v[i];

    solve(n);
    cout<<*max_element(value.begin(),value.end());

    return 0;
}