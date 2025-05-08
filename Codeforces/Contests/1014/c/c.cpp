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

    ll t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        ll largestEven = 0, largestOdd = 0, evenSum = 0, oddSum = 0;
        ll oddCount = 0;
        for (ll i = 0; i < n; i++) {
            ll a; cin>>a;
            if (a % 2) {
                largestOdd = max(largestOdd, a);
                oddSum += a;
                oddCount++;
            }
            else {
                largestEven = max(largestEven, a);
                evenSum += a;
            }
        }
        if (evenSum == 0) {
            cout<<largestOdd<<"\n";
            continue;
        }
        if (oddSum == 0) {
            cout<<largestEven<<"\n";
            continue;
        }
        cout<<oddSum+evenSum-oddCount+1<<"\n";
    }

    return 0;
}
