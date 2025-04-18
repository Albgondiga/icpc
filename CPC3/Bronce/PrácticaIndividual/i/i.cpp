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

    ll N; cin>>N;
    ifd cout<<"N="<<N<<"\n";
    set<ll> leftNodes;
    stack<ll> s;
    //vector<vector<bool>> m(2*N+1, vector<bool>(2*N+1, false));
    map<ll,ll> m;
    forn(i,N) {
        ll A,B; cin>>A>>B;
        leftNodes.insert(min(A,B));
        ifd cout<<min(A,B)<<" es un nodo izquierdo y va hasta "
            <<max(A,B)<<"\n";
        //m[min(A,B)][max(A,B)] = true;
        m[min(A,B)] = max(A,B);
    }
    for(ll i = 1; i <= 2*N; i++) {
        if (leftNodes.find(i) != leftNodes.end()) {
            s.push(i);
        } else {
            if (!s.empty()) {
                // if (m[s.top()][i] == false)
                if (m.at(s.top()) != i) {
                    cout<<"Yes"<<"\n";
                    return 0;
                }
                s.pop();
            }
        }  
    }
    cout<<"No"<<"\n";
    return 0;
}
