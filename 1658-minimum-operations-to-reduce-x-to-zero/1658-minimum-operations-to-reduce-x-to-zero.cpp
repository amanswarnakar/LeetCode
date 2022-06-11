class Solution {
public:
    int minOperations(vector<int>& a, int x) {
      int l = 0;
      int ans = 0, maxLen = 0;
      int temp = 0, n = a.size();
      long long int sum = 0;
      for(auto i : a){
        sum += i;
      }
      int tar = sum - x;
      bool flag = false;
      for(int r = 0; r < n; r++){
        temp += a[r];
        while(l <= r and temp > tar){
          temp -= a[l++];
        }
        if(temp == tar){
          flag = true;
          maxLen = max(maxLen, r - l + 1);
        }
      }
      return flag ? n - maxLen : -1;
    }
};