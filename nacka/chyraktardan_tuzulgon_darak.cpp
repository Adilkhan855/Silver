#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct segtree {
    int n;

    vector<int> t, p;

    segtree(int n) : n(n), t(n << 2), p(n << 2) {}

    void push(int v, int l, int r) {
        if(p[v] == 0) return;

        t[v] = (r - l + 1) - t[v];

        if(l != r) {
            p[v << 1] ^= p[v];
            p[v << 1 | 1] ^= p[v];
        }

        p[v] = 0;
    }

    void toggle(int v, int l, int r, int ql, int qr) {
        push(v, l, r);

        if(l > qr || ql > r) return;

        if(l >= ql && r <= qr) {
            p[v] ^= 1;
            push(v, l, r);
            return;
        }

        int m = (l + r) >> 1;

        toggle(v << 1, l, m, ql, qr);
        toggle(v << 1 | 1, m + 1, r, ql, qr);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    void toggle(int l, int r) {
        toggle(1, 0, n - 1, l, r);
    }
};

void solve() {
    int n; cin >> n;

    vector<vector<int>> adj(n);

    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;

        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sz(n), heavy(n), dep(n), par(n);

    {
        auto dfs = [&](auto &&self, int v) -> void {
            sz[v] = 1;

            heavy[v] = -1;

            for(auto to : adj[v]) {
                if(to == par[v]) continue;

                dep[to] = dep[v] + 1;

                par[to] = v;

                self(self, to);

                sz[v] += sz[to];

                if(heavy[v] == -1 || sz[heavy[v]] < sz[to]) {
                    heavy[v] = to;
                }
            }
        };

        dfs(dfs, 0);
    }

    vector<int> head(n), idx(n);

    segtree t(n);

    {
        int timer = 0;

        auto dfs = [&](auto &&self, int v, int h) -> void {
            idx[v] = timer++;
            head[v] = h;

            if(heavy[v] != -1) {
                self(self, heavy[v], h);
            }

            for(auto to : adj[v]) {
                if(to == par[v] || to == heavy[v]) continue;

                self(self, to, to);
            }
        };

        dfs(dfs, 0, 0);
    }

    auto update = [&](int u, int v) {
        while(head[u] != head[v]) {
            if(dep[head[u]] < dep[head[v]]) swap(u, v);

            t.toggle(idx[head[u]], idx[u]);

            u = par[head[u]];

//            cout << u << ' ' << v << endl;
        }

        if(idx[u] > idx[v]) swap(u, v);

        t.toggle(idx[u], idx[v]);
    };

    int q; cin >> q;

    while(q--) {
        int u, v; cin >> u >> v;

        u--, v--;

        update(0, u);

        update(0, v);

        cout << t.t[1] << '\n';
    }
}

/**

**/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
