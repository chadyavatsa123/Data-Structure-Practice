class Solution {
public:
int func(vector<int>&temp){
    int first=temp[0];
    int second=0;
    for(int i=1;i<temp.size();i++){
        int take=temp[i];
        if(i>1)
        take+=second;
        int nottake=0+first;
        int curr=max(take,nottake);
        second=first;
        first=curr;
    }
    return first;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0)
            temp1.push_back(nums[i]);
            if(i!=n-1)
            temp2.push_back(nums[i]);
        }
        return max(func(temp1),func(temp2));

    }
};