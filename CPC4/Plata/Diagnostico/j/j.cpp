#include <bits/stdc++.h>
using namespace std; 
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)
 
const ll INF = 1e18;
 
struct Data {
    ll value, index;
};
 
class SegmentTree {
    public : 
        vector<Data> st;
 
        Data make_data(ll value, ll index) {
            Data d;
            d.value = value;
            d.index = index;
            return d;
        }

        Data make_data(const Data& a) {
            Data d;
            d.value = a.value;
            d.index = a.index;
            return d;
        }
 
        SegmentTree(vector<Data> a) {
            st.assign(a.size()*4,make_data(0,0));
            build(a,1,0,a.size()-1);
        }
 
        Data combine(Data a, Data b) {
            Data c;
            if (a.value >= b.value) {
                c.value = a.value;
                c.index = a.index;
            } else {
                c.value = b.value;
                c.index = b.index;
            }
            return c;
        }
 
        void build(vector<Data> &a, ll v, ll tl, ll tr) {
            if(tl == tr) {
                st[v] = make_data(a[tl]);
            }
            else {
                ll tm = tl+(tr-tl)/2;
                build(a,2*v,tl,tm);
                build(a,2*v+1,tm+1,tr);
                st[v] = combine(st[2*v],st[2*v+1]);
            }
        }
 
        Data query(ll v, ll tl, ll tr, ll l, ll r){
            if(l > r) return make_data(INF, INF);
            if(tl == l && tr == r) return st[v];
            ll tm = tl + (tr-tl)/2;
            return combine(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr, max(l,tm+1),r));
        }
 
        void update(ll v, ll tl, ll tr, ll pos, ll val, ll index){
            if(tl == tr) {
                st[v] = make_data(val, index);
            }
            else {
                ll tm = tl+(tr-tl)/2;
                if(pos<= tm) update(2*v,tl,tm,pos,val);
                else update(2*v+1,tm+1,tr,pos,val);
                st[v] = combine(st[2*v],st[2*v+1]);
            }
        }
};
 
int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin>>n>>m;
    vector<Data> a(n);
    forn(i,n) {
        ll h; cin>>h;
        a[i] = {h, i+1};
    }
    SegmentTree st(x);
    while(q--){
        cin>>a>>b;
        a--;
        st.update(1,0,n-1,a,b);
        cout<<st.query(1,0,n-1,0,n-1).best<<"\n";
    }
}
