#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
#define fore(e,c) for(const auto &e : (c))
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 1000;
int n, m;
char M[N][N], T[N][N], B[N][N];

bool match(int i, char a, char b) {
    bool ans = true;
    forn(j,m) {
        if ((j % 2) == 0) {
            if (M[i][j] == '?' or M[i][j] == a) continue;
        } else {
            if (M[i][j] == '?' or M[i][j] == b) continue;
        }
        ans = false;
        break;
    }
    if (ans) {
        forn(j,m) {
            if ((j % 2) == 0) M[i][j] = a;
            else M[i][j] = b;
        }
    }
    return ans;
}

/*
cici/icic
cpcp/pcpc
*/
bool uno() {
    bool ans = true;
    forn(i,n) {
        if ((i % 2) == 0) {
            if (match(i, 'C', 'I') or match(i, 'I', 'C')) continue;
        } else {
            if (match(i, 'C', 'P') or match(i, 'P', 'C')) continue;
        }
        ans = false;
        break;
    }
    return ans;
}

/*
cpcp/pcpc
cici/icic
*/
bool dos() {
    bool ans = true;
    forn(i,n) {
        if ((i % 2) == 0) {
            if (match(i, 'C', 'P') or match(i, 'P', 'C')) continue;
        } else {
            if (match(i, 'C', 'I') or match(i, 'I', 'C')) continue;
        }
        ans = false;
        break;
    }
    return ans;
}

/*
cccc
ipip/pipi
*/
bool tres() {
    bool ans = true;
    forn(i,n) {
        if ((i % 2) == 0) {
            if (match(i, 'C', 'C')) continue;
        } else {
            if (match(i, 'P', 'I') or match(i, 'I', 'P')) continue;
        }
        ans = false;
        break;
    }
    return ans;
}

/*
ipip/pipi
cccc
*/
bool cuatro() {
    bool ans = true;
    forn(i,n) {
        if ((i % 2) == 0) {
            if (match(i, 'P', 'I') or match(i, 'I', 'P')) continue;
        } else {
            if (match(i, 'C', 'C')) continue;
        }
        ans = false;
        break;
    }
    return ans;
}

void limpiar() {                            
    forn(i,n) forn(j,m) M[i][j] = B[i][j];
}

bool solve() {                       
    forn(i,n) forn(j,m) B[i][j] = M[i][j];
    limpiar(); if (uno()) return true;
    limpiar(); if (dos()) return true;
    limpiar(); if (tres()) return true;
    limpiar(); if (cuatro()) return true;
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int tC; cin>>tC;
    while (tC--) {
        cin>>n>>m;
        forn(i,n) forn(j,m) {
            cin>>M[i][j];
            T[j][i] = M[i][j];
        }

        if (solve()) {
            cout<<"yes\n";
            forn(i,n) {
                forn(j,m) cout<<M[i][j];
                cout<<"\n";
            }
            continue;
        }

        swap(n,m);
        forn(i,n) forn(j,m) {
            M[i][j] = T[i][j];
        }
        if (solve()) {
            cout<<"yes\n";
            forn(i,m) {
                forn(j,n) cout<<M[j][i];
                cout<<"\n";
            }
        }
        else cout<<"no\n";
    }

    return 0;
}
