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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin>>n;
    vector<ll> songs(n);
    forn(i,n) cin>>songs[i];

    map<ll,ll> visited;
    ll m = 0, firstIndex = 0;
    forn (i,n) {
        if (visited.find(songs[i]) != visited.end()) {
            ifd cout<<"Repeated song, ";
            ifd cout<<"visited[i] = "<<visited[i]<<", ";
            if(visited[songs[i]] >= firstIndex) {
                firstIndex = visited[songs[i]] + 1;
                ifd cout<<"New FI = "<<firstIndex<<endl;
            }
        }
        visited[songs[i]] = i;
        m = max(m, i-firstIndex+1);
    }
    cout<<m<<"\n";
    return 0;
}