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

ll digit(int x) {
    if (x==1) return 4;
    if (x==2) return 6;
    switch ((x-2) % 8){
        case 1:
            return 2; 
            break;
        case 2:
            return 4; 
            break;
        case 3:
            return 8; 
            break;
        case 4:
            return 3; 
            break;
        case 5:
            return 2; 
            break;
        case 6:
            return 6; 
            break;
        case 7:
            return 1; 
            break;
        default:
            return 2;
            break;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll x, y, z, w;
    cin>>x>>y>>z>>w;
    cout<<digit(x)<<digit(y)<<digit(z)<<digit(w)<<"\n";
    return 0;
}