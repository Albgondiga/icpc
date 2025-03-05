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

const int N = 2*1e5+1;
ll heights[N], beauties[N];
int n;

#define dontPull 0
#define pull 1

ll dp[N][2];

ll f(int i, ll minHeight, int pullFlower) {
    if (i == n) return 0;
    if (!pullFlower and heights[i] < minHeight) return 0;

    if (dp[i][pullFlower] == -1) {
        ll beauty = 0;
        if (pullFlower) {
            beauty = max(f(i+1, minHeight, pull), f(i+1, minHeight, dontPull));
        } else {
            beauty = beauties[i];
            beauty += max(f(i+1, heights[i], pull), f(i+1, heights[i], dontPull));
        }
        dp[i][pullFlower] = beauty;
    } 
    return dp[i][pullFlower];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for (int i = 0; i < n; i++) cin>>heights[i];
    for (int i = 0; i < n; i++) cin>>beauties[i];
    for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = -1;

    cout<<max(f(0,0,pull), f(0,0,dontPull))<<"\n";

    return 0;
}
