class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(x<0)return -1;
        if(x==0)return nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum<x)return -1;
        int s1=sum-x;
        if(s1==0)return nums.size();
        int l=0;
        int s2=0;
        int mxlen=INT_MIN;
        for(int r=0;r<nums.size();r++){
         s2+=nums[r];
         while(s2>s1 && l<=r){
           s2-=nums[l];
           l++;
         }
         if(s2==s1)
         mxlen=max(mxlen,r-l+1);

        }
        if(mxlen==INT_MIN)return -1;
        return nums.size()-mxlen;
    }
};