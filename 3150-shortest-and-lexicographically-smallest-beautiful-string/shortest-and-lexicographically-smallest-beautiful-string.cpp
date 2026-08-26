class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0;
        int r=0;
        int sum=0;
        vector<pair<int,string>>res;
        while(r<s.size()){
           if(s[r]=='1')
           sum++;
          
           while(sum>k){
            sum=sum-(s[l]-'0');
            l++;
           }
            while(s[l]=='0'){
            l++;
           }
           if(sum==k){
           int len=r-l+1;
            string t="";
            for(int i=l;i<=r;i++){
             t+=s[i]; 
            }
            res.push_back({len,t});
           }
           r++;
        }
        int mn=INT_MAX;
        string ans="";
        for(auto it:res){
            if(mn>it.first){
                mn=it.first;
                ans=it.second;
            }
            else if(mn==it.first && ans>it.second){
                ans=it.second;
            }
            
        }
        return ans;

    }
};