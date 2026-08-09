class Solution {
public:
    long long findheight(int node,vector<int>adj[]){
        long long height=0;
        for(auto it:adj[node]){
            height=max(height,findheight(it,adj));
        }
        return 1+height;
    }
    void depth(int node,int d,vector<int>adj[],vector<int>&depths){
        depths[node]=d;
        for(auto it:adj[node]){
            depth(it,d+1,adj,depths);
        }
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        long long n=parent.size();
        vector<int>adj[n];
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
       long long h= findheight(0,adj);
       vector<int>depths(n);
       depth(0,1,adj,depths);
       long long sum=0;
       for(int i=0;i<n;i++){
        sum+=nums[i]*(h-depths[i]+1);
       }
       return sum;
    }
};