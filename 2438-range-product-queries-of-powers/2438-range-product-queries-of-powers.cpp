class Solution {
public:
    vector<int> genArr(int n){
      vector<int> ans;
      while(n){
        int x = int(log2(n));
        n -= pow(2, x);
        ans.push_back(x);
      }
      return ans;
    }
    long long mod = 1000000007;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
      vector<int> v = genArr(n), ans;
      sort(v.begin(), v.end());
      for(vector<int> &p: queries){
        int l = p[0], r = p[1];
        int temp = 1;
        for(int i = l; i <= r; i++){
          temp = long(temp * pow(2, v[i])) % mod;
        }
        ans.push_back(temp);
      }
      return ans;
    }
};