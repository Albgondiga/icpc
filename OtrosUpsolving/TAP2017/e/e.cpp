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

    vector<int> v(3);
    forn(i,3) cin>>v[i];
    sort(v.begin(), v.end());
    int a = v[0];
    int b = v[1];
    int c = v[2];

    ifd cout<<a<<" "<<b<<" "<<c<<endl;
    if ((a == 1) && ((b == 2)||(b==3))) {
        cout<<"S\n";
    } else if ((a == 2) && (b == 3) && (c == 4)) {
        cout<<"S\n";
    } else if ((a == 1) && (b == 4) && (c == 5)) {
        cout<<"S\n";
    } else {
        cout<<"N\n";
    }
}