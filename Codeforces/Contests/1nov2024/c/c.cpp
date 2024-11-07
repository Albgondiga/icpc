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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        forn(i, n) cin >> a[i];
        sort(a, a+n);

        int i1 = n-3, i2 = n-1;
        int minZ = i2;
        while (i1 >= 0) {
            if (a[i1]+a[i1+1] > a[i2]) {
                minZ = i2;
            }
            i1--; i2--;
        }
        i1 = n-3;
        while ((i1 >= 0) and (a[i1]+a[i1+1] > a[minZ])) {
            i1--;
        }
        ifd cout<<"i1 = "<<i1<<" i2 = "<<i2<<endl;
        ifd cout<<"La primera suma que no me sirve es "<<a[i1]<<" + "<<a[i1+1]<<" > "<<a[i2]<<endl;
        int ans = 0;
        ans += max(0,i1+1);
        ans += max(0,n-i2-1);
        cout << ans << '\n';
    }

    return 0;
}
