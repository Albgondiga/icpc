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

    int n;
    cin>>n;
    vector<int> x(n), y(n), r(n);

    forn(i, n) cin>>x[i]>>y[i]>>r[i];
    bool won=false;
    for (int i=0; i<n&&!won; i++) {
        int x1=x[i], y1=y[i], r1=r[i];
        for (int j=i+1; j<n&&!won; j++) {
            int x2=x[j], y2=y[j], r2=r[j];
            if (debug) cout<<"estoy fijándome en ("<<x1<<", "<<y1<<", r="<<r1<<") vs ("<<x2<<", "<<y2<<", r="<<r2<<")"<<endl;
            ll val1=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            if (debug) cout<<"la distancia entre los puntos al cuadrado es "<<val1<<endl;
            if ((val1<(r2-r1)*(r2-r1))) {
                if (debug) cout<<"uno está dentro de otro!"<<endl;
                continue;
                
            }
            ll val2=(r1+r2)*(r1+r2);
            if (debug) cout<<"la distancia entre los centros es "<<val1<<" y la distancia entre los radios es "<<val2<<endl;
            if (val1<=val2) {
                if (debug) cout<<"SE INTERSECAN!!"<<endl;
                won=true;
            }
            
        }
    }

    if (won) cout<<"NO"<<endl;
    else cout<<"SI"<<endl;


}
