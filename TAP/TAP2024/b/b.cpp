// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
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
const int sz=1e6+65;
#define debug 0
#define ifd if (debug)

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin>>n; ll nOg=n;
    vector<ll> div;
    for (ll x=2;x<=n; x++) {
        if (n%x) continue;
        ifd cout<<"vea que "<<x<<" divide a "<<n<<endl;
        div.push_back(x);
        while (n%x==0) n/=x;
    }

    n=nOg;
    if (div.size()==0) {
        ifd cout<<"es primo!"<<endl;
        cout<<"1\n";
        cout<<"1 1\n";
    }

    else {

        cout<<div.size()<<"\n";
        for (ll u:div) cout<<"1 "<<n/u<<"\n";
    }
}
