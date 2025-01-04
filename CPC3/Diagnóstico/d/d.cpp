#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    int i = 0;
    int yes = 0;
    while (i < N-1 && !yes) {
        if ((S[i] == 'a' && S[i+1] == 'b') || (S[i] == 'b' && S[i+1] == 'a')) {
            yes = 1;
        } else {
            ++i;
        }
    }
    if (yes) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}