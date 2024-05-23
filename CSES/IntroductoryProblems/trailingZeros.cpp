#include <bits/stdc++.h>

using namespace std;

#if 0
// Recursive function to calculate the multiples of 5 till N
int solve(int N)
{
    if (N == 0) {
        return 0;
    }
    return N / 5 + solve(N / 5);
}

int main()
{
    int N = 20;
    cout << solve(N) << "\n";
    return 0;
}
#endif

int main() {
    int n, div = 5, zeros = 0;
    cin >> n;
    while (div <= n) {
        zeros += n/div;
        div *= 5;
    }
    cout << zeros << endl;
    return 0;
}
