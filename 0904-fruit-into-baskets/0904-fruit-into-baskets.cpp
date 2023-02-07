class Solution {
public:
    int totalFruit(vector<int>& v) {
      int l = 0, r = 0, n = v.size();
      unordered_map<int, int> um;
      int ans = 0;
      while(r < n){
        um[v[r++]]++;
        while(um.size() > 2){
          um[v[l]]--;
          if(um[v[l]] == 0) um.erase(v[l]);
          l++;
        }
        ans = max(ans, r - l);
      }
      return ans;
      
      // int l = 0, r = 0, n = v.size();
      // unordered_map<int, int> um;
      // while(r < n){
      //   um[v[r++]]++;
      //   if(um.size() > 2){
      //     um[v[l]]--;
      //     if(um[v[l]] == 0) um.erase(v[l]);
      //     l++;
      //   }
      // }
      // return r - l;
      
      // TC - O(N^2) TLE
      
//       int n = v.size(), ans = 0, j;
//       for(int i = 0; i < n; i++){
//         unordered_set<int> st;
//         for(j = i; j < n; j++){
//           if(st.find(v[j]) == st.end() and st.size() == 2)
//             break;
//           st.insert(v[j]);
//         }
//         ans = max(ans, j - i);
//       }
//       return ans;
      
      // Brute Force TC - O(N^3) - TLE
      
      // int n = v.size(), ans = 0, i, j;
      // for(i = 0; i < n; i++){
      //   for(j = 0; j < n; j++){
      //     unordered_set<int> st;
      //     for(int k = i; k <= j; k++)
      //       st.insert(v[k]);
      //     if(st.size() <= 2) ans = max(ans, j - i + 1);
      //   }
      // }
      // return ans;
    }
};