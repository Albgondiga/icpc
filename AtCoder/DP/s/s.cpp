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

const ll MOD = 1e9+7;

string k;
int n, d;
vector<vector<vector<ll>>> dp;

// Si libre = true, soy menor que k sin importar que hago
ll f(int pos, ll sum, bool libre) {
    // Si ya se termino el numero, reviso si es multiplo
    if (pos == n) return (sum == 0 ? 1 : 0);
    if (dp[pos][sum][libre] == -1) {
        ll ans = 0;
        // Techo es el digito mas grande que puedo poner ahora
        int techo = (libre ? 9 : k[pos]-'0');
        for (int x = 0; x <= techo; x++) {
            ans += f(pos+1, (sum+x) % d, (libre or x < techo) ? true : false);
            ans %= MOD;
        }
        dp[pos][sum][libre] = ans;
    }
    return dp[pos][sum][libre];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>k>>d;
    n = k.size();

    dp.resize(n, vector<vector<ll>>(d, vector<ll>(2, -1)));
    // -1 para no contar el 0
    ll ans = (f(0,0,false) - 1 + MOD) % MOD;
    cout<<ans<<"\n";

    return 0;
}
