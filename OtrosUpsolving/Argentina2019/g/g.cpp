// 
#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 0


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    ll io; cin>>io;
    if (debug) cout<<"yo soy "<<io<<endl;
    vector<int> v(n-1);
    forn(i, n-1) cin>>v[i];
    sort(v.begin(), v.end());
    queue<int> q;
    for (auto u:v) q.push(u);
    int numMaesVivos=n-1;
    while(numMaesVivos>0&&io>=0) {
        if (debug) cout<<"ahorita mismo soy "<<io<<endl;
        ll current=q.front();
        q.pop();
        if (current>io) {
            io=-1;
            continue;
        }
        if (debug) cout<<"saqué a "<<current<<endl;
        ll res=(current-1)*numMaesVivos+(numMaesVivos-1);
        if (debug) cout<<"de donde mi res es "<<res<<endl;
        numMaesVivos--;
        io-=res;
    }
    if (io>=0) cout<<"SI"<<endl;
    else cout<<"NO"<<endl;
}
