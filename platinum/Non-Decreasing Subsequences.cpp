#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

using vi = vector<int>;
using vii = vector<vi>;

const int N = (1 << 16), M = 5e4, mod = 1e9 + 7;

int a[N], F[2][21];
int8_t lg[N];

vii sp[M];

int n, q, k, i, len, cen, j, l, r, m, tt, res;

void add_self(int &a, const int &b) {
    a += b;
    if (a >= mod) a -= mod;
}

void solve() {
    setIO("nondec");
    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    auto multiply = [&](const vii &M) -> void {
        res = 0;
        for (l = 0; l <= k; l++) {
            F[1][l] = 0;
            for (m = 0; m <= k; m++) {
                add_self(F[1][l], F[0][m] * 1ll * M[l][m] % mod);
            }
            add_self(res, F[1][l]);
        }
        swap(F[0], F[1]);
    };

    vector<vector<ar<int, 3>>> Q(16);

    scanf("%d", &q);

    vector<int> ans(q);

    for (i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        l--, r--;

        if (l == r) {
            ans[i] = 2;
            continue;
        }

        Q[lg[l ^ r]].pb({l, r, i});
    }

    for (i = 0; (1 << i) < n; i++) {
        len = (1 << i);

        for (cen = len; cen < n; cen += (len << 1)) {
            sp[cen] = sp[cen - 1] = vii(k + 1, vi(k + 1));

            for (l = 0; l <= k; l++) {
                sp[cen][l][l] = sp[cen - 1][l][l] = 1;

                if (l == a[cen]) {
                    sp[cen][l][l] = 2;
                } else if (l < a[cen]) {
                    sp[cen][a[cen]][l] = 1;
                }

                if (l == a[cen - 1]) {
                    sp[cen - 1][l][l] = 2;
                } else if (l < a[cen - 1]) {
                    sp[cen - 1][a[cen - 1]][l] = 1;
                }
            }

            for (j = cen + 1; j < min(n, cen + len); j++) {
                sp[j] = sp[j - 1];

                for (m = 0; m <= k; m++) {
                    for (l = 0; l <= a[j]; l++) {
                        add_self(sp[j][a[j]][m], sp[j - 1][l][m]);
                    }
                }
            }

            for (j = cen - 2; j >= max(0, cen - len); j--) {
                sp[j] = sp[j + 1];

                for (l = 0; l <= k; l++) {
                    for (m = 0; m <= a[j]; m++) {
                        add_self(sp[j][l][m], sp[j + 1][l][a[j]]);
                    }
                }
            }
        }

        for (auto &[L, R, ID] : Q[i]) {
            if (L == R) {
                ans[ID] = 2;
                continue;
            }

            for (j = 0; j <= k; j++) {
                F[0][j] = 0;
            }

            F[0][0] = 1;

            multiply(sp[L]);
            multiply(sp[R]);

            ans[ID] = res;
        }
    }

    for (auto &x : ans) {
        printf("%d\n", x);
        assert(x > 0);
    }
}

signed main() {
    for (i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;

    // scanf("%d", &tt);
    // while (tt--) solve();
    solve();
}
