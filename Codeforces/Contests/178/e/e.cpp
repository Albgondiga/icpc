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

#define debug 0
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k; cin>>n>>k;
    string s; cin>>s;
    int q; cin>>q;

    // Primera vez donde letra-'a' aparece a partir de j
    int apariciones[k][n+1];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n+1; j++) {
            apariciones[i][j] = -1;
        }
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            if (s[i]-'a' == j) apariciones[j][i] = i;
            else apariciones[j][i] = apariciones[j][i+1];
        }
    }

    while (q--) {
        string t; cin>>t;

        int ultimaPos = apariciones[t[0]-'a'][0];

        for (int i = 1; i < t.size(); i++) {
            if (ultimaPos == -1) break;
            ultimaPos = apariciones[t[i]-'a'][ultimaPos+1];
        }

        if (ultimaPos == -1) {
            cout<<0<<"\n";
            continue;
        }

        int ans = 1;
        bool seguir = true;
        int i = ultimaPos+1;
        while (i < n and seguir) {
            int M = -1;
            for (int j = 0; j < k and seguir; j++) {
                if (apariciones[j][i] == -1) {
                    seguir = false;
                }
                M = max(M, apariciones[j][i]);
            }
            if (seguir) {
                i = M+1;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
