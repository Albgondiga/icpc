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

#define debug 0
#define ifd if (debug)

string isBalanced(string s) {
    stack<char> stack;
    int l = s.length();
    for (int i=0; i < l; i++) {
        if (!stack.empty() && (
                   (s[i] == ')' && stack.top() == '(')
                || (s[i] == ']' && stack.top() == '[')
                || (s[i] == '}' && stack.top() == '{')
        )) {
            stack.pop();
        } else {
            stack.push(s[i]);
        }
    }
    if (stack.empty()) return "YES";
    return "NO";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;

    forn(i,n) {
        string s; cin>>s;
        ifd cout<<"s="<<s<<endl;   
        if (s.length() % 2) {
            cout<<"NO"<<"\n";
        } else {
            cout<<isBalanced(s)<<"\n";
        }
    }
    return 0;
}