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

    ll n, m; cin>>n>>m;
    vector<ll> v(n);
    map<ll,ll> index;
    forn(i,n) {
        cin>>v[i];
        index[v[i]] = i;
    }

    ll count = 1;
    for (ll i = 1; i < n; i++) {
        if (index[i+1] < index[i]) {
            count++;
        }
    }
    ifd cout<<"count="<<count<<endl;
    forn(i,m) {
        ll a,b; cin>>a>>b;
        index[v[a-1]] = b-1;
        index[v[b-1]] = a-1;
        swap(v[a-1],v[b-1]);
        if (v[b-1] > v[a-1]) {
            ifd cout<<v[b-1]<<" es mayor que "<<v[a-1]<<endl;
            count--;
        } else {
            ifd cout<<v[b-1]<<" es menor que "<<v[a-1]<<endl;
            count++;
        }
        cout<<count<<"\n";
    }
    return 0;
}