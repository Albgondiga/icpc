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

    int t; cin>>t;
    while (t--) {
        int n, m; cin>>n>>m;
        vector<int> a(n), b(m);
        for (int& x : a) cin>>x;
        for (int& x : b) cin>>x;

        // Recorrido 1
        int k1 = -1;
        int iA = 0, iB = 0;
        while (iA < n and iB < m) {
            int flower = a[iA], beauty = b[iB];
            if (flower >= beauty) {
                iA++; iB++;
            } else {
                iA++;
            }
        }
        if (iB > m) k1 = 0;
        else if (iB == m-1) k1 = b[m-1];
        // Recorrido 2
        int k2 = -1;
        iA = n-1, iB = m-1;
        while (iA >= 0 and iB >= 0) {
            int flower = a[iA], beauty = b[iB];
            if (flower >= beauty) {
                iA--; iB--;
            } else {
                iA--;
            }
        }
        if (iB < 0) k2 = 0;
        else if (iB == 0) k2 = b[0];

        if (k1 == 0 or k2 == 0) cout<<0<<"\n";
        else if (k1 == -1 and k1 == -1) cout<<-1<<"\n";
        else if (k1 == -1 and k2 > 0) cout<<k2<<"\n";
        else if (k2 == -1 and k1 > 0) cout<<k1<<"\n";
        else cout<<min(k1,k2)<<"\n";
    }

    return 0;
}
