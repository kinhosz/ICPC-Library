typedef pair<int, int> ii;
typedef vector<ii> vii;

int row[MAXN], col[MAXM], P[MAXM], way[MAXM];
int A[MAXN][MAXM];

pair<vii, int> hungarian(int n, int m){
	memset(row, 0, (n+1) * sizeof(int));
	memset(col, 0, (m+1) * sizeof(int));
	memset(P, 0, (m+1) * sizeof(int));

	for(int i=1;i<=n;i++){
		P[0] = i;
		int k0 = 0;
		vector<int> minv(m+1, INF);
		vector<char> used(m+1, false);

		do{
			used[k0] = true;
			int i0 = P[k0], delta = INF, k1;

			for(int j=1;j<=m;j++){
				if(!used[j]){
					int cur = A[i0][j] - row[i0] - col[j];
					if(cur < minv[j]){
						minv[j] = cur;
						way[j] = k0;
					}
					if(minv[j] < delta){
						delta = minv[j];
						k1 = j;
					}
				}
			}

			for(int j=0;j<=m;j++){
				if(used[j]){
					row[P[j]] += delta;
					col[j] -= delta;
				}
				else{
					minv[j] -= delta;
				}
			}

			k0 = k1;
		}while(P[k0] != 0);

		do{
			int k1 = way[k0];
			P[k0] = P[k1];
			k0 = k1;
		}while(k0);
	}

	vii res;

	for(int i=1;i<=m;i++){
		res.push_back(make_pair(P[i], i));
	}

	return make_pair(res, -col[0]);
}
