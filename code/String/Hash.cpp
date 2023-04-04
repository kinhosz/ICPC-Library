class Hash{
  ll Q;
  const ll MOD[2] = {1000000009, 999996223};
  vector<vector<ll>> hashes;
  vector<vector<ll>> powerQ;
private:
  auto add(auto a, ll b){
    for(int i=0;i<2;i++) a[i] = (a[i] + b)%MOD[i];
    return a;
  }

  auto mult(auto a, ll b){
    for(int i=0;i<2;i++) a[i] = (a[i] * b)%MOD[i];
    return a;
  }

  auto mult(auto a, auto b){
    for(int i=0;i<2;i++) a[i] = (a[i] * b[i])%MOD[i];
    return a;
  }

  auto sub(auto a, auto b){
    for(int i=0;i<2;i++) a[i] = (a[i] - b[i] + MOD[i])%MOD[i];
    return a;
  }

  ll getId(char x){
    return ll(x - '0');
  }

  auto toPair(auto a){
    return make_pair(a[0], a[1]);
  }

public:
  Hash(int q): Q(q){}

  void build(string &S){
    vector<ll> current = {0LL, 0LL};
    powerQ.push_back({1LL, 1LL});
    for(int i=0;i<S.size();i++){
      current = mult(current, Q);
      current = add(current, getId(S[i]));
      hashes.push_back(current);
      if(i!=0) powerQ.push_back(mult(powerQ[i-1], Q));
    }
  }

  auto getHash(int l, int r){
    auto hsh = hashes[r];
    l--;
    if(l <= -1) return toPair(hsh);
    return toPair(sub(hsh, mult(hashes[l], powerQ[r-l])));
  }
};