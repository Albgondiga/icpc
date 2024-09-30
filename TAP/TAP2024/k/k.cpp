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
    return (i >= 0 and i < n and j >= 0 and j < m); 
}

bool buscarT(int i, int j) {
    if (isValid(i+4,j-2)) {
        bool valid = true;
        for (int k = 0; k <= 4 and valid; k++) {
            if (grid[i+k][j-1] != '#' or usado[i+k][j-1]) valid = false;
        }
        if (grid[i][j] != '#' or usado[i][j]) valid = false;
        if (grid[i][j-2] != '#' or usado[i][j-2]) valid = false;
        if (valid) {
            T++;
            for (int k = 0; k <= 4 and valid; k++) {
                usado[i+k][j-1] = true;
            }
            usado[i][j] = true;
            usado[i][j-2] = true;
            return true;
        }
        return false;
    }
    return false;
}

bool buscarA(int i, int j) {
    if (isValid(i-4,j-2)) {
        bool valid = true;
        for (int k = 0; k <= 4 and valid; k++) {
            if (grid[i-k][j] != '#' or usado[i-k][j]) valid = false;
            if (grid[i-k][j-2] != '#' or usado[i-k][j-2]) valid = false;
        }
        if (grid[i-4][j-1] != '#' or usado[i-4][j-1]) valid = false;
        if (grid[i-2][j-1] != '#' or usado[i-2][j-1]) valid = false;
        if (valid) {
            A++;
            for (int k = 0; k <= 4 and valid; k++) {
                usado[i-k][j] = true;
                usado[i-k][j-2] = true;
            }
            usado[i-4][j-1] = true;
            usado[i-2][j-1] = true;
            return true;
        }
        return false;
    }
    return false;
}

bool buscarP(int i, int j) {
    if (isValid(i-2,j-2) and isValid(i+2,j-2)) {
        bool valid = true;
        for (int k = 0; k <= 4 and valid; k++) {
            if (grid[i+2-k][j-2] != '#' or usado[i+2-k][j-2]) valid = false;
        }
        for (int k = 0; k <= 2 and valid; k++) {
            if (grid[i-k][j] != '#' or usado[i-k][j]) valid = false;
        }
        if (grid[i][j-1] != '#' or usado[i][j-1]) valid = false;
        if (grid[i-2][j-1] != '#' or usado[i-2][j-1]) valid = false;
        if (valid) {
            P++;
            for (int k = 0; k <= 4 and valid; k++) {
                usado[i+2-k][j-2] = true;
            }
            for (int k = 0; k <= 2 and valid; k++) {
                usado[i-k][j] = true;
            }
            usado[i][j-1] = true;
            usado[i-2][j-1] = true;
            return true;
        }
        return false;
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
                bool encontrado = buscarT(i,j);
                if (!encontrado) {
                    encontrado = buscarA(i,j);
                }
                if (!encontrado) {
                    encontrado = buscarP(i,j);
                }
            }
        }
    }

    cout<<T<<" "<<A<<" "<<P<<"\n";
    return 0;
}
