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

    ll n; cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    forn(i,n) {
        cin>>a[i];
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto i1 = a.begin();
    auto i2 = b.begin();
    ll count = 0;
    ll m = 0;
    while (i1 != a.end() && i2 != b.end()) {
        if (*i1 < *i2) {
            count++;
            m = max(m,count);
            i1++;
        } else {
            count--;
            i2++;
        }
    }
    cout<<m<<"\n";
    return 0;
}