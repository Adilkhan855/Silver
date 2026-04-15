#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
// #define int long long

using ll = long long;

void solve() {
	int n; cin >> n;
	
	string s; cin >> s;
	
	vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
	
	// for (int i = n - 1; i >= 0; i--){
		// for (int j = n - 1; j >= 0; j--){
			// if (s[i] == s[j]) lcp[i][j] = 1 + lcp[i + 1][j + 1];
		// }
	// }
	
	for(int st = 0; st < n; st++) {
		for(int i = st + 1, l = 0, r = 0; i < n; i++) {
			if(i < r) {
				lcp[st][i] = min(r - i, lcp[st][st + i - l]);
			}
			
			while(i + lcp[st][i] < n && s[st + lcp[st][i]] == s[i + lcp[st][i]]) {
				lcp[st][i]++;
			}
			
			if(i + lcp[st][i] > r) {
				r = i + lcp[st][i];
				l = i;
			}
			
			// cout << lcp[st][i] << ' ';
		}
		
		// cout << nl;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			lcp[i][j] = lcp[j][i];
		}
	}
	
	vector<vector<int>> posl(n, vector<int>(n, -1));
	
	vector<vector<int>> posr(n, vector<int>(n, n));
	
	auto compare = [&](int l1, int r1, int l2, int r2, bool tie = false) { // s1 < s2
		assert(r1 - l1 == r2 - l2);
		
		int x = lcp[l1][l2];
		
		if(x == 0) {
			return s[l1] < s[l2];
		}
		
		if(x >= r1 - l1 + 1) {
			return tie;
		} else {
			return s[l1 + x] < s[l2 + x];
		}
	};
	
	for(int L = 0; L < n; L++) {
		
		{
			stack<int> st;
			
			for(int i = 0; i + L < n; i++) {
				while(!st.empty() && !compare(st.top(), st.top() + L, i, i + L, true)) st.pop();
				
				if(!st.empty()) {
					posl[L][i] = st.top();
				}
				
				st.push(i);
			}
		}
		
		{
			stack<int> st;
			
			for(int i = n - L - 1; i >= 0; i--) {
				while(!st.empty() && !compare(st.top(), st.top() + L, i, i + L)) st.pop();
				
				if(!st.empty()) {
					posr[L][i] = st.top();
				}
				
				st.push(i);
			}
		}
	}
	
	// vector<vector<vector<int>>> idx(n, vector<vector<int>>(n + 1));
	
	vector<vector<int>> cnt(n, vector<int>(n + 1));
	
	for(int l = 0; l < n; l++) {
		for(int r = l; r < n; r++) {
			// cout << l << ' ' << r << ": " << posl[r - l][l] << ' ' << posr[r - l][l] << nl;
			int mnl = posl[r - l][l];
			int mnr = posr[r - l][l] + r - l;
			mnr = min(mnr, n);
			// K < mnr - mnl
			// cout << mnl << ' ' << mnr << nl;
			// cout << "L = " << r - l + 1 << ' ' << "K <= " << max(0, mnr - mnl - 1) << nl;
			if(mnr - mnl - 1 >= 0) {
				cnt[r - l][mnr - mnl - 1]++;
				// for(int K = 1; K <= mnr - mnl - 1; K++) {
					// idx[r - l][K].push_back(l);
				// }
			}
		}
	}
	
	// for(int K = 1; K <= n; K++) {
		// for(int L = 1; L <= K; L++) {
			// cout << K << ' ' << L << ": " << nl;
			
			// for(auto i : idx[L - 1][K]) cout << i << ' ';
			
			// cout << nl;
		// }
	// }
	
	vector<int> ans(n + 1);
	
	for(int l = 0; l < n; l++) {
		for(int k = n - 1; k >= 0; k--) {
			cnt[l][k] += cnt[l][k + 1];
		}
		for(int k = l + 1; k <= n; k++) {
			ans[cnt[l][k]]++;
		}
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i] << nl;
}

/**

**/

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
