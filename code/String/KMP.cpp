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

  auto getPI(string &T){ // longest proper prefix
    vector<int> prefix;
    int j = 0;
    for(int i=0;i<T.size();i++){
      while(j>0 && patt[j] != T[i]) j=pi[j-1];
      if(patt[j] == T[i]) j++;
      prefix.push_back(j);
    }
    return prefix;
  }

  auto getLCP(string &T){ // longest common prefix between T & Patt
    vector<int> lcp = getPI(T);
    int pe = 1;
    for(int i=1;i<patt.size();i++){
      if(patt[i] != patt[i-1]) break;
      pe++;
    }

    for(int i=0;i<lcp.size();i++){
      if(lcp[i] != 0) lcp[i - lcp[i] + 1] = lcp[i];
      if(lcp[i] != 1) lcp[i] = 0;
    }
    int cnt;

    for(int i=0;i<lcp.size();i++){
      if(T[i] == patt[0]){
        if(lcp[i] != 0){
          cnt = pe;
        }
        else{
          cnt--;
          lcp[i] = cnt; 
        }
      }
      else lcp[i] = 0;
    }
    return lcp;
  }
};
