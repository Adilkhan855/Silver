#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 2e9 + 5;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	
	vector<array<int, 2>> cows(n);
	
	for(auto &[w, a] : cows) cin >> w >> a;
	
	sort(cows.begin(), cows.end(), greater<>());
	
	queue<array<int, 2>> t;
	
	t.push({inf, m});
	
	ll ans = 0;
	
	for(auto &[w, a] : cows) {
		int rem = a;
		while(!t.empty() && rem > 0 && w + k <= t.front()[0]) {
			if(t.front()[1] > rem) {
				t.front()[1] -= rem;
				rem = 0;
			} else {
				rem -= t.front()[1];
				t.pop();
			}
		}
		int cnt = a - rem;
		if(cnt > 0) {
			ans += cnt;
			t.push({w, cnt});
		}
	}
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
