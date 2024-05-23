#include <bits/stdc++.h>

using namespace std;

int main() {
    int max = 1, count = 1;
    string s;
    cin >> s;
    int l = s.length();
    for (int i = 1; i <= l; i++) {
        if (s[i] == s[i-1]) {
            count++;
        } else {
            if (count > max)
                max = count;
            count = 1;
        }
    }
    cout << max << endl;
    return 0;
}