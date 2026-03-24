#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

const int inf = 1e9 + 5, B = 450;

void solve() {
    int n; cin >> n;

    auto idx = [&](ll x, ll y) {
        return x * inf + y;
    };

    map<ll, vector<int>> mp;

    vector<ll> x(n), y(n);

    gp_hash_table<ll, bool> glob;

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        mp[x[i] - y[i]].push_back(i);
        glob[idx(x[i], y[i])] = true;
    }

    ll ans = 0;

    for(auto &[key, id] : mp) {
        if( (int)id.size() < B ) {
            int cur = 0;

            for(int i = 0; i < (int)id.size(); i++) {
                for(int j = 0; j < i; j++) {
                    ll first = idx(x[id[i]], y[id[j]]);
                    ll second = idx(x[id[j]], y[id[i]]);
                    if(glob[first] && glob[second]) {
                        cur++;
                    }
                }
            }

            ans += cur;
        } else {
            gp_hash_table<ll, bool> here;

            for(auto &i : id) here[idx(x[i], y[i])] = true;

            int cur = 0;

            for(int i = 0; i < n; i++) {
                if(x[i] - y[i] == key) continue;

                ll x1 = x[i] + (key - (x[i] - y[i]));
                ll y1 = y[i] - (key - (x[i] - y[i]));

                if(here[idx(x1, y[i])] && here[idx(x[i], y1)] && glob[idx(x1, y1)]) {
                    cur++;
                }
            }

            ans += cur / 2;
        }
    }

    cout << ans << '\n';
}

/**

**/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
