#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n; cin >> n;
	
	vector<int> x(n), y(n);
	
	vector<int> east, north;
	
	for(int i = 0; i < n; i++) {
		char c; cin >> c;
		cin >> x[i] >> y[i];
		
		if(c == 'E') {
			east.pb(i);
		} else {
			north.pb(i);
		}
	}
	
	sort(all(east), [&](const int &i, const int &j) {
		return y[i] < y[j];
	});
	
	sort(all(north), [&](const int &i, const int &j) {
		return x[i] < x[j];
	});
	
	vector<int> cnt(n), ok(n, true);
	
	for(auto i : east) {
		for(auto j : north) {
			if(ok[i] && ok[j] && x[i] < x[j] && y[i] > y[j]) {
				if(y[i] - y[j] > x[j] - x[i]) {
					ok[j] = false;
					cnt[i] += cnt[j] + 1;
				} else if(x[j] - x[i] > y[i] - y[j]) {
					ok[i] = false;
					cnt[j] += cnt[i] + 1;
				}
			}
		}
	}
	
	for(auto &u : cnt) cout << u << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
