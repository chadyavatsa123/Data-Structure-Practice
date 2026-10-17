class Solution {
public:
    int minSwaps(vector<int>& nums) {
       vector<pair<int,int>>v;
       for(int i=0;i<nums.size();i++){
        int num=nums[i];
        int sum=0;
        while(num>0){
         sum+=num%10;
         num=num/10;
        }
        v.push_back({sum,nums[i]});
       } 
       sort(v.begin(),v.end());
       unordered_map<int,int>pos;
       for(int i=0;i<nums.size();i++){
        pos[nums[i]]=i;
       }
       int swaps=0;
       for(int i=0;i<nums.size();i++){
        int target=v[i].second;
        if(nums[i]==target)continue;
        int j=pos[target];
        int curr=nums[i];
        swap(nums[i],nums[j]);
        pos[target]=i;
        pos[curr]=j;
        swaps++;
       }
       return swaps;
    }
};