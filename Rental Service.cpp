#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
	setIO("rental");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, r; cin >> n >> m >> r;
	
	vector<int> c(n), b(r);
	vector<ar<int, 2>> s(m);
	
	for(auto &x : c) cin >> x;
	
	for(auto &[p, q] : s) {
		cin >> p >> q;
		swap(p, q);
	}
	
	for(auto &x : b) cin >> x;
	
	sort(all(c), greater<>());
	sort(all(s), greater<>());
	sort(all(b), greater<>());
	
	vector<int> pref1(m + 1), pref2(m + 1), pref3(r + 1);
	
	for(int i = 0; i < m; i++) {
		pref1[i + 1] = pref1[i] + s[i][1];
		pref2[i + 1] = pref2[i] + s[i][0] * s[i][1];
	}
	
	for(int i = 0; i < r; i++) {
		pref3[i + 1] = pref3[i] + b[i];
	}
	
	auto val = [&](int x) {
		int j = upper_bound(all(pref1), x) - pref1.begin();
		j--;
		x -= pref1[j];
		int res = pref2[j];
		if(j < m) res += x * s[j][0];
		return res;
	};
	
	c.insert(c.begin(), 0);
	
	int ans = 0, sum = 0;
	
	for(int i = 0; i <= n; i++) {
		sum += c[i];
		ans = max(ans, val(sum) + pref3[min(r, n - i)]);
	}
	
	cout << ans << nl;
}
