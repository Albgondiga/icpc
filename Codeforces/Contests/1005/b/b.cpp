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
        vector<int> v(n);
        vector<int> freq(2e5+5,0);
        for (int& x : v) {
            cin>>x;
            freq[x]++;
        }

        vector<int> prefixUnos(n,0);
        if (freq[v[0]] == 1) prefixUnos[0] = 1;
        for  (int i = 1; i < n; i++) {
            if (freq[v[i]] > 1) continue;
            prefixUnos[i] = prefixUnos[i-1]+1;
        }

        int i = max_element(prefixUnos.begin(), prefixUnos.end()) 
                - prefixUnos.begin();
        
        if (prefixUnos[i] == 0) {
            cout<<0<<"\n";
            continue;
        }
        cout<<i-prefixUnos[i]+2<<" "<<i+1<<"\n";
    }

    return 0;
}
