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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 0
#define ifd if (debug)

string p, t;
vector<ll> a;

bool check(ll m) {
    set<int> s;
    forn(i,m) s.insert(a[i]);

    ifd for(auto i:s) cout<<i<<" ";
    ifd cout<<endl;

    int start = 0;
    for (auto c : p) {
        ifd cout<<"Estoy buscando una "<<c<<" empezando en "<<start<<endl;
        bool found = false;
        for (int i = start; i < t.size() && !found; i++) {
            if ((t[i] == c) && (s.find(i+1) == s.end())) {
                ifd if(found) cout<<"La encontre"<<endl;
                found = true; start = i+1;
            }
        }
        ifd if (!found) cout<<"No la encontre"<<endl;
        if (!found) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>t>>p;
    a.resize(t.size());

    forn(i, t.size()) cin>>a[i];

    ll l = 1, r = t.size()-p.size()+1;
    ll res = 0;
    while (l <= r) {
        ifd cout<<"l = "<<l<<", r = "<<r<<endl;
        ll m = l + (r-l)/2;
        if (check(m)) {
            ifd cout<<m<<" funciona"<<endl;
            l = m+1; res = m;
        } else {
            ifd cout<<m<<" no funciona"<<endl;
            r = m-1;
        }
    }
    cout<<res<<"\n";

    return 0;
}
