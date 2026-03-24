#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 1e18 + 5;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(m + 1, inf));

    for(int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for(int j = 0; j < m; j++) {
        vector<ll> pref(n + 1, inf);

        for(int i = 0; i < n; i++) {
            pref[i + 1] = min(pref[i], dp[i][j] + 2 * a[i][j] - i);
        }

        vector<ll> suf(n + 1, inf);

        for(int i = n - 1; i >= 0; i--) {
            suf[i] = min(suf[i + 1], dp[i][j] + 2 * a[i][j] + i);
        }

        for(int i = 0; i < n; i++) {
//            cout << dp[i][j] << ' ';
            dp[i][j + 1] = min(pref[i] + i, suf[i] - i) + 1;
        }

//        cout << '\n';
    }

    ll ans = inf;

    for(int i = 0; i < n; i++) ans = min(ans, dp[i][m]);

    cout << ans << '\n';
}

/**

**/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
