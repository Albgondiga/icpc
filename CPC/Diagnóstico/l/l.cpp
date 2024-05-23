#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int i = 0;
    int count = 0;
    while (i < s.length()) {
        if (s[i] == s[i+1]) {
            s = s.erase(i+1,1);
            count++;
        } else {
            if (count > 0 && count % 2 != 0) {
                s = s.erase(i,1);
                if (i > 0) i--;
            } else {
                i++;
            }
            count = 0;
        }
    }
    cout << s << endl;
    return 0;
}