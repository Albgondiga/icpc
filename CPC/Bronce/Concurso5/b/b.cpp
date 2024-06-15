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

    int r1, c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;

    // Rook
    if (r1 == r2 || c1 == c2) {
        cout<<1<<" ";
    } else {
        cout<<2<<" ";
    }
    // Bishop
    if (((r1+c1) % 2 == 0 && (r2+c2) % 2 == 1) ||
            ((r1+c1) % 2 == 1 && (r2+c2) % 2 == 0)) {
        cout<<0<<" ";
    } else {
        if ((r1+c1) == (r2+c2) || (r1-c1) == (r2-c2)) {
            cout<<1<<" ";
        } else {
            cout<<2<<" ";
        }
    }
    // King
    if (r2 < r1) swap(r1,r2);
    int horizontal = r2-r1;
    if (c2 < c1) swap(c1,c2);
    int vertical = c2-c1;
    cout<<max(horizontal,vertical)<<"\n";

    return 0;
}