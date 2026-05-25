#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        string s; cin>>s;

        int coll = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == s[i+1]) coll++;
        }

        if (coll > 2) {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
    }

    return 0;
}
