class Solution {
public:
    int minOperations(vector<int>& a, int x) {
      int l = 0, r = 0;
      int ans = INT_MAX;
      int temp = 0, n = a.size();
      long long int sum = 0;
      for(auto i : a){
        sum += i;
      }
      int tar = sum - x;
      bool flag = false;
      while(r < n){
        temp += a[r];
        while(l <= r and temp > tar){
          temp -= a[l++];
        }
        if(temp == tar){
          flag = true;
          ans = min(ans, n - r + l - 1);
        }
        r++;
      }
      return flag ? ans : -1;
    }
};