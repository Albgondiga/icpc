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

// Direccions para der, izq, arriba, abajo
ll dx[4] = { 0, 0, -1, 1 };
ll dy[4] = { 1, -1, 0, 0 };

ll r, c;

bool isValid(ll x, ll y) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

bool wolfAdj(ll x, ll y, vector<vector<char>>& v) {
    ll count = 0;
    forn(i,4) {
        if (isValid(x+dx[i],y+dy[i])) {
            if (v[x+dx[i]][y+dy[i]] == 'W') {
                return true;
            } else if (v[x+dx[i]][y+dy[i]] == '.') {
                v[x+dx[i]][y+dy[i]] = 'D';
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    vector<vector<char>> v(r, vector<char>(c));
    forn(i,r) {
        forn(j,c) {
            cin>>v[i][j];
        }
    }
    forn(i,r) {
        forn(j,c) {
            if (v[i][j] == 'S') {
                if (wolfAdj(i,j,v)) {
                    cout<<"No"<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"Yes\n";
    forn(i,r) {
        forn(j,c) {
            cout<<v[i][j];
        }
        cout<<"\n";
    }
    return 0;
}