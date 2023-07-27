template<typename T>
vector<T> berlekampMassey(const vector<T> &s){
	int n = s.size(), l = 0, m = 1;
	vector<T> c(n), b(n);
	T ld = c[0] = b[0] = T(1);

	for(int i=0; i<n; i++, m++){
		T d = s[i];
		for(int j=1;j<=l;j++){
			d = ((c[j] * s[i-j]) % mod + d) % mod;
		}
		if(d == T(0)) continue;

		vector<T> temp = c;

		T coef = (d * ld) % mod;
		for(int j=m;j<n;j++){
			c[j] = (c[j] + mod - (coef * b[j - m]) % mod) % mod;
		}

		if(2 * l <= i){
			l = i + 1 - l;
			m = 0;
			b = temp;
			ld = fastExp(d, mod-2);
		}
	}
	c.resize(l+1);
	c.erase(c.begin());

	for(T &x: c) x = (mod - x) % mod;
	return c;
}
