class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
       // set<int>st;
        int l=0;
        int r=0;
        int mx=0;
        vector<vector<int>>res(nums.size());
        int cnt=0;
        unordered_map<int,int>mp;
        while(r<nums.size()){
         int x=nums[r];
        for(int i=2;i*i<=x;i++){
            
            if(x %i==0){
             res[r].push_back(i);
             while(x %i==0)
             x/=i;
            }
        }
        if(x>1)
        res[r].push_back(x);
      
            for(auto it:res[r]){
                if(mp[it]==0)
                cnt++;
                mp[it]++;
            }
            while(cnt>k){
                for(auto it:res[l]){
                    mp[it]--;
                    
                    if(mp[it]==0){
                        cnt--;
                    }
                }
                l++;
            }
            mx=max(mx,r-l+1);
            r++;
        
        }
        return mx;   
    }
};