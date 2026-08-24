#include <bits/stdc++.h>
using namespace std;

int n, LOG;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p, int d = 0) {
    tin[v] = ++timer;
    depth[v] = d, subtree[v] = 1;
    up[v][0] = p;
    for (int i = 1; i <= LOG; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d+1);
            subtree[v] += subtree[u];
        }
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int go_up(int u, int v) {
    for (int i = LOG; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    u = go_up(u,v);
    return up[u][0];
}


int getKthAncestor(int node, int k) {
    if(depth[node] < k) {
        return -1;
    }
    for(int j = LOG - 1; j >= 0; j--) {
        if(k >= (1 << j)) {
            node = up[node][j];
            k -= 1 << j;
        }
    }
    return node;
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    LOG = ceil(log2(n));
    up.assign(n, vector<int>(LOG + 1));
    dfs(root, root);
}