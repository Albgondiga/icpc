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
        bool hayCeros = false;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') hayCeros = true;
        }
        if (!hayCeros) {
            cout<<1<<"\n";
            continue;
        }
        for (int i = 0; i < n-1; i++) {
            if (s[i] == '1' and s[i+1] == '0') count++;
        }
        cout<<count*2+(s[n-1] == '1' ? 1 : 0)<<"\n";
    }


    return 0;
}
