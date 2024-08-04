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
const int MAXN=100100;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int MOD = 998244353;
int n, m; 
map<pair<int, vector<int>>, int> dp;

// Se mantiene un vector B tal que |B| = |LIS|
ll f(int i, vector<int>& B) {
    if (i == n) return (B.size() == 3);
    if (dp.count({i,B})) return dp[{i,B}];

    ll res = 0;
    for (int v = 1; v <= m; v++) {
        bool found = false;
        vector<int> B2 = B;

        for (int j = 0; j < B.size(); j++) {
            // Se reemplaza el primer Bj >= v por v
            if (B[j] >= v) {
                B2[j] = v; found = true;
                break;
            }
        }
        if (B.size() < 3 && !found) {
            B2.push_back(v); found = true;    
        }
        if (found) res = ((res + f(i+1, B2)) % MOD);
    }

    return dp[{i,B}] = res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    vector<int> B;
    cout<<f(0, B)<<"\n";

    return 0;
}