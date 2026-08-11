class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int mxSum=0;
     
       set<int>st(nums.begin(),nums.end());
        int i=0;
     while(i<nums.size()){
        int sum=0;
        int curr=nums[i];
        sum+=curr;
        i++;
        while(st.find(curr+1)!=st.end() && nums[i]==curr+1  && i<nums.size()){
            curr=curr+1;
            sum+=curr;
            i++;
        }
        mxSum=max(mxSum,sum);  
        break;
     }
     
    while(st.find(mxSum)!=st.end())
    mxSum++;
     return mxSum;
    }
};