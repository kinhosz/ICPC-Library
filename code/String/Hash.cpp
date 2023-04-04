class Hash{
  int Q;
  const int MOD[2] = {1000000009, 999996223};
  vector<vector<int>> hashes;
  vector<vector<int>> powerQ;
private:
  vector<int> add(vector<int> a, int b){
    for(int i=0;i<2;i++) a[i] = (a[i] + b)%MOD[i];
    return a;
  }

  vector<int> mult(vector<int> a, int b){
    for(int i=0;i<2;i++) a[i] = (ll(a[i]) * ll(b))%MOD[i];
    return a;
  }

  vector<int> mult(vector<int> a, vector<int> b){
    for(int i=0;i<2;i++) a[i] = (ll(a[i]) * ll(b[i]))%MOD[i];
    return a;
  }

  vector<int> sub(vector<int> a, vector<int> b){
    for(int i=0;i<2;i++) a[i] = (a[i] - b[i] + MOD[i])%MOD[i];
    return a;
  }

  int getId(char x){
    return int(x - '0');
  }

  pair<int,int> toPair(vector<int> a){
    return make_pair(a[0], a[1]);
  }

public:
  Hash(int q): Q(q){}

  void build(string &S){
    hashes.resize(S.size());
    powerQ.resize(S.size());

    vector<int> current = {0, 0};
    powerQ[0] = {1, 1};
    for(int i=0;i<S.size();i++){
      current = mult(current, Q);
      current = add(current, getId(S[i]));
      hashes[i] = current;
      if(i!=0) powerQ[i] = mult(powerQ[i-1], Q);
    }
  }

  pair<int,int> getHash(int l, int r){
    vector<int> hsh = hashes[r];
    l--;
    if(l <= -1) return toPair(hsh);
    return toPair(sub(hsh, mult(hashes[l], powerQ[r-l])));
  }
};
