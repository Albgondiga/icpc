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
typedef pair<string, int> si;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

ll sumDivisors(ll x) {
    if (x==1) return 0;
    ll sum = 1;
    for(ll d = 2; d*d <= x; d++) {
        if (x % d == 0) {
            sum+=d;
            if (d*d != x)
                sum+=x/d; 
        }
    }
    return sum;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin>>n;
    forn(i,n) {
        ll x; cin>>x;
        cout<<sumDivisors(x)<<"\n";
    }
}