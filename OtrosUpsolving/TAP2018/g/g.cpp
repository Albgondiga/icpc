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

int dot(ii a, ii b) {
    return a.first*b.first + a.second*b.second;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    vector<ii> p(n);
    forn(i,n) {
        int x, y; cin>>x>>y;
        p[i] = {x,y};
    }
    
    ll count = 0;
    for (int i = 0; i < n; i++) {
        ii a = p[i];
        for (int j = i+1; j < n; j++) {
            ii b = p[j];
            for (int k = j+1; k < n; k++) {
                ii c = p[k];
                ii ab = { a.first-b.first, a.second-b.second };
                ii ac = { a.first-c.first, a.second-c.second };
                ii bc = { b.first-c.first, b.second-c.second };
                if (dot(ab,ac) == 0 || dot(ab,bc) == 0 || dot(ac,bc) == 0) {
                    count++;
                }
            }
        }
    }
    cout<<count<<"\n";

    return 0;
}