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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> v;
    v.push_back(0);
    v.push_back(9);

    int l = 0, r = 2;
    if (v.begin()+2 == v.end()) cout<<"Todo bien"<<endl;
    auto i1 = lower_bound(v.begin()+l,v.begin()+r,0);
    auto i2 = upper_bound(v.begin()+l,v.begin()+r,0);
    l = i1-v.begin();
    r = i2-v.begin();
    cout<<"l = "<<l<<", r = "<<r<<endl;

    i1 = lower_bound(v.begin()+l,v.begin()+r,9);
    i2 = upper_bound(v.begin()+l,v.begin()+r,9);
    if (i1 == v.begin()+r) cout<<"No lo encontre"<<endl;
    else {
        cout<<*i1<<" "<<*i2<<endl;
        l = i1-v.begin();
        r = i2-v.begin();
        cout<<"l = "<<l<<", r = "<<r<<endl;
    }

    return 0;
}
