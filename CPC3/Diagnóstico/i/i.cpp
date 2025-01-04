#include <bits/stdc++.h>

using namespace std;

int main() {
    string inst;
    priority_queue<int> S;
    vector<int> n;
    while (cin >> inst) {
        if (inst == "insert") {
            int x;
            cin >> x;
            S.push(x);
        } else if (inst == "extract") {
            n.push_back(S.top());
            S.pop();
        } else {
            for (auto i : n) {
                cout << i << endl;
            }
            return 0;
        }
    }
    return 0;
}
