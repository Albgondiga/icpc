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

    int k; cin>>k;
    string s; cin>>s;

    ll count = 0;
    int n = s.size();
    ll ones = 0, zeros = 0;
    int first1 = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            else if (ones < k) {

            } else {

            }
            ones++;
            if (first1 == -1) first1 = i;
        } else {
            zeros++;
        }
    }
    cout<<count<<"\n";
    return 0;
}
