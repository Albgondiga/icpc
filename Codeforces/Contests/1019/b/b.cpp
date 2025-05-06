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

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        string s; cin>>s;
        vector<int> v(n+1);

        v[0] = 0;
        for (int i = 1; i < n+1; i++) {
            v[i] = s[i-1]-'0';
        }

        ll switches = 0;
        for (int i = 1; i < n+1; i++) {
            if (v[i] != v[i-1]) switches++;
        }

        if (switches == 0) {
            cout<<n<<"\n";
        } else if (switches == 1) {
            cout<<n+1<<"\n";
        } else if (switches == 2) {
            cout<<n+1<<"\n";
        } else {
            cout<<n+switches-2<<"\n";
        }
    }

    return 0;
}
