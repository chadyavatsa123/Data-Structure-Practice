class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*  unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
      
       vector<pair<int, int>> v(mp.begin(), mp.end());

        //  Sort based on frequency (descending)
        sort(v.begin(), v.end(), [](auto a, auto b) {
            return a.second > b.second;
        });
       
  vector<int>ans;
 
 for(auto it:v){
    ans.push_back(it.first);
    k--;
    if(k==0)break;
 }
 return ans;*/
 unordered_map<int,int>mpp;
 for(auto it:nums){
    mpp[it]++;
 }
 vector <int>ans;
 while(k>0){
    int mx=INT_MIN;
    int freq=-1;
    for(auto it:mpp){
        if(it.second>freq){
            freq=it.second;
            mx=it.first;
        }
    }
    ans.push_back(mx);
    mpp.erase(mx);
    k--;

 }
 return ans;
  
    }
};