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

int n, k; 
string s;

bool check(int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        
    }
    if (count == k+1) return true;
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>k>>s;
    int l = 0, r = 1e6, ans = -1;
    while (l <= r) {
        int m = (l+r)/2;
        if (check(m)) {
            ans = m; r = m-1;
        } else {
            l = m+1;
        }
    }

    return 0;
}
