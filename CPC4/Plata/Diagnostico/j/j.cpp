#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
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
 
        void query_and_update(ll v, ll tl, ll tr, ll val){
            if(tl == tr) {
                st[v] -= val;
                cout<<tl+1<<" ";
            }
            else {
                ll tm = tl+(tr-tl)/2;
                if (st[2*v] >= val) query_and_update(2*v,tl,tm,val);
                else query_and_update(2*v+1,tm+1,tr,val);

                st[v] = max(st[2*v],st[2*v+1]);
            }
        }
};
 
int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin>>n>>m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    SegmentTree st(a);

    for (int i = 0; i < m; i++) {
        ll r; cin>>r;
        if (st.st[1] < r) cout<<"0 ";
        else st.query_and_update(1,0,n-1,r);
    }
    cout<<"\n";
    return 0;
}
