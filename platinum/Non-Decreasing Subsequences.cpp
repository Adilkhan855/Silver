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

const int N = (1 << 16), M = 5e4, mod = 1e9 + 7;

int a[M];
int8_t lg[N];

int sp[M][21][21], sum[M][21];

int n, q, k, i, len, cen, j, l, r, m, tt;

void add_self(int &a, const int &b) {
	a += b;
	if(a >= mod) a -= mod;
}

void solve() {
    setIO("nondec");
    cin >> n >> k;

	for(i = 0; i < n; i++) cin >> a[i];
	
	vector<vector<ar<int, 3>>> Q(16);
	
	cin >> q;
	
	vector<int> ans(q);

	for(i = 0; i < q; i++) {
		cin >> l >> r;
		l--, r--;
		
		if(l == r) {
			ans[i] = 2;
			continue;
		}
		
		Q[ lg[l ^ r] ].pb({l, r, i});
	}
	
	for(i = 0; (1 << i) < n; i++) {
		
		len = (1 << i);
		
		for(cen = len; cen < n; cen += (len << 1)) {
			
			for(l = 0; l <= k; l++) {
				for(m = 0; m <= l; m++) {
					sp[cen][l][m] = sp[cen - 1][l][m] = 0;
				}
			}
			
			for(l = 0; l <= k; l++) {
				sp[cen][l][l] = sp[cen - 1][l][l] = 1;
				
				if(l == a[cen]) {
					sp[cen][l][l] = 2;
				} else if(l < a[cen]) {
					sp[cen][ a[cen] ][l] = 1;
				}
				
				if(l == a[cen - 1]) {
					sp[cen - 1][l][l] = 2;
				} else if(l < a[cen - 1]) {
					sp[cen - 1][ a[cen - 1] ][l] = 1;
				}
			}

			for(j = cen + 1; j < min(n, cen + len); j++) {
				// sp[j] = merge(mat[ a[j] ], sp[j - 1]);
				
				// sp[j] = sp[j - 1];
				
				for(l = 0; l <= k; l++) {
					for(m = 0; m <= l; m++) {
						sp[j][l][m] = sp[j - 1][l][m];
					}
				}
				
				for(m = 0; m <= k; m++) {
					for(l = 0; l <= a[j]; l++) {
						add_self(sp[j][ a[j] ][m], sp[j - 1][l][m]);
					}
				}
			}

			for(j = cen - 2; j >= max(0, cen - len); j--) {
				// sp[j] = merge(sp[j + 1], mat[ a[j] ]);
					
				// sp[j] = sp[j + 1];
				
				for(l = 0; l <= k; l++) {
					for(m = 0; m <= l; m++) {
						sp[j][l][m] = sp[j + 1][l][m];
					}
				}

				for(l = 0; l <= k; l++) {
					for(m = 0; m <= a[j]; m++) {
						add_self(sp[j][l][m], sp[j + 1][l][ a[j] ]);
					}
				}
			}
			
			for(j = max(0, cen - len); j < min(n, cen + len); j++) {
				for(l = 0; l <= k; l++) {
					sum[j][l] = 0;
					for(m = 0; m <= l; m++) {
						add_self(sum[j][m], sp[j][l][m]);
					}
				}
			}
			
		}
		
		for(auto &[L, R, ID] : Q[i]) {
			for(int m = 0; m <= k; m++) {
				add_self(ans[ID], sum[R][m] * 1ll * sp[L][m][0] % mod);
			}
		}
		
	}
	
	for(auto &x : ans) {
		cout << x << nl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;

	solve();
}
