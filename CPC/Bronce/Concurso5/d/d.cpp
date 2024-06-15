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

#define debug 0
#define ifd if (debug)
#define N 20
#define M 400

vector<set<int>> rest(N+1);
int taken[N+1] = { 0 };

void countPizzas (int v, int n, ll& count) {
    if (v > n) {
        ifd cout<<"Nueva combinacion: ";
        count++;
        ifd {
            for (int i = 0; i <= n; i++) {
                if (taken[i])
                    cout<<i<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // No tomar ingrediente
    countPizzas(v+1,n,count);
    // Tomar ingrediente si es posible
    bool canTake = true;
    for (auto s : rest[v]) {
        if (taken[s]) {
            ifd cout<<"Ya se agarro "<<s<<", que es restriccion de "<<v<<endl;
            canTake = false;
            break;
        }
    }
    if (canTake) {
        //ifd cout<<"Take "<<v<<endl;
        taken[v] = true;
        countPizzas(v+1, n, count);
        taken[v] = false;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    forn(i,m) {
        int a, b; cin>>a>>b;
        rest[a].insert(b);
        rest[b].insert(a);
    }
    ll count = 0;
    countPizzas(1, n, count);
    cout<<count<<"\n";
    return 0;
}