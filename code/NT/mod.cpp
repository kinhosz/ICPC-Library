template <typename T = long long>
struct Modint{
	typedef Modint Mi;
	const T mod = 1e9+7;
	T x = 0;

	Modint(){}
	Modint(T y){ this->normalize(y); }

	T normalize(T y){ while(y<0) y += mod; x = y%mod; }

	Mi fexp(Mi b, T e){
		Mi r = 1;
		while(e){
			if(e&(T(1))) r *= b;
			b *= b;
			e >>= 1;
		}
		return r;
	}

	Mi inverse(){ return this->fexp(Mi(x), mod-2); }

	Mi& operator=(const T &y){ x = Mi(y).x; }
	Mi& operator=(const Mi &other) { x = other.x; }
	Mi operator+(const Mi &other) const { return (x + other.x) % mod; }
	Mi operator-(const Mi &other) const { return (x - other.x + mod) % mod; }
	Mi operator*(const Mi &other) const { return (x * other.x) % mod; }
	Mi operator/(Mi other) const { return (x * other.inverse().x) % mod; }

	Mi& operator+=(const Mi &other) { Mi val = (*this) + other; x = val.x; }
	Mi& operator-=(const Mi &other) { Mi val = (*this) - other; x = val.x; }
	Mi& operator*=(const Mi &other) { Mi val = (*this) * other; x = val.x; }
	Mi& operator/=(const Mi &other) { Mi val = (*this) / other; x = val.x; }

	friend ostream& operator<<(ostream& os, const Mi &other){ 
		os << other.x; 
		return os; 
	}
};
