class Solution {
public:
    bool helper(int n){
      if (n <= 1)
        return false;
      for (int i = 2; i * i <= n; i++)
        if (n % i == 0){
          return false;
        }
      return true;
    }
    vector<int> closestPrimes(int l, int r) {
      if(r - l < 1) return {-1, -1};
      vector<int> v;
      int p = -1, q = -1;
      for(int i = l; i <= r; i++){
        if(helper(i)){
          v.emplace_back(i);
        }
      }
      int dif = 0;
      if(v.size() > 1){
        p = v[0]; q = v[1];
        dif = v[1] - v[0];
        for(int i = 0; i < v.size() - 1; i++){
          if(dif > v[i + 1] - v[i]){
            dif = v[i + 1] - v[i];
            p = v[i]; q = v[i + 1];
          }
        }
      }
      return {p, q};
    }
};