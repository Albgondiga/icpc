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
#define ifd if (debug)

bool pot2(ll x) {
    ll pot = 1;
    while (pot < x) {
        pot *= 2;
    }
    if (pot == x) return true;
    else return false;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, q; cin>>n>>q;
    vector<ll> vA(n+1,0), vB(n+1,0), vC(n+1,0);
    for(ll i = 1; i <= n; i++) {
        ll x; cin>>x;
        if (x % 2) {
            if (x == 1) {
                vC[i] = vC[i-1]+1;
                vA[i] = vA[i-1];
                vB[i] = vB[i-1];
            } else {
                vB[i] = vB[i-1]+x;
                vA[i] = vA[i-1];
                vC[i] = vC[i-1];
            }
        } else if (pot2(x)) {
            vA[i] = vA[i-1]+x;
            vB[i] = vB[i-1];
            vC[i] = vC[i-1];
        } else {
            vA[i] = vA[i-1];
            vB[i] = vB[i-1];
            vC[i] = vC[i-1];    
        }
    }

    ifd {
        for (auto x : vA) cout<<x<<" ";
        cout<<endl;
        for (auto x : vB) cout<<x<<" ";
        cout<<endl;
        for (auto x : vC) cout<<x<<" ";
        cout<<endl;
    }

    while(q--) {
        ll l, r; cin>>l>>r;
        ll sumaA = vA[r]-vA[l-1];
        ll sumaB = vB[r]-vB[l-1];
        if ((vC[r]-vC[l-1]) % 2) {
            sumaA++;
        }
        if (sumaA > sumaB) {
            cout<<"A\n";
        } else if (sumaB > sumaA) {
            cout<<"B\n";
        } else {
            cout<<"E\n";
        }
    }

    return 0;

}
