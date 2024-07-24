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

string s;
int n;
map<int, int> match;
void parentesis(int l, int r, bool reverse) {
    while (l<=r) {
        if (!reverse) {
            if (s[l]=='(') {
                parentesis(l+1, match[l]-1, !reverse);
                l=match[l];
            }
            else cout<<s[l];
            l++;
            
        }
        else {
            if (s[r]==')') {
                parentesis(match[r]+1, r-1, !reverse);
                r=match[r];
            }
            else cout<<s[r];
            r--;
        }
    }
    
}

char toggle(char c) {
    if (debug) cout<<"me llegó para togglear "<<c<<", c-'A' = "<<c-'A'<<endl;

    if (c-'A'>26) c=toupper(c);
    else c=tolower(c);
    if (debug) cout<<"me quedó "<<c<<endl;
    return c;
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>s;
    n=s.size();
    int numOpen=0;

    // ok, el juego de las mayúsculas
    stack<int> st;
    forn(i, s.size()) {
        char c=s[i];
        if (c=='(') {
            numOpen++;
            st.push(i);
        }
        else if (c==')') {
            numOpen--;
            int x=st.top();
            st.pop();
            match[x]=i;
            match[i]=x;
        }
        else if (numOpen%2) s[i]=toggle(c);
    }


    if (debug) cout<<"s="<<s<<endl;

    parentesis(0, n-1, 0);    


}
