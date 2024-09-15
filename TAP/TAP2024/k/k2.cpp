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

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m); 
}

bool buscarT(int i, int j) {
    bool valid = false;
    if (isValid(i-4,j-1) and isValid(i-4,j+1)) {
        valid = true;
        for (int k = 1; k <= 4 && valid; k++) {
            if (grid[i-k][j] != '#' or usado[i-k][j]) valid = false;
        }
        if (valid) {
            if (grid[i-4][j-1] != '#' or usado[i-4][j-1]) valid = false;
            if (grid[i-4][j+1] != '#' or usado[i-4][j+1]) valid = false;
        }
    }
    if (valid) {
        T++;
        for (int k = 1; k <= 4 && valid; k++) {
            usado[i-k][j] = true;
        }
        usado[i-4][j-1] = true;
        usado[i-4][j+1] = true;
        usado[i][j] = true;
        return true;
    }
    return false;
}

bool buscarA(int i, int j) {
    bool valid = false;
    if (isValid(i-4,j-2)) {
        valid = true;
        for (int k = 1; k <= 4 && valid; k++) {
            if (grid[i-k][j] != '#' or usado[i-k][j]) valid = false;
            if (grid[i-k][j-2] != '#' or usado[i-k][j-2]) valid = false;
        }
        if (valid) {
            if (grid[i-4][j-1] != '#' or usado[i-4][j-1]) valid = false;
            if (grid[i-3][j-1] != '.' or usado[i-3][j-1]) valid = false;
            if (grid[i-2][j-1] != '#' or usado[i-2][j-1]) valid = false;
            if (grid[i-1][j-1] != '.' or usado[i-1][j-1]) valid = false;
            if (grid[i][j-1] != '.' or usado[i][j-1]) valid = false;
            if (grid[i][j-2] != '#' or usado[i][j-2]) valid = false;
        }
    }
    if (valid) {
        A++;
        for (int k = 1; k <= 4 && valid; k++) {
            usado[i-k][j] = true;
            usado[i-k][j-2] = true;
        }
        usado[i-4][j-1] = true;
        usado[i-2][j-1] = true;
        usado[i][j] = true;
        usado[i][j-2] = true;
        return true;
    }
    return false;
}

bool buscarP(int i, int j) {
    bool valid = false;
    if (isValid(i-4,j+2)) {
        valid = true;
        for (int k = 1; k <= 4 && valid; k++) {
            if (grid[i-k][j] != '#' or usado[i-k][j]) valid = false;
            if (k == 2) {
                if (grid[i-k][j+1] != '#' or usado[i-k][j+1]) valid = false;
                if (grid[i-k][j+2] != '#' or usado[i-k][j+2]) valid = false;
            } else if (k == 3) {
                if (grid[i-k][j+1] != '.' or usado[i-k][j+1]) valid = false;
                if (grid[i-k][j+2] != '#' or usado[i-k][j+2]) valid = false;
            } else if (k == 4) {
                if (grid[i-k][j+1] != '#' or usado[i-k][j+1]) valid = false;
                if (grid[i-k][j+2] != '#' or usado[i-k][j+2]) valid = false;
            }
        }
    }
    if (valid) {
        P++;
        for (int k = 1; k <= 4 && valid; k++) {
            usado[i-k][j] = true;
            if (k == 2) {
                usado[i-k][j+1] = true;
                usado[i-k][j+2] = true;
            } else if (k == 3) {
                usado[i-k][j+2] = true;
            } else if (k == 4) {
                usado[i-k][j+1] = true;
                usado[i-k][j+2] = true;
                usado[i][j] = true;
            }
        }
        return true;
    }
    return false;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    forn(i,n) forn(j,m) cin>>grid[i][j];
    T = A = P = 0;
    for (int j = m-1; j >= 0; j--) {
        for (int i = n-1; i >= 0; i--) {
            if (grid[i][j] == '#' and !usado[i][j]) {
                bool encontrado = buscarP(i,j);
                if (!encontrado) {
                    encontrado = buscarT(i,j);
                }
                if (!encontrado) {
                    encontrado = buscarA(i,j);
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
