class Solution {
public:
    
      // Merge Sort Technique
    
    int merge(vector<int> &arr, int l, int mid, int r){
        int cnt = 0;
        int j = mid + 1;
        for(int i = l; i <= mid; i++){
          while(j <= r and arr[i] > 2ll * arr[j])
            j++;
          cnt += j - (mid + 1);       
        }
        
        // Merging
        vector<int> temp;
        int left = l, right = mid + 1;
        while(left <= mid and right <= r){
          if(arr[left] < arr[right])
            temp.push_back(arr[left++]);
          else 
            temp.push_back(arr[right++]);
        }
        while(left <= mid)
          temp.push_back(arr[left++]);
        while(right <= r)
          temp.push_back(arr[right++]);
      
        // Swapping the temp array with the original array
        for(int i = l; i <= r; i++){
          arr[i] = temp[i-l];
        }
        return cnt;
      }
      
      int mergeSort(vector<int> &arr, int l, int r){
        if(l >= r)  return 0;
        int mid = l + (r-l)/2;
        int inv = mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
        return inv;
      }
      
  int reversePairs(vector<int>& nums) {
  
    return mergeSort(nums, 0, nums.size()-1);
    
      // Brute Force
      
    //   int ans = 0, n = nums.size();
    //   for(int i = 0; i < n-1; i++){
    //     for(int j = i+1; j < n; j++){
    //       long long x = nums[i], y = nums[j];
    //       if(x > 2 * y)
    //         ans++;
    //     }
    //   }
    //   return ans;
      
      
      
    }
};