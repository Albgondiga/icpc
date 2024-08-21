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

#define debug 0
#define ifd if (debug)


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, r, c;
    ordered_set candidates;
    vector<int> hired;

    cin>>n>>r>>c;
    r--;
    c--;
    forn(i,n) candidates.insert(i+1);
    ifd cout<<"r="<<r<<", c="<<c<<endl;
    ll pos1 = r;
    ll pos2 = c;
    ifd cout<<"candidates.size()="<<candidates.size()<<endl<<endl;
    while (candidates.size() > 2) {
        ifd {
            cout<<"Quedan: ";
            for (auto c : candidates) cout<<c<<" ";
            cout<<endl;
        }

        pos1 %= candidates.size();
        pos2 %= candidates.size();
        
        ifd cout<<"pos1 = "<<pos1<<", pos2 = "<<pos2<<endl;

        auto s1 = candidates.find_by_order(pos1);
        auto s2 = candidates.find_by_order(candidates.size()-pos2-1);
        
        ifd cout<<"Despues de moverse s1 esta en "<<*s1<<", s2 esta en "<<*s2<<endl<<endl;
        
        if (s1 == s2) {
            hired.push_back(*s1);
            candidates.erase(s1);
            pos1 += r;
            pos2 += c;
        } else {
            candidates.erase(s1);
            candidates.erase(s2);
            pos1 += (r-1);
            pos2 += (c-1);
        }
    }

    if (candidates.size() >= 1) hired.push_back(*candidates.find_by_order(0));
    if (candidates.size() == 2) hired.push_back(*candidates.find_by_order(1));

    sort(hired.begin(), hired.end());
    for (auto h : hired) cout<<h<<" ";
    cout<<"\n";

    return 0;
}
