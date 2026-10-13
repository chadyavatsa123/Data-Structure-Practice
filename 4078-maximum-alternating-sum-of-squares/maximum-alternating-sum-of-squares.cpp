class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>res(nums.size());
        priority_queue<int>pq;
        for(auto it:nums){
            int val=abs(it);
            pq.push(val);
        }
        int i=0;
       while(!pq.empty() && i<nums.size()){
       // int num=pq.top();
       // pq.pop();
        if(i%2==0){
        int num=pq.top();
        pq.pop();
        res[i]=num;
        
        }
        i=i+2;
       }
       int j=1;
      while(!pq.empty() && j<nums.size()){
         int num=pq.top();
         pq.pop();
         res[j]=num;
         j=j+2;
      }
       long long score=0;
       for(int i=0;i<res.size();i++){
        if(i%2==0){
        int val=1ll*res[i]*res[i];
        score+=val;
        }
        else{
        int val=1ll*res[i]*res[i];
        score-=val;
        }
       }
       return score;
    }
};