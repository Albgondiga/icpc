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

ii nextPos(char dir, ii pos) {
    if (dir == 'U') {
        return make_pair(pos.first-1,pos.second);
    } else if (dir == 'D') {
        return make_pair(pos.first+1,pos.second);
    } else if (dir == 'L') {
        return make_pair(pos.first,pos.second-1);
    } else if (dir == 'R') {
        return make_pair(pos.first,pos.second+1);
    }
}

bool isValid(ii pos) {
    return pos.first >= 1 && pos.first <= 7
        && pos.second >= 1 && pos.second <= 7;
}

bool end(ii pos) {
    return pos.first == 7 & pos.second == 1;
}

void countPaths(string& path, ii pos, int index, ll& count, vector<vector<bool>>& grid) {
    // Si se llega al final de la cadena  y a la posicion correcta
    if (index == 48) {
        if (end(pos)) {
            count++;
            ifd cout<<"count++\n";
            forn(i,7) {
                forn(j,7) {
                    cout<<grid[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        return;
    }
    // Si se llega al final de forma prematura retorna
    if (end(pos)) 
        return;
    // Si ya paso por ahi, retorna
    if (grid[pos.first-1][pos.second-1])
        return;
    // Si no, continua
    grid[pos.first-1][pos.second-1] = true;
    if (path[index] == '?') {
        ii newPos = nextPos('U', pos);
        if (isValid(newPos) && grid[newPos.first-1][newPos.second-1] == false)
            countPaths(path, newPos, index+1, count, grid);
        
        newPos = nextPos('D', pos);
        if (isValid(newPos) && grid[newPos.first-1][newPos.second-1] == false)
            countPaths(path, newPos, index+1, count, grid);

        newPos = nextPos('L', pos);
        if (isValid(newPos) && grid[newPos.first-1][newPos.second-1] == false)
            countPaths(path, newPos, index+1, count, grid);

        newPos = nextPos('R', pos);
        if (isValid(newPos) && grid[newPos.first-1][newPos.second-1] == false)
            countPaths(path, newPos, index+1, count, grid);
    } else {
        ii newPos = nextPos(path[index], pos);
        // ifd cout<<path[index]<<" => "<<"["<<newPos.first<<"]"<<"["<<newPos.second<<"]"<<"\n";
        if (isValid(newPos) && grid[newPos.first-1][newPos.second-1] == false)
            countPaths(path, newPos, index+1, count, grid);
    }
    grid[pos.first-1][pos.second-1] = false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<vector<bool>> grid(7, vector<bool>(7,false));
    forn(i,7) {
        forn(j,7) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    string path; cin>>path;
    ll count = 0;
    countPaths(path, make_pair(1,1), 0, count, grid);
    cout<<count<<"\n";
}