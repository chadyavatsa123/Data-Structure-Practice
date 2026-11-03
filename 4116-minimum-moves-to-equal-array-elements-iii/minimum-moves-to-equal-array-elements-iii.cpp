class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size()-1;i++){
            sum+=nums[nums.size()-1]-nums[i];
        }
        return sum;
    }
};