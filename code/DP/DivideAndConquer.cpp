auto cost(int j, int k){

}

void dnc(int l, int r, int optl, int optr, auto &dp_curr, auto &dp_bef){
	int mid = (l + r) >> 1;
	if(l > r) return ;
	const ll inf = 1e9 + 7;
	
	pair<ll, int> best = make_pair(-inf, -1);
	for(int k=optl; k <= min(optr, mid); k++){
		pair<ll, int> curr = make_pair(dp_bef[k] + cost(mid, k), k);
		best = max(best, curr);
	}
	dp_curr[mid] = best.first;
	dnc(l, mid-1, optl, best.second, dp_curr, dp_bef);
	dnc(mid+1, r, best.second, optr, dp_curr, dp_bef);
}