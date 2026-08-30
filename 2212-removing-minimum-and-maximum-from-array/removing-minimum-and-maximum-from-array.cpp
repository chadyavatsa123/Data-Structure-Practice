class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1)
        return 1;
        int mn=INT_MAX;
        int mx=INT_MIN;
        int maxind=-1;
        int minind=-1;
       for(int i=0;i<nums.size();i++){
        if(nums[i]>mx){
            mx=nums[i];
            maxind=i;
        }
        if(nums[i]<mn){
            mn=nums[i];
            minind=i;
        }
       }
       //left part
      int left= max(minind,maxind)+1;
      //right
      int right=max(n-minind,n-maxind);
      //mini will be taken from where it will be nearest
      int mini=min(minind+1,n-minind);
      //maxi will be taken form where it will be nearest
      int maxi=min(maxind+1,n-maxind);
      
      return min(left,min(right,(mini+maxi)));
    }
};