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
vector<ll> tree;
int n;

void add(int i, ll k) {
    ifd cout<<"le estoy sumando al mae en "<<i<<" "<<k<<endl;
    while (i<n+1) {
        tree[i]+=k;
        ifd cout<<"tree["<<i<<"] = "<<tree[i]<<endl;
        i+=i&-i;
    }

    ifd {
        cout<<"ahora el arbol se ve: "<<endl;
        forn(i, n+1) cout<<tree[i]<<" ";
        cout<<endl;
    }
}


ll sum(int i) {
    ll ans=0;
    while (i>0) {
        ans+=tree[i];
        i-=(i&-i);
    }
    return ans;
}
int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>n>>q;
    tree.resize(n+1);
    ifd {
        cout<<"AL INICIO SE VE: "<<endl;
        forn(i, n+1) cout<<tree[i]<<" ";
        cout<<endl;
    }
    while (q--) {
        ifd {
            cout<<"SE VE: "<<endl;
            forn(i, n+1) cout<<tree[i]<<" ";
            cout<<endl;
        }
        char c; cin>>c;

        if (c=='!') {
            int l, r; ll x;
            cin>>l>>r>>x;
            add(l, x);
            add(r+1, -1*x);
        }
        if (c=='?') {
            ll p, x;
            cin>>p>>x;
            ll ans=sum(p);
            if (ans>=x) {
                cout<<"yes sir\n";
                //add(p, -x);

                add(p, -x);
                add(p+1, x);
            }
            else cout<<"negative\n";

        }
    }
}
