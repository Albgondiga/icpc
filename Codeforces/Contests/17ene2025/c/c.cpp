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
        int unos = n/2;
        if (n % 2) unos++;

        if (unos % 2) {
            int x = 1;
            for (int i = 1; i <= unos/2+1; i++) cout<<x<<" ";
            for (int i = 1; i <= n-unos; i++) cout<<++x<<" ";
            x = 1;
            for (int i = 1; i <= unos/2; i++) cout<<x<<" ";
            cout<<"\n";
        } else {
            int x = 1;
            for (int i = 1; i <= unos/2-1; i++) cout<<x<<" ";
            for (int i = 1; i <= n-unos+1; i++) cout<<++x<<" ";
            x = 1;
            for (int i = 1; i <= unos/2; i++) cout<<x<<" ";
        }
    }

    return 0;
}
