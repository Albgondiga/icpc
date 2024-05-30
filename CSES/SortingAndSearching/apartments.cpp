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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n,m,k; cin>>n>>m>>k;

    vector<ll> app(n);
    vector<ll> apt(m);
    forn(i, n) cin >> app[i];
    forn(j, m) cin >> apt[j];

    sort(app.begin(), app.end());
    sort(apt.begin(), apt.end());
    auto i1 = app.begin();
    auto i2 = apt.begin();

    ll count = 0;
    while (i1 != app.end() && i2 != apt.end()) {
        if (*i1 > *i2+k) {
            i2++;
        } else if (*i1 < *i2-k) {
            i1++;
        } else {
            count++;
            i1++;
            i2++;
        }
    }
    cout<<count<<"\n";
    return 0;
}