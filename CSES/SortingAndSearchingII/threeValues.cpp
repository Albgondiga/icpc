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

int n;
ll x;
vector<pair<ll,int>> a;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>x;
    a.resize(n);
    forn(i,n) {
        ll num; cin>>num;
        a[i] = {num,i+1};
    } 

    sort(a.begin(), a.end());

    forn (i, n-2) {
        int j = i+1;
        int k = n-1;
        while (j < k) {
            ll sum = a[i].first+a[j].first+a[k].first;
            if (sum == x) {
                cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<"\n";
                return 0;
            } else if (sum > x) {
                k--;
            } else if (sum < x) {
                j++;
            }
        }
    }

    cout<<"IMPOSSIBLE\n";

    return 0;
}