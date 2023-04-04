class KMP{
  vector<int> pi;
  string patt;

  void build(string &S){
    patt = S + '$';
    pi.push_back(0);
    for(int i=1;i<S.size();i++){
      int j = pi[i-1];
      while(j>0 && S[j] != S[i]) j=pi[j-1];
      if(S[i] == S[j]) j++;
      pi.push_back(j);
    }
    pi.push_back(0);
  }

public:
  KMP(string &S){
    build(S);
  }

  auto getPrefixes(string &T){
    vector<int> prefix;
    int j = 0;
    for(int i=0;i<T.size();i++){
      while(j>0 && patt[j] != T[i]) j=pi[j-1];
      if(patt[j] == T[i]) j++;
      prefix.push_back(j);
    }
    return prefix;
  }
};