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
    ll n, m, t; cin>>n>>m;
    t=n+m;
    ll a, b, q; cin>>a>>b;
    q=a+b;
    ll A= (n+m)*(a*m+b*n);
    if (debug) cout<<"A="<<A;
    ll B= 2*n*m*(a+b);

    if (debug) cout<<"B="<<B;
    if (A>B) cout<<"A"<<endl;
    else if (A<B) cout<<"B"<<endl;
    else cout<<"C"<<endl;

}
