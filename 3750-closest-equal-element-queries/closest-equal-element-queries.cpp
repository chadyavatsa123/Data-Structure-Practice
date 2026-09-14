class Solution {
public: 
    int upperbound(int num,vector<int>&temp){
        if(num==temp.back()){
        int nxt=temp[0];
        return nxt;
        }
        int l=0;
        int r=temp.size()-1;
        int nxt=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(temp[mid]<=num)
            l=mid+1;
            else{
              nxt=temp[mid];
              r=mid-1;
            }

        }
        return nxt;
    }
    int lowerbound(int num,vector<int>&temp){
        if(num==temp[0])
        return temp.back();
        int l=0;
        int r=temp.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(temp[mid]<num){
              ans=temp[mid];
              l=mid+1;
            }
            else
            r=mid-1;
        }
        return ans;
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        vector<int>res;
        for(int i=0;i<queries.size();i++){
            int n=nums[queries[i]];
            vector<int>&temp=mpp[n];
            if(temp.size()==1){
            res.push_back(-1);
            continue;
            }
           int nxt=abs(queries[i]-upperbound(queries[i],temp));
           int prev=abs(queries[i]-lowerbound(queries[i],temp));
           nxt=min(nxt,(int)(nums.size()-nxt));
           prev=min(prev,(int)(nums.size()-prev));
           res.push_back(min(nxt,prev));
           

        }
        return res;
    }
};