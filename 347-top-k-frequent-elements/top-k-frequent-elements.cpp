class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
          unordered_map<int,int>mp;
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
 return ans;
  
    }
};