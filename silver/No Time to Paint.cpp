#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n, q; cin >> n >> q;
	
	string s; cin >> s;
	
	vector<int> pref(n + 1), suf(n + 1);
	
	{
		vector<int> last(26, -1);
		stack<int> st;
		
		for(int i = 0; i < n; i++) {
			while(!st.empty() && s[st.top()] > s[i]) st.pop();
			
			pref[i + 1] = pref[i] + (last[s[i] - 'A'] == -1 || st.top() > last[s[i] - 'A']);
			last[s[i] - 'A'] = i;
			
			st.push(i);
		}
	}
	
	{
		vector<int> last(26, -1);
		stack<int> st;
		
		for(int i = n - 1; i >= 0; i--) {
			while(!st.empty() && s[st.top()] > s[i]) st.pop();
			
			suf[i] = suf[i + 1] + (last[s[i] - 'A'] == -1 || st.top() < last[s[i] - 'A']);
			last[s[i] - 'A'] = i;
			
			st.push(i);
		}
	}
	
	while(q--) {
		int l, r; cin >> l >> r;
		cout << pref[l - 1] + suf[r] << nl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
