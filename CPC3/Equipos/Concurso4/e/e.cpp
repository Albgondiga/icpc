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
#define ifd if (debug)

ll n, w, a;
string s;


void ventana(ll& tiempo) {
    tiempo += (w/2)*2;
    tiempo += 10;
    w--;
}

void aisle(ll& tiempo) {
    tiempo += (a/2)*2;
    tiempo += 5;
    a--;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>s;
    w = a = (2*n - 1);

    ll tiempo = 0;

    for (auto p : s) {
        ifd cout<<"w = "<<w<<", a = "<<a<<endl;
        if (p == 'I') {
            if (w >= 0) {
                ifd cout<<"I va a ventana "<<w<<endl;
                ventana(tiempo);
            } else {
                ifd cout<<"I va a aisle "<<a<<endl;
                aisle(tiempo);
            }
        } else {
            if (w >= 0 && (w/2 >= a/2)) {
                ifd cout<<"E va a ventana "<<w<<endl;
                ventana(tiempo);
            } else {
                ifd cout<<"E va a aisle "<<a<<endl;
                aisle(tiempo);
            }
        }
        ifd cout<<tiempo<<endl;
    }

    cout<<tiempo<<"\n";
    
    return 0;
}
