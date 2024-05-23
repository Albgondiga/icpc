#include <iostream>

using namespace std;

int main() {
    int N, S, K, P, Q;
    int total = 0;
    cin >> N >> S >> K;
    for (int i = 0; i < N; ++i) {
        cin >> P >> Q;
        total += (P*Q);
    }
    if (total < S) {
        total += K;
    }
    cout << total << endl;
    return 0;
}
