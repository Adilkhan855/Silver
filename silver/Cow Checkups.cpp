#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using ll = long long;

void solve() {
	int n; cin >> n;
	
	vector<int> a(n), b(n);
	
	for(auto &x : a) cin >> x;
	
	for(auto &x : b) cin >> x;
	
	auto sum = [&](int x) {
		return x * 1ll * (x + 1) / 2;
	};
	
	vector<array<int, 2>> pq1, sq1;
	vector<array<int, 3>> pq2, sq2;
	
	pq1.reserve(n);
	sq1.reserve(n);
	pq2.reserve(2 * n);
	sq2.reserve(2 * n);
	
	ll ans = 0;
	
	for(int i = 0; i < n; i++) {
		pq1.push_back({min(i, n - i), a[i]});
		sq2.push_back({min(i, n - i), a[i], n - i});
		sq2.push_back({i, a[i], -(n - i)});
		sq1.push_back({max(i, n - i - 1), a[i]});
		pq2.push_back({max(i, n - i - 1), a[i], i + 1});
		pq2.push_back({i, a[i], -(i + 1)});
		if(a[i] == b[i]) {
			ans += sum(i) + sum(n - i - 1);
			ans += min(i + 1, n - i);
		}
	}
	
	sort(pq1.begin(), pq1.end());
	sort(pq2.begin(), pq2.end());
	sort(sq1.begin(), sq1.end(), greater<>());
	sort(sq2.begin(), sq2.end(), greater<>());
	
	gp_hash_table<int, ll> mp1, mp2;
	
	int p1 = 0, p2 = 0;
	
	while(p1 < (int)pq1.size() && pq1[p1][0] == 0) p1++;
	
	for(int i = 0; i < n; i++) {
		mp1[b[i]] += i + 1;
		mp2[b[i]]++;
		while(p1 < (int)pq1.size() && pq1[p1][0] == i + 1) {
			ans += mp1[pq1[p1][1]];
			p1++;
		}
		while(p2 < (int)pq2.size() && pq2[p2][0] == i) {
			ans += mp2[pq2[p2][1]] * 1ll * pq2[p2][2];
			p2++;
		}
	}
	
	mp1.clear(), mp2.clear();
	
	int s1 = 0, s2 = 0;
	
	while(s1 < (int)sq1.size() && sq1[s1][0] == n - 1) s1++;
	
	for(int i = n - 1; i >= 0; i--) {
		mp1[b[i]] += n - i;
		mp2[b[i]]++;
		while(s1 < (int)sq1.size() && sq1[s1][0] == i - 1) {
			ans += mp1[sq1[s1][1]];
			s1++;
		}
		while(s2 < (int)sq2.size() && sq2[s2][0] == i) {
			ans += mp2[sq2[s2][1]] * 1ll * sq2[s2][2];
			s2++;
		}
	}
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
