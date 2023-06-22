ll fastExp(ll base, ll exp){
	ll ret = 1LL;

	while(exp){
		if((exp&(1LL))) ret = (ret * base)%MOD;
		base = (base * base)%MOD;
		exp >>= 1;
	}

	return ret;
}