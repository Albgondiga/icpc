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

vector<vector<bool>> grid(7, vector<bool>(7,false));
string path;

// Dir para der, izq, arr, ab
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

#define right 0
#define left 1
#define up 2
#define down 3

bool isValid(ll x, ll y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7;
}

bool end(ll x, ll y) {
    return x == 6 && y == 0;
}

int getDir(char d) {
    if (d == 'R') {
        return right;
    } else if (d == 'L') {
        return left;
    } else if (d == 'U') {
        return up;
    } else if (d == 'D') {
        return down;
    }
}

void countPaths(ll x, ll y, int index, ll& count) {
    // Si se llega al final de la cadena  y a la posicion correcta
    if (index == 48) {
        if (end(x,y)) {
            count++;
        }
        return;
    }
    // Si se llega al final de forma prematura retorna
    if (end(x,y)) 
        return;
    // Si ya paso por ahi, retorna
    if (grid[x][y])
        return;

    // Celdas vecinas
    vector<bool> visited(4, -1);
    for (int i = 0; i < 4; i++)
        if (isValid(x+dx[i],y+dy[i]))
            visited[i] = grid[x+dx[i]][y+dy[i]];

    // Particiones:
    // No he ido arriba ni abajo pero si izq y der
    if (!visited[down] && !visited[up] && visited[right]
        && visited[left])
        return;
    // No he ido izq y der pero sí arriba y abajo
    if (!visited[right] && !visited[left] && visited[down]
        && visited[up])
        return;

    // ME FALTARON ESTOS CASOS (por eso me daba TLE):

    // If we are at a position such that the upper-right
    // diagonal square is visited and the up and right
    // squares are unvisited return 0
    if (isValid(x-1,y+1) && grid[x-1][y+1])
        if (!visited[right] && !visited[up])
            return;

    // If we are at a position such that the lower-right
    // diagonal square is visited and the down and right
    // squares are unvisited return 0
    if (isValid(x+1,y+1) && grid[x+1][y+1])
        if (!visited[right] && !visited[down])
            return;

    // If we are at a position such that the upper-left
    // diagonal square is visited and the up and left
    // squares are unvisited return 0
    if (isValid(x-1,y-1) && grid[x-1][y-1])
        if (!visited[left] && !visited[up])
            return;

    // If we are at a position such that the lower-left diagonal
    // square is visited and the down and right squares are
    // unvisited return 0
    if (isValid(x+1,y-1) && grid[x+1][y-1])
        if (!visited[left] && !visited[down])
            return;

    // Si no, continua
    grid[x][y] = true;
    if (path[index] == '?') {
        forn(i,4) {
            if (isValid(x+dx[i],y+dy[i])) {
                countPaths(x+dx[i],y+dy[i],index+1,count);
            }
        }
    } else {
        int dir = getDir(path[index]);
        if (isValid(x+dx[dir],y+dy[dir])) {
            countPaths(x+dx[dir], y+dy[dir], index+1, count);
        }
    }
    grid[x][y] = false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>path;
    ll count = 0;
    countPaths(0, 0, 0, count);
    cout<<count<<"\n";
}