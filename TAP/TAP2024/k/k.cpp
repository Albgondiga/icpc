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

ll A = 0, T = 0, P = 0;
int n, m;
char grid[MAX][MAX];
bool usado[MAX][MAX];

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m); 
}

bool bajar(int x, int y, int cantidad, int siguiente, string& cosos) {
    if (siguiente == cantidad-1) {
        if (grid[x][y] == cosos[siguiente]) {
            usado[x][y] = true;
            return true;
        }
        return false;
    }
    if (grid[x][y] == cosos[siguiente]) {
        if (isValid(x+1,y)) {
            bool seguir = bajar(x+1,y,cantidad,siguiente+1,cosos);
            if (seguir) {
                usado[x][y] = true;
                return true;
            } else {
                ifd cout<<"Fallo en "<<x+1<<" "<<y<<endl;
                ifd cout<<"Yo soy "<<grid[x][y]<<", el otro es "<<grid[x+1][y]<<endl;
            }
            return false;
        }
        return false;
    }
    return false;
}

bool buscarT(int x, int y) {
    string s = "####";
    if (bajar(x+1,y,4,0,s)) {
        usado[x][y] = true;
        usado[x][y-1] = true;
        usado[x][y+1] = true;
        T++;
        return true;
    }
    return false;
}
bool buscarA(int x, int y) {
    string s1 = "####";
    string s2 = ".#..";
    if (bajar(x+1,y-1,4,0,s1) && bajar(x+1,y,4,0,s2) &&
            bajar(x+1,y+1,4,0,s1)) {
        usado[x][y] = true;
        usado[x][y-1] = true;
        usado[x][y+1] = true;
        A++;
        return true;
    } else {
        for(int i = 1; i <= 4; i++) {
            if (isValid(x+i,y)) usado[x+i][y] = false;
            if (isValid(x+i,y-1)) usado[x+i][y-1] = false;
            if (isValid(x+i,y+1)) usado[x+i][y+1] = false;
        }
    }
    return false;
}
bool buscarP(int x, int y) {
    ifd cout<<"Buscar P en"<<x<<" "<<y<<endl;
    string s1 = "####";
    string s2 = ".#";
    string s3 = "##";
    if (bajar(x+1,y-1,4,0,s1) && bajar(x+1,y,2,0,s2)
            && bajar(x+1,y+1,2,0,s3)) {
        usado[x][y] = true;
        usado[x][y-1] = true;
        usado[x][y+1] = true;
        P++;
        return true;
    } else {
        for(int i = 1; i <= 4; i++) {
            if (isValid(x+i,y-1)) usado[x+i][y-1] = false;
            if (isValid(x+i,y+1)) usado[x+i][y+1] = false;
        }
        for(int i = 1; i <= 2; i++) {
            if (isValid(x+i,y)) usado[x+i][y] = false;
        }
    }
    return false;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    forn(x,n) forn(y,m) cin>>grid[x][y];
    // APT
    forn (x,n) {
        forn (y,m) {
            if (isValid(x,y-1) && isValid(x,y+1)) {
                if ((grid[x][y] == '#') && (grid[x][y-1] == '#') && (grid[x][y+1] == '#')) {
                    if (!usado[x][y] && !usado[x][y-1] && !usado[x][y+1]) {
                        bool encontrado = buscarA(x,y);
                        if (!encontrado) encontrado = buscarP(x,y);
                        if (!encontrado) encontrado = buscarT(x,y);
                    }
                }
            }
        }
    }

    ifd {
        cout<<"APT"<<endl;
        //valid = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout<<usado[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    // PAT
    bool valid = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                if (!usado[i][j]) valid = false;
            } 
            usado[i][j] = false;
        }
    }
    if (valid) {
        cout<<T<<" "<<A<<" "<<P<<"\n";
        return 0;
    }
    if (!valid) {
        T = A = P = 0;
        forn (x,n) {
            forn (y,m) {
                if (isValid(x,y-1) && isValid(x,y+1)) {
                    if ((grid[x][y] == '#') && (grid[x][y-1] == '#') && (grid[x][y+1] == '#')) {
                        if (!usado[x][y] && !usado[x][y-1] && !usado[x][y+1]) {
                            bool encontrado = buscarP(x,y);
                            if (!encontrado) encontrado = buscarA(x,y);
                            if (!encontrado) encontrado = buscarT(x,y);
                        }
                    }
                }
            }
        }
    }
    // ATP
    valid = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                if (!usado[i][j]) valid = false;
            } 
            usado[i][j] = false;
        }
    }
    if (valid) {
        cout<<T<<" "<<A<<" "<<P<<"\n";
        return 0;
    }
    if (!valid) {
        T = A = P = 0;
        forn (x,n) {
            forn (y,m) {
                if (isValid(x,y-1) && isValid(x,y+1)) {
                    if ((grid[x][y] == '#') && (grid[x][y-1] == '#') && (grid[x][y+1] == '#')) {
                        if (!usado[x][y] && !usado[x][y-1] && !usado[x][y+1]) {
                            bool encontrado = buscarA(x,y);
                            if (!encontrado) encontrado = buscarT(x,y);
                            if (!encontrado) encontrado = buscarP(x,y);
                        }
                    }
                }
            }
        }
    }
    // PTA
    valid = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                if (!usado[i][j]) valid = false;
            } 
            usado[i][j] = false;
        }
    }
    if (valid) {
        cout<<T<<" "<<A<<" "<<P<<"\n";
        return 0;
    }
    if (!valid) {
        T = A = P = 0;
        forn (x,n) {
            forn (y,m) {
                if (isValid(x,y-1) && isValid(x,y+1)) {
                    if ((grid[x][y] == '#') && (grid[x][y-1] == '#') && (grid[x][y+1] == '#')) {
                        if (!usado[x][y] && !usado[x][y-1] && !usado[x][y+1]) {
                            bool encontrado = buscarP(x,y);
                            if (!encontrado) encontrado = buscarT(x,y);
                            if (!encontrado) encontrado = buscarA(x,y);
                        }
                    }
                }
            }
        }
    }
    // TAP
    valid = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                if (!usado[i][j]) valid = false;
            } 
            usado[i][j] = false;
        }
    }
    if (valid) {
        cout<<T<<" "<<A<<" "<<P<<"\n";
        return 0;
    }
    if (!valid) {
        T = A = P = 0;
        forn (x,n) {
            forn (y,m) {
                if (isValid(x,y-1) && isValid(x,y+1)) {
                    if ((grid[x][y] == '#') && (grid[x][y-1] == '#') && (grid[x][y+1] == '#')) {
                        if (!usado[x][y] && !usado[x][y-1] && !usado[x][y+1]) {
                            bool encontrado = buscarT(x,y);
                            if (!encontrado) encontrado = buscarA(x,y);
                            if (!encontrado) encontrado = buscarP(x,y);
                        }
                    }
                }
            }
        }
    }
    // TPA
    valid = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                if (!usado[i][j]) valid = false;
            } 
            usado[i][j] = false;
        }
    }
    if (valid) {
        cout<<T<<" "<<A<<" "<<P<<"\n";
        return 0;
    }
    if (!valid) {
        T = A = P = 0;
        forn (x,n) {
            forn (y,m) {
                if (isValid(x,y-1) && isValid(x,y+1)) {
                    if ((grid[x][y] == '#') && (grid[x][y-1] == '#') && (grid[x][y+1] == '#')) {
                        if (!usado[x][y] && !usado[x][y-1] && !usado[x][y+1]) {
                            bool encontrado = buscarT(x,y);
                            if (!encontrado) encontrado = buscarP(x,y);
                            if (!encontrado) encontrado = buscarA(x,y);
                        }
                    }
                }
            }
        }
    }

    cout<<T<<" "<<A<<" "<<P<<"\n";
    return 0;
}
