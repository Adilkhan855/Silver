/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) x.begin(), x.end()
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
	setIO("highcard");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<int> a(n);
	set<int> st;
	for(int i = 1; i <= 2 * n; i++) st.emplace(i);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		st.erase(a[i]);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		auto it = st.upper_bound(a[i]);
		if(it != st.end()) {
			cnt++;
			st.erase(it);
		}
	}
	cout << cnt << nl;
}
