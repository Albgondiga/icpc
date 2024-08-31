#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

ll kmp(string s, string t) {
    t = t+'#';
    vector<int> pi = prefix_function(t);

    for (auto i : pi) cout<<i<<" ";
    cout<<endl;

    int n = (int)s.length(), m = (int)t.length()-1;
    ll count = 0, prev = 0;
    for (int i = 0; i < n; i++) {
        ll l = prev;
        while ((l > 0) && (s[i] != t[l])) {
            l = pi[l-1];
        }
        if (s[i] == t[l]) {
            l++;
            prev = l;
        }
        if (l == m) {
            count++;
        }
    }
    return count;
}

int main() {
    string s = "baacabacabacabb", t = "acabaca";
    cout<<kmp(s,t)<<endl;
    return 0;
}