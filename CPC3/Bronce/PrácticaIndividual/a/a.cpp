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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    stack<int> stack;
    string s;
    while (cin>>s) {
        ifd cout<<"s = "<<s<<endl;
        if (s == "+") {
            int x, y;
            y = stack.top();
            stack.pop();
            x = stack.top();
            stack.pop();
            stack.push(x+y);
        } else if (s == "-") {
            int x, y;
            y = stack.top();
            stack.pop();
            x = stack.top();
            stack.pop();
            stack.push(x-y);
        } else if (s == "*") {
            int x, y;
            y = stack.top();
            stack.pop();
            x = stack.top();
            stack.pop();
            stack.push(x*y);
        } else {
            stack.push(stoi(s));
        }
    }
    cout<<stack.top()<<endl;
    return 0;
}
