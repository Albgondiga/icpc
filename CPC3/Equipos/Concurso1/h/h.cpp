// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0
vector<int> v;

ll calcule (ll x) {
    ll res=0;
    for (int u:v) res+=(u/x);
    return res;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC; cin>>tC;
    while(tC--) {
        ll n, k; cin>>n>>k;
        if (debug) cout<<"k = "<<k<<endl;
        ll sum=0;
        v.resize(n);
        forn(i, n) {
            cin>>v[i];
            sum+=v[i];
        }
        ll div=k*k;
        ll max=sum/div;
        ll min=1;
        ll res = -1;
        while (min<=max) {
            ll x = ((min+max)/2);
            if (debug) cout<<"estoy probando con min="<<min<<", max = "<<max<<" y x="<<x<<endl;
            ll ans=(calcule(x));
            if (debug) cout<<"mi division de los maes dio "<<ans<<endl;;
            if (ans>=k*k) {
                min=x+1; res = x;
            }
            else max=x-1;
        }
        cout<<res<<"\n";

    }
}
