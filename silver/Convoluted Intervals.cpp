#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n, m; cin >> n >> m;
	
	vector<int> a(n), b(n);
	
	vector<int> a_freq(m + 1), b_freq(m + 1);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		a_freq[a[i]]++;
		b_freq[b[i]]++;
	}
	
	vector<int> st(2 * m + 1), en(2 * m + 1);
	
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= m; j++) {
			st[i + j] += a_freq[i] * a_freq[j];
			en[i + j] += b_freq[i] * b_freq[j];
		}
	}
	
	int cur = 0;
	
	for(int k = 0; k <= 2 * m; k++) {
		cur += st[k];
		cout << cur << nl;
		cur -= en[k];
	}	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
