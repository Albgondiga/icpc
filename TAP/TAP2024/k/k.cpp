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

const int MAX = 1000;

ll T, A, P;
int n, m;
char grid[MAX][MAX];
bool usado[MAX][MAX];

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m); 
}

bool buscarT(int x, int y) {
    bool valid = false;
    if (isValid(x-4,y-1) and isValid(x-4,y+1)) {
        valid = true;
        for (int k = 1; k <= 4 && valid; k++) {
            if (grid[x-k][y] != '#') valid = false;
        }
        if (valid) {
            if (grid[x-4][y-1] != '#') valid = false;
            if (grid[x-4][y+1] != '#') valid = false;
        }
    }
    if (valid) {
        T++;
        for (int k = 1; k <= 4 && valid; k++) {
            usado[x-k][y] = true;
        }
        usado[x-4][y-1] = true;
        usado[x-4][y+1] = true;
        usado[x][y] = true;
    }
    if (valid) return true;
    return false;
}

bool buscarA(int x, int y) {
    bool valid = false;
    if (isValid(x-4,y-2)) {
        valid = true;
        for (int k = 1; k <= 4 && valid; k++) {
            if (grid[x-k][y] != '#') valid = false;
            if (grid[x-k][y-2] != '#') valid = false;
        }
        if (valid) {
            if (grid[x-4][y-1] != '#') valid = false;
            if (grid[x-2][y-1] != '#') valid = false;
            if (grid[x][y-2] != '#') valid = false;
        }
    }
    if (valid) {
        A++;
        for (int k = 1; k <= 4 && valid; k++) {
            usado[x-k][y] = true;
            usado[x-k][y-2] = true;
        }
        usado[x-4][y-1] = true;
        usado[x-2][y-1] = true;
        usado[x][y] = true;
        usado[x][y-2] = true;
    }
    if (valid) return true;
    return false;
}

bool buscarP(int x, int y) {
    bool valid = false;
    if (isValid(x-4,y+2)) {
        valid = true;
        for (int k = 1; k <= 4 && valid; k++) {
            if (grid[x-k][y] != '#') valid = false;
            if (k == 2) {
                if (grid[x-k][y+1] != '#') valid = false;
                if (grid[x-k][y+2] != '#') valid = false;
            } else if (k == 3) {
                if (grid[x-k][y+2] != '#') valid = false;
            } else if (k == 4) {
                if (grid[x-k][y+1] != '#') valid = false;
                if (grid[x-k][y+2] != '#') valid = false;
            }
        }
    }
    if (valid) {
        P++;
        for (int k = 1; k <= 4 && valid; k++) {
            usado[x-k][y] = true;
            if (k == 2) {
                usado[x-k][y+1] = true;
                usado[x-k][y+2] = true;
            } else if (k == 3) {
                usado[x-k][y+2] = true;
            } else if (k == 4) {
                usado[x-k][y+1] = true;
                usado[x-k][y+2] = true;
                usado[x][y] = true;
            }
        }
    }
    if (valid) return true;
    return false;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    forn(x,n) forn(y,m) cin>>grid[x][y];
    T = A = P = 0;
    // APT
    for (int x = n-1; x >= 0; x--) {
        for (int y = m-1; y >= 0; y--) {
            if (grid[x][y] == '#' and !usado[x][y]) {
                bool encontrado = buscarP(x,y);
                ifd if (encontrado) cout<<"Encontre una P en "<<x<<" "<<y<<endl;
                if (!encontrado) {
                    encontrado = buscarA(x,y);
                    ifd if (encontrado) cout<<"Encontre una T en "<<x<<" "<<y<<endl;
                }
                if (!encontrado) {
                    encontrado = buscarT(x,y);
                    ifd if (encontrado) cout<<"Encontre una A en "<<x<<" "<<y<<endl;
                }
            }
        }
    }

    ifd {
        forn(i,n) {
            forn(j,m) {
                cout<<usado[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    cout<<T<<" "<<A<<" "<<P<<"\n";
    return 0;
}
