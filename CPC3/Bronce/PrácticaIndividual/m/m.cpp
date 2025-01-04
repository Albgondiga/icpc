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

    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    forn(i,n) cin>>a[i];
    sort(a.begin(),a.end());

    ll first = a[n/2]; ll last = a[n/2]+k;
    ll maxMedian = 0;
    // Busqueda binaria en lugar de contar todos
    // por fuerza bruta
    while (first <= last) {
        maxMedian = (first+last)/2;
        ifd cout<<"maxMedian = "<<maxMedian<<endl; 

        ll op = 0;
        for(ll i = n/2; i < n; i++) {
            if (maxMedian-a[i] > 0) {
                op += maxMedian-a[i];
                if (op > k)
                    break;
            }
        }

        if (op <= k) {
            first = maxMedian+1;
        } else {
            last = maxMedian-1;
        }
    }

    cout<<first-1<<"\n";
    return 0;
}
