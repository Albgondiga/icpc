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
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;
#define mp make_pair

#define debug 1
#define ifd if (debug)

void hanoi(int n, vector<ii>& moves, int src, int d, int aux) {
    if (n == 1) {
        moves.pb(mp(src,d));
        return;
    }
    hanoi(n-1, moves, src, aux, d);
    moves.pb(mp(src,d));
    hanoi(n-1, moves, aux, d, src);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<ii> moves;
    hanoi(n, moves, 1, 3, 2);
    cout<<moves.size()<<"\n";
    for (auto m:moves)
        cout<<m.first<<" "<<m.second<<"\n";
    return 0;
}