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
        int n; cin>>n;
        string s; cin>>s;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') a.push_back(i+1);
            else b.push_back(i+1);
        }

        bool alice = false;
        for (int& cA : a) {
            bool ganadora = true;
            for (int& cB : b) {
                if ((!(cB == 1 and cA == n) and (cA > cB) or (cA == 1 and cB == n))) continue;
                ganadora = false;
                break;
            }
            if (ganadora) {
                alice = true;
                break;
            }
        }
        if (alice) {
            cout<<"Alice\n";
            continue;
        } 
        cout<<"Bob\n";
    }

    return 0;
}
