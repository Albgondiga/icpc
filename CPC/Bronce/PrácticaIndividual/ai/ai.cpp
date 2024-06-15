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

const int N = 100;
const int M = 150;

int C[N + 1];  // colores
pair<int, int> E[M + 1];

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);

  int n, m; cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);  // menor siempre primero
    E[i] = {a, b};
  }
  
  for (int v = 1; v <= n; v++) {
    for (int color = 1; color <= 4; color++) {
      bool flag = true;  // si se puede usar color actual
      for (int i = 0; i < m; i++) {
        if (E[i].second == v) {
          if (C[E[i].first] == color)
            flag = false;  // v ya tiene adyacente con ese color
        }
      }
      
      if (flag) {
        C[v] = color;
        break;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << C[i];
  }
  cout << "\n";
}