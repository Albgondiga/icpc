#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it=v.begin(); it!=v.end(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

const int MAX = 1e3 + 5;

vector <int> factor[MAX];
int s, t, d[MAX];

void bfs() {
    memset(d, -1, sizeof d);
    cin >> s >> t;

    d[s] = 0;

    queue <int> q;
    q.push(s);

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int to : factor[x]) {
            if(x + to < MAX && d[x + to] == -1) {
                d[x + to] = d[x] + 1;
                q.push(x + to);
            }
        }
    }

    cout << d[t] << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for(int i = 2; i < MAX; i++) {
        if(!factor[i].size())
            for(int j = 2 * i; j < MAX; j += i)
                factor[j].push_back(i);
    }

    int tc;
    cin >> tc;

    for(int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        bfs();
    }
}