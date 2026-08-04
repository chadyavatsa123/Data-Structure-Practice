class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,bool>mpp;
        for(auto &it :nums){
            mpp[it]=true;
        }
        vector<int>ans;
       int i=0;
       while(i<nums.size()){
            int curr=nums[i];
            i++;
            while(mpp.find(curr+1)!=mpp.end() && i<nums.size()){
                curr=curr+1;
                i++;
            }
            if(mpp.find(curr+1)==mpp.end() && i<nums.size()){
                while(mpp.find(curr+1)==mpp.end()){
               ans.push_back(curr+1);
               curr=curr+1;
                }
            }
        }
        return ans;
    }
};