class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>0;i--){
            sum+=nums[i]-nums[0];
        }
        return sum;
    }
};