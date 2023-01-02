class Solution {
public:
    int minimumPartition(string s, int k) {
      int l = 0, r = 0, ans = 0, n = s.size(), curr = 0;
      int lenk = 0;
      int temp = k;
      while(temp){
        temp /= 10;
        lenk++;
      }
      if(lenk == 1){
        for(char &i: s){
          if(i - '0' > k) return -1;
        }
        return n;
      }
      for(int i = 0; i < n; i++){
        string t = "", g =  to_string(k);
        int curr = 0;
        while(i < n and t.size() < g.size() and curr < k){
          curr = curr * 10 + s[i] - '0';
          t += s[i];
          i++;
        } 
        if(curr > k) i--;
        ans++; i--;
      }
      return ans > 0 ? ans : -1;
    }
};
