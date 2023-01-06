class Solution {
public:
    int maxIceCream(vector<int>& v, int t) {
      sort(v.begin(), v.end());
      int ans = 0, i = 0;
      while(i < v.size() and t >= v[i]){
        t -= v[i]; i++; ans++;
      }
      return ans;
    }
};