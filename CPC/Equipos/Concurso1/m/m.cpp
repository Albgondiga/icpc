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
#define ifd if(debug)


int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int tC;
    cin>>tC;
    while (tC--) {
        ifd cout<<"CASO "<<endl;
        int n; cin>>n;
        vector<int> s(n), a(n);
        int sC=0, aC=0;
        forn(i, n) cin>>s[i];
        forn(i, n) cin>>a[i];
        
        forn(i, n) {
            if (s[i]==a[i]) continue;
            if (s[i]<0) aC++;
            else if (a[i]<0) sC++;
            else if (s[i]<a[i]) sC++;
            else aC++;
        }

        if (aC==sC) cout<<"Tie\n";
        else if (aC>sC) cout<<"Alfredo\n";
        else cout<<"Saboya\n";
    }


}
