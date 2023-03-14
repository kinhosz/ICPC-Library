void sosdp(){
	int bmask;

	for(int i=0;i<22;i++){
		for(int mask=0;mask<maxn;mask++){
			if(mask & (1<<i)){
				bmask = mask^(1<<i);
				dp[mask] = max(dp[mask],dp[bmask]);
			}
		}
	}
}