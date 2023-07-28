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
      ld = fexp(d, mod-2);
    }
  }
  c.resize(l+1);
  c.erase(c.begin());

  for(T &x: c) x = (mod - x) % mod;
  return c;
}

// aqui foi ctrl+c
// p = p*q % h
void mull(vector<int> &p,vector<int> &q, vector<int> &h, int m) {
  vector<int> t_(m+m);
  for(int i=0;i<m;++i) if(p[i])
    for(int j=0;j<m;++j)
      t_[i+j]=(t_[i+j]+p[i]*q[j])%mod;
  for(int i=m+m-1;i>=m;--i) if(t_[i])
    //miuns t_[i]x^{i-m}(x^m-\sum_{j=0}^{m-1} x^{m-j-1}h_j)
    for(int j=m-1;~j;--j)
      t_[i-j-1]=(t_[i-j-1]+t_[i]*h[j])%mod;
  for(int i=0;i<m;++i) p[i]=t_[i];
}

// a = caso base, h = recorrencia, m = tamanho da recorrencia
inline int calc(vector<int> &a, vector<int> &h, int K, int m) {
  vector<int> s(m), t(m);
  //init
  s[0]=1; if(m!=1) t[1]=1; else t[0]=h[0];
  //binary-exponentiation
  while(K) {
    if(K&1) mull(s,t,h,m);
    mull(t,t,h,m); K>>=1;
  }
  int su=0;
  for(int i=0;i<m;++i) su=(su+s[i]*a[i])%mod;
  return (su%mod+mod)%mod;
}