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

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s; cin>>s;
    bool possible = true;
    bool primeraE = true;
    int fRacha = 0, fOtro = 0;
    for (auto c : s) {
        ifd cout<<"fRacha = "<<fRacha<<", fOtro = "<<fOtro<<endl;
        if (c == 'F') {
            if (primeraE) {
                fRacha++;
            } else {
                fOtro++;
            }
        } else {
            if (primeraE) primeraE = false;
            if (fOtro) {
                fOtro--;
            } else if (fRacha) {
                fRacha--;
            } else {
                possible = false; 
                break;
            }
        }
    }

    if (possible) cout<<fRacha<<"\n";
    else cout<<"I cry\n";

    return 0;
}
