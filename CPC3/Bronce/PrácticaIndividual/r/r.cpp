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

    map<ll,ll> m;
    ll n; cin>>n;
    forn(i,n) {
        ll x; cin>>x;
        m[x]++;
    }
    ll count = 0;
    for (auto i:m) {
        ifd cout<<i.first<<" "<<i.second<<endl;
        if (i.second >= i.first)
            count += i.second-i.first;
        else
            count += i.second;
    }
    cout<<count<<"\n";
}