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

#define debug 1
#define ifd if (debug)

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    ll maxR=-1;

    ll aF, bF, cF;
    vector<int> v(n);
    forn(i,n) cin>>v[i];
    forn(i, n) {
        ll a=v[i];
        forn(j, n) {
            ll b=v[j];
            forn(k, n) {
                ll c=v[k];
                ll cA=a*a+b*b+c*c-a*b-a*c-b*c;
                if (cA>maxR) {
                    maxR=cA;
                    aF=a;
                    bF=b;
                    cF=c;
                }

            }
        }
    }


    cout<<"("<<aF<<", "<<bF<<", "<<cF<<")\n";
    cout<<"maxR="<<maxR<<endl;

}