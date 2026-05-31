#include <bits/stdc++.h>
using namespace std; 
#define forr(i, a, b) for (int i=a; i<b; i++)
#define forn(i, n) forr(i, 0, n)
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
#define fore(e,c) for(const auto &e : (c))
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define debug 1
#define ifd if (debug)

const int N = 5001;
const ll MOD = 1e9+7;
int n, m;
string s;

struct Trie {
	Trie* hijos[26]; // map<char,Trie> hijos
	int words, pref;
	Trie(): words(0), pref(0) { 
        for (int i = 0; i < 26; i++) hijos[i] = NULL;
    }
};
        
void add(Trie* node, string& word, int k) {
	if (k == (int)word.size()) {
		node->words++; node->pref++;
    } else {
		node->pref++; int ind = (int)(word[k] - 'a');
		if (node->hijos[ind] == NULL) {
			Trie* v = new Trie; 
            node->hijos[ind] = v;
        }
		add(node->hijos[ind], word, k+1);
    }
}

int search(Trie* node, string& word, int k){
	if (k == (int)word.size()) return (node->words);
	int ind = (int)(word[k] - 'a');
	if (node->hijos[ind] == NULL) return (0);
	else return search(node->hijos[ind], word, k+1);
}

ll dp[N];
ll f(Trie* root, int k) {
    if (k == n) return 1LL;
    if (dp[k] == -1) {
        ll count = 0;
        Trie* node = root;           // siempre reinicia desde la raíz
        for (int j = k; j < n; j++) {
            int ind = (int)(s[j] - 'a');
            if (node->hijos[ind] == NULL) break;
            node = node->hijos[ind];
            if (node->words > 0)     // encontró una palabra completa
                count += (f(root, j+1) % MOD);
                count %= MOD;
        }
        dp[k] = count;   
    }
    return dp[k];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin>>s>>m;
    n = (int)s.size();

    Trie trie;
    forn(i,m) {
        string t; cin>>t;
        add(&trie, t, 0);
    }

    forn(i,n) dp[i] = -1;
    f(&trie, 0);
    cout<<dp[0]<<"\n";

    return 0;
}
