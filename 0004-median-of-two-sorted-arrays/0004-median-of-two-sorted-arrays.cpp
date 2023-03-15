class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
      // Binary Search Approach
      int n1 = v1.size(), n2 = v2.size();
      if(n2 < n1) return findMedianSortedArrays(v2, v1);
      int l = 0, r = n1;
      while(l <= r){
        int c1 = l + (r - l) / 2;
        int c2 = (n1 + n2 + 1) / 2 - c1;
        
        int l1 = c1 == 0 ? INT_MIN : v1[c1 - 1];
        int l2 = c2 == 0 ? INT_MIN : v2[c2 - 1];
        int r1 = c1 == n1 ? INT_MAX : v1[c1];
        int r2 = c2 == n2 ? INT_MAX : v2[c2];

        if(l1 <= r2 and l2 <= r1){
          if((n1 + n2) % 2 == 1) return max(l1, l2);
          return (max(l1, l2) + min(r1, r2)) / 2.0;
        } else if(l1 > r2) {
          r = c1 - 1;
        } else {
          l = c1 + 1;
        }
      }
      return 0.0;
      
      
      // TC - O((n + m)log(n + m))   SC - O(n + m)
      
      // vector<int> v(v1.begin(), v1.end());
      // for(auto &i: v2) v.emplace_back(i);
      // sort(v.begin(), v.end());
      // int n = v.size();
      // if(n % 2)
      //   return double(v[n / 2]);
      // return double(v[n / 2 - 1] + v[n / 2]) / 2.0;
    }
};