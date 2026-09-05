class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         vector<int>mini(nums.size());
        int mn=INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
           // mini[i]=min(mini[i],nums[i]);
         if(mn>nums[i]){
            mn=nums[i];
         }
         mini[i]=mn;
        }
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
          maxi=max(maxi,nums[i]);
          int diff=maxi-mini[i];
          if(diff<=k)return i;
        }
        return -1;
    }
};