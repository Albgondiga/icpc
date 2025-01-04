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

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;

    while(tc--) {
        int n; cin >> n;
        int toMatch = -1;
        vector<bool> used(n+1);

        for (int i = 1; i < n; i++) {
            int m; cin >> m;
            bool found = false;
    
            for (int j = 0; j < m; j++) {
                int p; cin >> p;

                if (!used[p] && !found) {
                    found = true;
                    used[p] = true;
                }
            }

            if(!found) {
                toMatch = i;
            }
        }

        if (toMatch == -1) {
            cout<<"OPTIMAL"<<"\n";
        } else {
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    cout<<toMatch<<" "<<i<<"\n";
                }
            }
        }
    }
    return 0;
}