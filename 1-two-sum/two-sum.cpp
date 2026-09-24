class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]=i;
       }
       int i=0; 
      while(i<nums.size()){
        int num=target-nums[i];
       
       if(mp.find(num)!=mp.end() && mp[num]!=i){
        int index=mp[num];
        return {i,index};
       }
        i++;
      }
      return {-1,-1};
    }
};