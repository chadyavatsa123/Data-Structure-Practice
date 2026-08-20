class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
      arr1.push_back(nums[0]);
      arr2.push_back(nums[1]);
      int i=2;
      while(i<nums.size()){
        if(arr1.back()>arr2.back())
        arr1.push_back(nums[i]);
        else 
        arr2.push_back(nums[i]);
        i++;
      }

        vector<int>merged;
        for(auto it:arr1)
        merged.push_back(it);
        for(auto it:arr2){
            merged.push_back(it);
        }
        return merged;
    }
};