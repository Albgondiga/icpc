#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
#define fore(e,c) for(const auto &e : (c))
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

string s, t;
int n, m;

// dp[i][j] tiene LCS entre s[0...i-1] y t[0...j-1]
vector<vector<int>> dp;

int f(int i, int j) {
    if (i > n or j > m) return 0;
    if (dp[i][j] == -1) {
        if (s[i] == t[j]) dp[i][j] = 1 + f(i+1,j+1);
        else dp[i][j] = max(f(i+1,j), f(i,j+1));
    }
    return dp[i][j];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>s>>t;

    n = s.size();
    m = t.size();

    // dp[i][j] tiene LCS entre s[0...i-1] y t[0...j-1]
    dp.assign(n+1, vector<int>(m+1, -1));

    f(0,0);

    int i = 0, j = 0;
    string ans = "";
    while (i < n and j < m) {
        if (s[i] == t[j]) {
            ans.push_back(s[i]);
            i++; j++;
        } else if (dp[i+1][j] >= dp[i][j+1]) {
            i++;
        } else {
            j++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
