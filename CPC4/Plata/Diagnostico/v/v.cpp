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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

ll cross(pll a, pll b) {
    return a.first*b.second - a.second*b.first;
}

pll mvector(pll a, pll b) {
    return {b.first-a.first, b.second-a.second};
}

bool overlap(pll a, pll b, pll c, pll d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    return !(b < c || d < a);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        pll a, b, c, d;
        a = {x1, y1}; b = {x2, y2};
        c = {x3, y3}; d = {x4, y4};
        
        if (a == c or a == d or b == c or b == d) {
            // Comparten vertice
            cout<<"YES\n";
        } else {
            pll ac = mvector(a, c); pll bc = mvector(b, c);
            pll ad = mvector(a, d); pll bd = mvector(b, d);

            pll ca = mvector(c, a); pll da = mvector(d, a);
            pll cb = mvector(c, b); pll db = mvector(d, b);

            if ((cross(ac, bc) * cross(ad, bd) < 0) and
                (cross(ca, da) * cross(cb, db) < 0)) {
                cout<<"YES\n";
            } else {
                if (cross(ac,bc) == 0 and cross(ad,bd) == 0) {
                    if (overlap(a,b,c,d)) {
                        cout<<"YES\n";
                    } else {
                        cout<<"NO\n";
                    }
                } else {
                    cout<<"NO\n";
                }
            } 
        }
    }

    return 0;
}
