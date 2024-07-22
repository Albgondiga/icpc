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
typedef pair<int,int> ii;
typedef pair<string, int> si;
typedef pair<ll,ll> pll;
#define dforn(i, n) for (int i=n-1; i>=0; i--)
#define dprint(v) cout<<#v"="<<v<<endl
const int MAXN=100100;

#define debug 1
#define ifd if (debug)

const int MAX = 1e3+5;
char steps[MAX][MAX];
char graph[MAX][MAX];
bool visited[MAX][MAX];
ii start, dest;
stack<char> ans;
int n, m;

const int dX[4] = {-1, 1, 0, 0};
const int dY[4] = {0, 0, -1, 1};
const char dir[4] = {'L','R','U','D'};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] != '#' && !visited[x][y]);
}

void backtrack(int x, int y) {
    if (steps[x][y] != 'X') {
        char ch = steps[x][y];
        ans.push(ch);
        // Move one cell up
        if (ch == 'U')
            backtrack(x + 1, y);
        // Move one cell down
        else if (ch == 'D')
            backtrack(x - 1, y);
        // Move one cell left
        else if (ch == 'L')
            backtrack(x, y + 1);
        // Move one cell right
        else if (ch == 'R')
            backtrack(x, y - 1);
    }
}


bool bfs(int x, int y) {
    steps[x][y] = 'X';

    queue<ii> q;
    q.push({ x, y });
    while (!q.empty()) {
        ii next = q.front();
        x = next.first;
        y = next.second;
        q.pop();
        // If we have reached the destination
        if (graph[x][y] == 'B') {
            backtrack(x, y);
            return true;
        }
        visited[x][y] = true;
        for (int k = 0; k < 4; k++) {
            if (isValid(x+dX[k], y+dY[k])) {
                visited[x+dX[k]][y+dY[k]] = true;
                steps[x+dX[k]][y+dY[k]] = dir[k];
                q.push({x+dX[k], y+dY[k]});
            }
        }
    }
    return false;
}

int main() {
    // Sample Input
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'A')
                start = { i, j };
            else if (graph[i][j] == 'B')
                dest = { i, j };
        }
    }


    if (bfs(start.first, start.second)) {
        cout << "YES" << endl << ans.size() << endl;
        while (!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
