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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n,x; cin>>n>>x;
    vector<ll> p(n);
    forn(i,n) cin>>p[i];

    sort(p.begin(), p.end());
    ll count = 0;
    ll w = x;
    auto i1 = p.begin();
    auto i2 = p.end()-1;
    while (i1 < i2) {
        ifd cout<<*i1<<" "<<*i2<<endl;
        if (*i1 + *i2 <= x) {
            count++;
            i1++;
            i2--;
        } else {
            count++; // otro para i2
            i2--;
        }
    }
    if (i1 == i2) count++;
    cout<<count<<"\n";
    return 0;
}