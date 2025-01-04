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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 1001;
int t, a, b;
vector<int> factors[N];

void factorizar(vector<int>& fact, const int n) {
    int n2 = n;
    for (int d = 2; d*d <= n2; d++) {
        if (n2 % d == 0) fact.push_back(d);
        while (n2 % d == 0) {
            n2 /= d;
        }
    }
    if (n2 > 1 and n2 != n) fact.push_back(n2);
}

int bfs(int n, int m) {
    if (n == m) return 0;
    
    queue<int> q;
    bool visited[N] = {0};
    int dist[N] = {0};
    visited[n] = true;
    dist[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto d : factors[s]) {

            if (s+d == m) return dist[s]+1;
            
            else if (s+d < m) {
                if (visited[s+d]) continue;
                visited[s+d] = true;
                dist[s+d] = dist[s]+1;
                q.push(s+d);
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for (int n = 1; n <= 1000; n++)
        factorizar(factors[n], n);

    cin>>t;
    for (int i = 1; i <= t; i++) {
        cin>>a>>b;
        cout<<"Case "<<i<<": "<<bfs(a,b)<<"\n";
    }

    return 0;
}
