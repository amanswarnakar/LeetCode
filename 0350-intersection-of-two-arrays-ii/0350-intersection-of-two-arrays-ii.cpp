class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      vector<int> ans;
      unordered_map<int, int> um;
      for(auto &i: nums1){
        um[i]++;
      }
      for(auto &i: nums2){
        if(um.find(i) != um.end() and um[i] > 0){
          ans.emplace_back(i);
          um[i]--; 
        }
      }
      return ans;
    }
};