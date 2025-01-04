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

    ll t; cin>>t;
    forn(i,t) {
        ll n; cin>>n;
        vector<ll> a(n);
        forn(j,n) cin>>a[j];

        sort(a.begin(),a.end());
        if (a[0] == a[1]) {
            ll first = a[0];
            bool no = true;
            for(int k = 2; k < n && no; k++) {
                if (a[k] % first) {
                    cout<<"YES"<<"\n";
                    no = false; 
                }
            }
            if (no)
                cout<<"NO"<<"\n";
        } else {
            cout<<"YES"<<"\n";
        }
    }
}