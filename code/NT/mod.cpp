template <typename T>
struct Modint{
	typedef Modint Mi;
	const T mod = 1e9;
	T x = 0;

	Modint(){}
	Modint(T y){ x = normalize(y); }

	T normalize(T y){ while(y<0) y += mod; return y % mod; }

	Mi fexp(Mi b, T e){
		Mi r = 1;
		while(e){
			if(e&(T(1))) r *= b;
			b *= b;
			e >>= 1;
		}
		return r;
	}

	Mi inverse(){ return fexp(Mi(x), mod-2); }

	Mi& operator=(const T &y){ x = Mi(y).x; return *this; }
	Mi& operator=(const Mi &other) { x = other.x; return *this; }
	Mi operator+(const Mi &other) const { return Mi((x + other.x) % mod); }
	Mi operator-(const Mi &other) const { return Mi((x - other.x + mod) % mod); }
	Mi operator*(const Mi &other) { return Mi((x * other.x) % mod); }
	Mi operator/(Mi other) const { return Mi((x * other.inverse().x) % mod); }

	Mi operator++(int32_t){ Mi cop(*this); x = (x + 1) % mod; return cop; }
	Mi operator--(int32_t){ Mi cop(*this); x = (x -1 + mod) % mod; return cop; }

	Mi operator++(){ x = (x + 1) % mod; return *this; }
	Mi operator--(){ x = (x - 1 + mod) % mod; return *this; }

	Mi& operator+=(const Mi &other) { Mi val = (*this) + other; x = val.x; return *this; }
	Mi& operator-=(const Mi &other) { Mi val = (*this) - other; x = val.x; return *this; }
	Mi& operator*=(const Mi &other) { Mi val = (*this) * other; x = val.x; return *this; }
	Mi& operator/=(const Mi &other) { Mi val = (*this) / other; x = val.x; return *this; }

	friend ostream& operator<<(ostream& os, const Mi &other){ 
		os << other.x; 
		return os; 
	}
};

typedef Modint<long long> ModInt;
