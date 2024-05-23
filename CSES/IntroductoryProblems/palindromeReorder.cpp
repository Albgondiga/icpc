#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int l = s.length();
    int next = 0;

    string p(l,'0');
    for (int i = 0; i < l; i++) {
        if (s[i] != '0') {
            bool found = false;
            for (int j = i+1; j < l && !found; j++) {
                if (s[i] == s[j]) {
                    p[next] = s[i], p[l-(next+1)] = s[i];
                    s[i] = '0', s[j] = '0';
                    next++;
                    found = true;
                }
            }
            if (!found) {
                if (l % 2 == 0) {
                    cout << "NO SOLUTION" << endl;
                    return 0;
                } else if (p[l/2] == '0') {
                    p[l/2] = s[i];
                    s[i] = '0';
                } else {
                    cout << "NO SOLUTION" << endl;
                    return 0;
                }
            }
        }
    }
    for (auto i : p) {
        cout << i;
    }
    cout << endl;
    return 0;
}