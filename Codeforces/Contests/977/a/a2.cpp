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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        int n; cin>>n;
        deque<ll> v;
        forn(i,n) {
            ll x; cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        while (v.size() > 1) {
            ll a = v.front(); v.pop_front();
            ll b = v.front(); v.pop_front();
            v.push_back((a+b)/2);
            sort(v.begin(), v.end());
        }
        cout<<v.front()<<endl;
    }

    return 0;
}
