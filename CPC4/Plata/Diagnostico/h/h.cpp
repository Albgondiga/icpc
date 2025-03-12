#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

struct node {
    unordered_map<int, int> nxt;
    int tam;
    int count;
    node() : tam(0), count(0) {}
};

void Add(vector<node>& Trie, string& s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i];
        if (!Trie[cur].nxt.count(c)) {
            Trie[cur].tam++;
            Trie[cur].nxt[c] = Trie.size();
            Trie.emplace_back();
        }
        cur = Trie[cur].nxt[c];
    }
}

int n;
const int N = 1e5+1;
string s[N];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while(cin>>n) {
        vector <node> Trie(1);
        for (int i = 1; i <= n; i++) {
            cin>>s[i];
            s[i] += ('z' + 1);
            Add(Trie, s[i]);
        }

        long double sol = 0;

        for (int i = 1; i <= n; i++) {
            string& t = s[i];
            int cur = Trie[0].nxt[t[0]];
            sol++;
            for (int j = 1; j+1 < t.size(); j++) {
                if (Trie[cur].tam != 1)
                    sol++;
                cur = Trie[cur].nxt[t[j]];
            }
        }
        sol /= (.0 + n);
        cout<<setprecision(2)<<fixed;
        cout<<sol<<"\n";
    }
    
    return 0;
}
