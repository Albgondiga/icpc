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

#define debug 1
#define ifd if (debug)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, X; cin>>N>>X;
    vector<int> L(N+1);
    for (int i=1; i<N+1; i++){
        cin>>L[i];
    }

    vector<int> D(N+1);
    D[1] = 0;
    ll count = 1; // Contar D1
    for(int i=2; i<=N+1; i++){
        D[i] = D[i-1]+L[i-1];
        if (D[i] <= X) {
            count++;
        } else {
            break;
        }
    }
    cout << count << endl;
}