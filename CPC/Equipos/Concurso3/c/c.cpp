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
    vector<int> v(n);
    vector<int> apariciones(1e6+5);
    vector<bool> seen(1e6+5);
    forn(i, n) {
        cin>>v[i];
        apariciones[v[i]]++;
    }
    sort(v.begin(), v.end());
    vector<bool> sieve(1e6+5);
    for (int x:v) {
        if (seen[x]) continue;
        seen[x]=true;
        if (debug) cout<<"me estoy fijando en "<<x<<" y marco sus múltiplos"<<endl;
        if (sieve[x]) continue;

        for (int u=2*x; u<=1e6+5; u+=x) sieve[u]=1;
    }
    int result=0;
    for (int i=0; i<n; i++) {
        if (apariciones[v[i]]>1) continue;
        if (!sieve[v[i]]) result++;
    }

    cout<<result<<endl;


}
