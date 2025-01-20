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

const ll INF = 1e18;

class SegmentTree {
    public : 
        vector<ll> st;
        ll n;
 
        SegmentTree(vector<ll> a) {
            n = a.size();
            st.assign(n*4,0);
            build(a,1,0,n-1);
        }

        void build(vector<ll> &a, ll v, ll tl, ll tr) {
            if(tl == tr) {
                st[v] = a[tl];
            }
            else {
                ll tm = tl+(tr-tl)/2;
                build(a,2*v,tl,tm);
                build(a,2*v+1,tm+1,tr);
                st[v] = max(st[2*v],st[2*v+1]);
            }
        }
 
        ll query(ll v, ll tl, ll tr, ll l, ll r){
            if(l > r) return -1;
            if(tl == l && tr == r) return st[v];
            ll tm = tl + (tr-tl)/2;
            return max(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr, max(l,tm+1),r));
        }
 
        ll query(ll l, ll r) {
            return query(1,0,n-1,l,r);
        }

        void update(ll v, ll tl, ll tr, ll pos, ll val){
            if(tl == tr) {
                st[v] = val;
            }
            else {
                ll tm = tl+(tr-tl)/2;
                if(pos<= tm) update(2*v,tl,tm,pos,val);
                else update(2*v+1,tm+1,tr,pos,val);
                st[v] = max(st[2*v],st[2*v+1]);
            }
        }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    while (cin >> n) {
        cin>>m;
        vector<ll> hills(n);
        forn(i, n) cin>>hills[i];
        SegmentTree st(hills);

        ll count = 0;
        while (m--) {
            ll a, b; cin>>a>>b;
            a--; b--;
            ll maxHill = st.query(a+1, b-1);
            if (maxHill <= hills[a]) count++;
        }

        cout<<count<<"\n";
    }
    return 0;
}
