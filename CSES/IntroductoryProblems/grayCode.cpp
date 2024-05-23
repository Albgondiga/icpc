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

/*
Idea: n = 3
Tengo 11 10 00 01, al reves es 01 00 10 11
Si considero 01 00 10 11 11 10 00 01, puedo
añadirle un 0/1 antes a cada mitad y diferencia
de uno se mantiene. Igual con el pegue
*/

vector<string> createCode(int n) {
    if (n == 1) { return {"0","1"}; }

    vector<string> previous = createCode(n - 1);
    vector<string> reversed = previous;
    reverse(reversed.begin(), reversed.end());
    int s = previous.size();

    for (int i = 0; i < s; i++) {
        // 0 al inicio
        string plusZero = "1" + previous[i];
        // 1 al inicio en al reves
        previous[i] = "0" + reversed[i];
        previous.push_back(plusZero);
    }
    return previous;
}

int main() {
    int n; cin>>n;
    vector<string> grayCode = createCode(n);
    for (auto code:grayCode)
        cout<<code<<"\n";
    return 0;
}
