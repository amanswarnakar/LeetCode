class DSU {
  vector<int> p, r;
public:
  DSU(int n) {
    p.resize(n);
    r.resize(n, 0);
    for(int i = 0; i < n; i++) p[i] = i;
  }
  int Find(int x){
    return p[x] = p[x] == x ? x : Find(p[x]);
  }
  bool Union(int x, int y){
    int xset = Find(x), yset = Find(y);
    if(xset == yset) return false;
    r[xset] < r[yset] ? p[xset] = yset : p[yset] = xset;
    r[xset] += r[xset] == r[yset];
    return true;
  }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
      DSU alice(n + 1), bob(n + 1);
      sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){ return a[0] > b[0]; });
      int a = 0, b = 0, extra = 0;
      for(auto &e: edges){
        if(e[0] == 3){
          if(alice.Union(e[1], e[2])){
            bob.Union(e[1], e[2]);
            a++; b++;
          } else {
            extra++;
          }
        } else if(e[0] == 1){
          if(alice.Union(e[1], e[2])) a++;
          else extra++;
        } else {
          if(bob.Union(e[1], e[2])) b++;
          else extra++;
        }
      }
      return (a == n - 1 and b == n - 1) ? extra : -1;
    }
};