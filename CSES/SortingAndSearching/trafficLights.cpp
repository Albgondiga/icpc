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

    ll x, n; cin >> x >> n;
    
    set<pll> passages;
    multiset<ll> lengths;
    passages.insert({0,x});
    lengths.insert(x);

    forn (i,n) {
        ll lights; cin>>lights;
        // Passage donde estan los semaforos
        auto it = passages.upper_bound({lights, 0});
        it--;
        // Partir el passage
        ll start = (*it).first;
        ll end = (*it).second;
        passages.erase(it);
        lengths.erase(lengths.find(end-start));

        passages.insert({start, lights});
        passages.insert({lights, end});
        lengths.insert(lights-start);
        lengths.insert(end-lights);

        cout<<*(lengths.rbegin())<<" ";
    }
    cout<<"\n";
    return 0;
}