/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define nl '\n'

signed main() {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	vector<int> pref(n + 1), suf(n + 1);
	
	for(int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i];
	}
	
	suf[n] = 1e9;
	
	for(int i = n - 1; i >= 0; i--) {
		suf[i] = min(suf[i + 1], a[i]);
	}
	
	vector<pair<int, int>> vals;
	
	for(int i = 1; i < n - 1; i++) {
		int val = pref[n] - pref[i] - suf[i], len = n - 1 - i;
		vals.emplace_back(val, len);
	}
	
	sort(all(vals), [](const pair<int, int> &v1, const pair<int, int> &v2) {
		return v1.first * v2.second < v2.first * v1.second;
	});
	
	pair<int, int> mx = vals.back();
	
	for(int i = 1; i < n - 1; i++) {
		int val = pref[n] - pref[i] - suf[i], len = n - 1 - i;
		if(mx.first * len == val * mx.second) {
			cout << i << nl;
		}
	}
}
