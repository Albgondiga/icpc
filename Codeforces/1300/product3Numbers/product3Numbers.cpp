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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t; cin>>t;
    ll n;
    while(t--) {
        cin>>n;
        if (n < 24) cout<<"NO\n";
        else {
            bool possible = false;
            for (ll a = 2; a * a <= n && !possible; a++) {
                if (n % a == 0) {
                    ll bc = n/a;
                    for (ll b = a+1; b*b < bc; b++) {
                        if (bc % b == 0) {
                            ll c = bc/b;
                            cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n";
                            possible = true;
                            break;
                        }
                    }
                }
            }
            if (!possible) cout<<"NO\n";
        }
    }

    return 0;
}