#if 0
ll findNumber(ll x, ll y) {
    if (x == 1 && y== 1) {
        return 1;
    } else {
        if (x - y >= 0) {
            ll corner = pow(x,2)-(x-1);
            if (x%2 == 0) {
                return corner + abs(x-y);
            } else {
                return corner - abs(x-y);
            }
        } else {
            ll corner = pow(y,2)-(y-1);
            if (y%2 == 0) {
                return corner - abs(x-y);
            } else {
                return corner + abs(x-y);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    ll v[n];
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        v[i] = findNumber(x, y);
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }
    cout << endl;
    return 0;
}
#endif