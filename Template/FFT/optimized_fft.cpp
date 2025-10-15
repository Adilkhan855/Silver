#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

template <typename A, typename B>
bool chmin(A &a, const B &b) {
	if(a > b) {
		return a = b, true;
	}
	return false;
}

template <typename A, typename B>
bool chmax(A &a, const B &b) {
	if(a < b) {
		return a = b, true;
	}
	return false;
}

struct cmpl {
	double x, y;
	
	cmpl(double x = 0, double y = 0) : x(x), y(y) {}
	
	cmpl operator+(const cmpl &other) const {
		return cmpl(x + other.x, y + other.y);
	}
	
	cmpl operator-(const cmpl &other) const {
		return cmpl(x - other.x, y - other.y);
	}
	
	cmpl operator*(const cmpl &other) const {
		return cmpl(x * other.x - y * other.y, x * other.y + y * other.x);
	}
	
	cmpl operator/(const double &u) const {
		return cmpl(x / u, y / u);
	}
	
	double& real() {
		return x;
	}
	
	double& imag() {
		return y;
	}
};

const double PI = atan2(0, -1);

vector<vector<cmpl>> w;

vector<int> bit_rev;

void precalc(int logn) {
	bit_rev.resize(1 << logn);
	w.resize(logn + 1);
	w[0].resize(1, 1);
	for(int l = 1; l <= logn; l++) {
		int n = (1 << l);
		w[l].resize(n >> 1);
		cmpl the_w(cos(2 * PI / n), sin(2 * PI / n));
		for(int j = 0; j < (n >> 1); j++) {
			// w[l][j] = cmpl(cos(2 * PI * j / n), sin(2 * PI * j / n));
			if(j & 1) {
				w[l][j] = w[l - 1][j >> 1] * the_w;
			} else {
				w[l][j] = w[l - 1][j >> 1];
			}
		}
	}
}

void fft(vector<cmpl> &P, bool inv = false) {
	int n = P.size();
	
	int logn = 0;
	
	while((1 << logn) < n) logn++;
	
	for(int i = 0; i < n; i++) {
		bit_rev[i] = (bit_rev[i >> 1] >> 1) | ((i & 1) << (logn - 1));
		if(i < bit_rev[i]) {
			swap(P[i], P[bit_rev[i]]);
		}
	}
	
	for(int lvl = 1; lvl <= logn; lvl++) {
		int len = (1 << lvl);
		for(int st = 0; st < n; st += len) {
			for(int j = 0; j < (len >> 1); j++) {
				cmpl val1 = P[st + j] + w[lvl][j] * P[st + (len >> 1) + j];
				cmpl val2 = P[st + j] - w[lvl][j] * P[st + (len >> 1) + j];
				P[st + j] = val1;
				P[st + (len >> 1) + j] = val2;
			}
		}
	}
	
	if(inv) {
		reverse(P.begin() + 1, P.end());
		for(int i = 0; i < n; i++) {
			P[i] = P[i] / n;
		}
	}
}

vector<int> multiply(vector<int> P, vector<int> Q) {
	int n = 1, logn = 0;
	while(n < (int)(P.size() + Q.size() - 1)) {
		n <<= 1;
		logn++;
	}
	
	precalc(logn);
	
	// vector<cmpl> P_cmpl(n), Q_cmpl(n);
	
	// copy(all(P), P_cmpl.begin());
	// copy(all(Q), Q_cmpl.begin());
	
	// fft(P_cmpl);
	// fft(Q_cmpl);
	
	// for(int i = 0; i < n; i++) {
		// P_cmpl[i] = P_cmpl[i] * Q_cmpl[i];
	// }
	
	// fft(P_cmpl, true);
	
	vector<cmpl> A(n);
	
	for(int i = 0; i < n; i++) {
		A[i] = cmpl(i < (int)P.size() ? P[i] : 0, i < (int)Q.size() ? Q[i] : 0);
	}
	
	fft(A);
	
	for(int i = 0; i < n; i++) {
		A[i] = A[i] * A[i];
	}
	
	fft(A, true);
	
	vector<int> R(n);
	
	for(int i = 0; i < n; i++) {
		// R[i] = round(P_cmpl[i].real());
		R[i] = round(A[i].imag() / 2);
	}
	
	return R;
}

void solve() {
	int n; cin >> n;
	
	vector<int> P(n);
	
	for(auto &x : P) cin >> x;
	
	int m; cin >> m;
	
	vector<int> Q(m);
	
	for(auto &x : Q) cin >> x;
	
	auto R = multiply(P, Q);
	
	for(int i = 0; i < (int)(P.size() + Q.size() - 1); i++) {
		cout << R[i] << ' ';
	}
	
	cout << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
