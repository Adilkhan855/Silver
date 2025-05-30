/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) x.begin(), x.end()
#define pb push_back
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	setIO("angry");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k; cin >> n >> k;
	
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	
	sort(all(a));
	
	auto check = [&](int R) {
		int r = 0, cnt = 0;
		vector<int> used(n);
		for(int l = 0; l < n; l++) {
			if(!used[l]) {
				cnt++;
				used[l] = 1;
				while(r + 1 < n && a[r + 1] - a[l] <= 2 * R) {
					r++;
					used[r] = 1;
				}
			}
		}
		return cnt <= k;
	};
	int l = 0, r = 1e9;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l << nl;
}
