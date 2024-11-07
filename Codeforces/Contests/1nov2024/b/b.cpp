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
    while(t--){
        int n, k; cin>>n>>k;
        if (n == 1) {
            cout<<1<<"\n"<<1<<"\n";
        } else if (k == 1 or k == n) {
            cout<<-1<<"\n";
        } else {
            if (k % 2 == 0) {
                int casiM = min(k-1,n-k);
                cout<<2*casiM+1<<"\n";
                for (int i = 1; i <= casiM; i++) {
                    cout<<i<<" ";
                }
                cout<<k<<" ";
                for (int i = 1; i <= casiM; i++) {
                    cout<<k+i<<" ";
                }
                cout<<"\n";
            } else {
                int casiM = min(k-2,n-k-1);
                cout<<2*casiM+1<<"\n";
                for (int i = 1; i <= casiM; i++) {
                    cout<<i<<" ";
                }
                cout<<k-1<<" ";
                for (int i = 1; i <= casiM; i++) {
                    cout<<k+1+i<<" ";
                }
                cout<<"\n";
            }
        }
    }

    return 0;
}
