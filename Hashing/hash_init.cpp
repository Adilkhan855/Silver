mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) uniform_int_distribution<int>(l, r)(rng)
 
bool check(int x) {
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) return false;
	}
	return true;
}

const int N = 1e6 + 5; // IMPORTANT!!!
int pr, mod;
int p[N];

void init_hash() {
	pr = rnd(30, 200), mod = rnd(1e9, 2e9);
	p[0] = 1;
	for(int i = 1; i < N; i++) {
		p[i] = p[i - 1] * pr % mod;
	}
}
