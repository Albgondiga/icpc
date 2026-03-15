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

const int N = 300+1;
int n;
// dp[i][j][k] tiene cuantas operaciones cuando hay i con 1, j con 2 y k con 3
double dp[N][N][N];

double f(int i, int j, int k) {
    if (i < 0 or j < 0 or k < 0) return 0.0;
    if (i == 0 and j == 0 and k == 0) return dp[i][j][k] = 0.0;
    if (dp[i][j][k] < 0.0) {
        double x = (double)i, y = (double)j, z = (double)k;
        double ans = (double)n + x*f(i-1,j,k) + y*f(i+1,j-1,k) + z*f(i,j+1,k-1);
        ans /= (x+y+z);
        dp[i][j][k] = ans;
    }
    return dp[i][j][k];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n;
    int i = 0, j = 0, k = 0;
    forn(c,n) {
        int a; cin>>a;
        if (a == 1) i++;
        else if (a == 2) j++;
        else k++;
    }

    forn(a,n+1) forn(b,n+1) forn(c,n+1) dp[a][b][c] = -1.0;
    
    cout<<setprecision(15)<<fixed<<f(i,j,k)<<"\n";

    return 0;
}
